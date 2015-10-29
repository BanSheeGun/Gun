var f:array[0..500] of longint;
    a:array[1..15] of longint;
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
 assign(input,'hallows.in');reset(input);
 assign(output,'hallows.out');rewrite(output);
 read(n,vs);
 for i:=1 to n do begin
  read(m,v,w);
  cf(m);
  for j:=1 to top do begin
   v1:=v*a[j];w1:=w*a[j];
   for k:=vs downto v1 do
    if f[k]<f[k-v1]+w1 then f[k]:=f[k-v1]+w1;
  end;
 end;
 writeln(f[vs]);
 close(input);close(output);
end.
