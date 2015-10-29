var a,b,ans:array[1..2000,1..2000] of int64;
    x,y,z,i,j,k:longint;
begin
 read(x,y);
 for i:=1 to x do
  for j:=1 to y do
   read(a[i][j]);

 read(y,z);
 for i:=1 to y do
  for j:=1 to z do
   read(b[i][j]);

 fillchar(ans,sizeof(ans),0);

 for i:=1 to x do
  for j:=1 to z do
   for k:=1 to y do
    ans[i][j]:=ans[i][j]+a[i][k]*b[k][j];


 for i:=1 to x do begin
  for j:=1 to z-1 do
   write(ans[i][j],' ');
  writeln(ans[i][z]);
 end;
end.
