var f:array[1..1000] of longint;
    n,i,j:longint;
begin
 read(n);
 for i:=1 to n div 2 do
  begin
  for j:=1 to i div 2 do
   inc(f[i],f[j]);
  inc(f[i]);
 end;

 for j:=1 to n div 2 do
  inc(f[n],f[j]);
 inc(f[n]);
 writeln(f[n]);
end.
