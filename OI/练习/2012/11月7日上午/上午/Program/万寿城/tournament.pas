program ex;
var  n,k,x,y,i,j:longint;
b:array[1..2] of integer;
a,c:array[1..100] of integer;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
read(n);
for i:=1 to n do
begin
a[i]:=1;
c[i]:=n-1;
end;
for j:=1 to (n*(n-1)div 2)-1 do
begin
read(x,y);
a[y]:=a[x]+1;
c[x]:=c[x]-1;
c[y]:=c[y]-1;
end;
for i:=1 to n do
if c[i]<>0 then begin
k:=k+1;
b[k]:=i;
end;
if a[b[1]]<a[b[2]] then writeln(b[1],' ',b[2])
else writeln(b[2],' ',b[1]);
close(input);
close(output);
end.
