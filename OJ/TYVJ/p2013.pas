var a,b:array[1..100000] of longint;
    f:array[0..1,1..100000] of longint;
    n,i,j:longint;
begin
 read(n);
 for i:=1 to n do
  read(a[i]);

 for i:=1 to n do
  read(b[i]);

 for i:=n downto 1 do
  for j:=i+1 to n do begin
   if a[i]*b[j]+f[0][j]>f[1][i] then f[1][i]:=a[i]*b[j]+f[0][j];
   if f[1][j]>f[0][i] then f[0][i]:=f[1][j];
  end;

 if f[0][1]>f[1][1] then writeln(f[0][1])
                    else writeln(f[1][1]);
end.
