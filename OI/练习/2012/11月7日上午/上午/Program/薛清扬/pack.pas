var n,v,i,j,k:longint;
c,w,a,b,f:array[-10000..10000]of longint;
function max(x,y:longint):longint;
begin
if x>y then max:=x else max:=y;
end;
procedure try1(x,y:longint);
var i:longint;
begin
    for i:=v downto x do
        f[i]:=max(f[i],f[i-x]+y);
end;
procedure try4(x,y,z:longint);
var j:longint;
begin
    for j:=z to v do
        f[j]:=max(f[j],f[j-z]+y*z*z-x*z);
end;
procedure try2(x,y:longint);
var j:longint;
begin
    for j:=x to v do
        f[j]:=max(f[j],f[j-x]+y);
end;
procedure try3(x,y,z:longint);
begin
if x*z>=v then
begin
try2(x,y);
        exit;
end;
k:=1;
while k<z do
begin
try1(k*x,k*y);
        z:=z-k;
        k:=k*2;
try1(z*x,z*y);
end;
end;
begin
assign(input,'pack.in');
assign(output,'pack.out');
reset(input);
rewrite(output);
readln(n,v);
for i:=1 to n do
begin
read(b[i]);
if (b[i]=3)or(b[i]=1) then readln(c[i],w[i]);
if b[i]=2 then readln(c[i],w[i],a[i]);
end;
for i:=1 to n do
begin
if b[i]=3 then try2(w[i],c[i]);
if b[i]=2 then try3(w[i],c[i],a[i]);
if b[i]=1 then for j:=1 to v do try4(w[i],c[i],j);
end;
writeln(f[v]);
close(input);
close(output);
end.
