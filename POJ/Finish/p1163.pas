var a,f:array[1..101,1..101] of longint;
    n,i,j:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 read(n);
 for i:=1 to n do
  for j:=1 to i do
   read(a[i][j]);
 for i:=n downto 1 do
  for j:=1 to i do
   f[i][j]:=a[i][j]+max(f[i+1][j],f[i+1][j+1]);
 writeln(f[1][1]);
end.
