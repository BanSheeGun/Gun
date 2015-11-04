var w:array[1..1000] of longint;
    g,f:array[1..1000,1..1000] of longint;
    n,i,j,k,min:longint;
begin
 assign(input,'dtest1.in');reset(input);
 assign(output,'dtest1.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(w[i]);

 fillchar(g,sizeof(g),0);
 for i:=1 to n do
  g[i][i]:=w[i];
 for i:=1 to n do
  for j:=i+1 to n do
   g[i][j]:=g[i][j-1]+w[j];

 fillchar(f,sizeof(f),0);
 for k:=1 to n-1 do
  for i:=1 to n do
   begin
    min:=maxlongint;
    for j:=i to i+k-1 do
     if f[i][j]+f[j+1][i+k]<min then
       min:=f[i][j]+f[j+1][i+k];
    f[i][i+k]:=min+g[i][i+k];
   end;
 writeln(f[1][n]);
 close(input);close(output);
end.
