program ex;
var  a,b,d,e,m,n,i,j,z,q,k,max1,x:longint;
f:array[-100..2000,-100..2000] of integer;
function max(d,e:longint):longint;
begin
if d>e then max:=d
else max:=e;
end;
begin
assign(input,'pack.in');
reset(input);
assign(output,'pack.out');
rewrite(output);
read(n,m);
if m=0 then writeln('0') else
begin
for i:=1 to n do
read(x,a,b);
if q<>0 then read(q);
for j:=1 to m do
if j>z then
begin
if x=1 then f[i,j]:=max(f[i,j],f[i-1,j-b]+a*(sqr(x))-b*x);
if x=2 then f[i,j]:=max(f[i,j],f[i-q,j-q*b]+q*a);
if x=3 then  for k:=1 to n do
 f[i,j]:= max(f[i,j],f[i-k,j-k*b]+k*a);
 end;
end;
writeln(f[n,m]);
close(input);
close(output);
end.

