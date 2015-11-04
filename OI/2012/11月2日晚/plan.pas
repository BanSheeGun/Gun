var f:array[0..200001] of longint;
    a:array[1..10] of longint;
    n,vs,m,v,w,top,i,j,k,v1,w1:longint;
procedure cf(n:longint);
var sum,k:longint;
begin
 sum:=n;
 top:=0;
 k:=1;
 while k<sum do begin
  inc(top);
  a[top]:=k;
  sum:=sum-k;
  k:=k*2;
 end;
 inc(top);
 a[top]:=sum;
end;
begin
 assign(input,'plan.in');reset(input);
 assign(output,'plan.out');rewrite(output);
 read(n,vs);
 fillchar(f,sizeof(f),63);
 f[0]:=0;
 for i:=1 to n do begin
  read(w,m,v);
  cf(m);
  for j:=1 to top do begin
   v1:=v*a[j];w1:=w*a[j];
   for k:=vs downto 0 do begin
     if k+v1>200000 then break;
    if f[k+v1]>f[k]+w1 then f[k+v1]:=f[k]+w1;
  end;
  end;
 end;
 for i:=vs+1 to 200000 do
  if f[i]<>f[200001] then break;
 writeln(i,' ',f[i]);
 close(input);close(output);
end.
