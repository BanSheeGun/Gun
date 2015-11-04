var f:array[0..8000] of longint;
    d,b,c:array[1..3] of longint;
    a:array[1..20] of longint;
    n,m,i,j,v,kk,k,z,top,v1,w1:longint;
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
function get(var z:longint):longint;
var i:longint;
begin
 for i:=1 to 3 do
  if z=d[i] then exit(i);
end;
begin
 assign(input,'embro.in');reset(input);
 assign(output,'embro.out');rewrite(output);
 read(n,m);
 for i:=1 to 3 do read(d[i],b[i],c[i]);

 for i:=1 to n do begin
  read(v,kk);
  z:=get(kk);
  cf(v);

  for j:=1 to top do begin
   for k:=m downto 1 do begin
    v1:=a[j]*c[z];w1:=b[z]*a[j];
    if k-v1-v>=0 then
    if f[k]<f[k-v-v1]+w1 then f[k]:=f[k-v-v1]+w1;
   end;
  end;
 end;
 writeln(f[m]);
 close(input);close(output);
end.
