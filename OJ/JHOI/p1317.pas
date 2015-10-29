var n,m,v,c,i,j:longint;
    f:array[0..30000] of longint;
begin
 fillchar(f,sizeof(f),0);
 read(n,m);
 for i:=1 to m do
  begin
   read(v,c);
   for j:=n downto v do
    if f[j]<f[j-v]+v*c
     then f[j]:=f[j-v]+v*c;
  end;
 writeln(f[n]);
end.
