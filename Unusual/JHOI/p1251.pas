var w:array[1..300] of longint;
    f,d,f1:array[0..300,0..300] of longint;
    k,n,m,i,j:longint;

procedure pr(x,y:longint);
begin
 if y<>1 then pr(f1[x][y]-1,y-1);
 if y=1 then write(w[(x+y)div 2],' ')
 else
 write(w[(x+f1[x][y]) div 2],' ');
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
  begin
  f[i][1]:=d[1,i];
  f1[i][1]:=(i) div 2;
  end;
 for k:=1 to m do
  for i:=k to n do
   for j:=k-1 to i-1 do
   begin
    if f[i][k]>f[j][k-1]+d[j+1][i]
     then begin
           f[i][k]:=f[j][k-1]+d[j+1][i];
           f1[i][k]:=j+1;
          end;
   end;

 writeln(f[n][m]);
 pr(n,m);
 writeln;
end.
