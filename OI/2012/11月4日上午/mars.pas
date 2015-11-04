var a:array[1..1000,1..1000] of longint;
    k,n,i,j:longint;
begin
 assign(input,'mars.in');reset(input);
 assign(output,'mars.out');rewrite(output);
 read(k);
 n:=1;
 for i:=1 to k do n:=n*2;


 for i:=1 to n do
  for j:=1 to n do
   read(a[i][j]);

 for k:=1 to n do
  for i:=1 to n do
  if k<>i then
   for j:=1 to n do
    if (i<>j)and(k<>j) then
    if a[i][k]+a[k][j]>a[i][j] then a[i][k]:=a[i][j]+a[j][k];

  for i:=1 to  n do
   for j:=1 to n do
    if  a[i][j]>k then k:=a[i][j];
   writeln(k);
 close(input);close(output);
end.
