var w:array[1..300] of longint;
    f,d:array[0..300,0..300] of longint;
    k,n,m,i,j:longint;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
begin
 read(n,m);
 for i:=1 to n do
  read(w[i]);

 fillchar(d,sizeof(d),0);
 for i:=1 to n do
  for j:=i to n do
   for k:=i to j do
   d[i][j]:=d[i][j]+abs(w[k]-w[(i+j)div 2]);

 fillchar(f,sizeof(f),63);
 for i:=1 to n do
  f[i][1]:=d[1,i];
 for k:=1 to m do
  for i:=k to n do
   for j:=k-1 to i-1 do
   begin
    f[i][k]:=min(f[i][k],f[j][k-1]+d[j+1][i]);
   end;

 writeln(f[n][m]);
end.
