var ans,v,w:array[0..2000] of int64;
    cf,vv,ww:array[1..100] of int64;
    i,k,top,n,m,q,a,b,c,j:longint;

procedure work1(a,b:longint);
var ss,tt:longint;
begin
 for i:=1 to m do begin
  w[i]:=i;
  v[i]:=a*i*i-b*i;
 end;

 for k:=1 to m do
 for i:=m downto w[k] do
  if ans[i]<ans[i-w[k]]+v[k] then  ans[i]:=ans[i-w[k]]+v[k];
end;

procedure work2(v,w,s:longint);
var ss,tt:longint;
begin
 ss:=s;
 top:=0;tt:=1;
 while ss>=tt do begin
  inc(top);
  cf[top]:=tt;
  vv[top]:=v*cf[top];
  ww[top]:=w*cf[top];
  ss:=ss-tt;
  tt:=tt*2;
 end;
 if ss<>0 then begin
  inc(top);
  cf[top]:=ss;
  vv[top]:=v*cf[top];
  ww[top]:=w*cf[top];
 end;

 for k:=1 to top do
 for i:=m downto ww[k] do
  if ans[i]<ans[i-ww[k]]+vv[k] then  ans[i]:=ans[i-ww[k]]+vv[k];
end;

begin
 assign(input,'pack.in');reset(input);
 assign(output,'pack.out');rewrite(output);
 fillchar(ans,sizeof(ans),0);
 read(n,m);
 for j:=1 to n do begin
  read(q);
  case q of
   1:begin
    read(a,b);
    work1(a,b);
   end;
   2:begin
    read(a,b,c);
    work2(a,b,c);
   end;
   3:begin
    read(a,b);
    work2(a,b,m div b+1);
   end;
  end;
 end;
 writeln(ans[m]);
 close(input);close(output);
end.
