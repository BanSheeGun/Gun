var w,head,e,next:array[1..60000] of longint;
    f:array[0..1,1..60000] of longint;
    t:array[1..6000] of boolean;
    x,y,k,n,i,ans,fa:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function d(jy,tt:longint):longint;
var k:longint;
begin
 if f[jy][tt]<>0 then exit(f[jy][tt]);
 case jy of
  0:begin
   k:=head[tt];
   while k<>0 do begin
    f[jy][tt]:=f[jy][tt]+max(d(0,e[k]),d(1,e[k]));
    k:=next[k];
   end;
  end;
  1:begin
   k:=head[tt];
   while k<>0 do begin
    f[jy][tt]:=f[jy][tt]+d(0,e[k]);
    k:=next[k];
   end;
   f[jy][tt]:=f[jy][tt]+w[tt];
  end;
 end;
 exit(f[jy][tt]);
end;
begin
 assign(input,'anniversary.in');reset(input);
 assign(output,'anniversary.out');rewrite(output);
 read(n);
 fillchar(t,sizeof(t),true);
 for i:=1 to n do
  read(w[i]);
 i:=0;
 read(y,x);
 while (y<>0)and(x<>0) do begin
  t[y]:=false;
  inc(i);
  e[i]:=y;
  next[i]:=head[x];
  head[x]:=i;
  read(y,x);
 end;
 for i:=1 to n do
  if t[i] then fa:=i;
 for i:=1 to n do begin
  k:=d(0,i);
  ans:=max(ans,k);
  k:=d(1,i);
  ans:=max(ans,k);
 end;

 writeln(d(1,fa));
 close(input);close(output);
end.
