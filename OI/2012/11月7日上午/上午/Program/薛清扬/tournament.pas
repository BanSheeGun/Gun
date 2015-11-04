var n,i,j,k,c,d:longint;
a:array[0..100,0..100]of longint;
b:array[1..2]of longint;
h:array[1..100]of longint;
begin
assign(input,'tournament.in');
assign(output,'tournament.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to (n*(n-1) div 2)-1 do
begin
readln(c,d);
a[c,d]:=1;
a[d,c]:=-1;
inc(h[c]);
inc(h[d]);
end;
for i:=1 to n do
for j:=1 to n do
if i<>j then
begin
for k:=1 to n do
if (k<>i)and(k<>j)and(a[i,j]*a[j,k]>0) then
begin
if a[i,j]>0 then begin if a[i,j]+a[j,k]>a[i,k] then begin a[i,k]:=a[i,j]+a[j,k];a[k,i]:=-(a[i,j]+a[j,k]);end;
end
else if a[i,j]+a[j,k]<a[i,k] then begin a[i,k]:=a[i,j]+a[j,k];a[k,i]:=-(a[i,j]+a[j,k]);end;
end;
end;
j:=1;
for i:=1 to n do
if h[i]=n-2 then begin b[j]:=i;inc(j);end;
if a[b[1],b[2]]>=0 then writeln(b[1],' ',b[2]) else writeln(b[2],' ',b[1]);
close(input);
close(output);
end.
