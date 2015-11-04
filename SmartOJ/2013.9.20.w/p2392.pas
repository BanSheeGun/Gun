var a:array[1..10000] of int64;
    i,m,n,j:longint;
begin
 read(m,n);
 for i:=1 to m+1 do a[i]:=1;
 for i:=2 to n+1 do
  for j:=2 to m+1 do
  a[j]:=a[j]+a[j-1];
 writeln(a[m+1]);
end.
