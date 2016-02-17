var f:array[0..400,0..400] of longint;
    i,j,k,mv,mm,n,v,m,w:longint;
begin
 read(mv,mm);
 read(n);
 for i:=1 to n do begin
  read(v,m,w);
  for j:=mv downto v do
   for k:=mm downto m do
    if f[j][k]<f[j-v][k-m]+w then f[j][k]:=f[j-v][k-m]+w;
 end;

 writeln(f[mv][mm]);
end.
