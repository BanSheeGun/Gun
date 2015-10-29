var a,b,c:array[1..500,1..500] of longint;
    d,r,e,f:array[1..500,1..1] of longint;
    n,i,j,k:longint;
function check:boolean;
begin
 for i:=1 to n do
  if e[i][1]<>f[i][1] then exit(false);
 exit(true);
end;

begin
 read(n);
 for i:=1 to n do
  for j:=1 to n do
   read(a[i][j]);
 for i:=1 to n do
  for j:=1 to n do
   read(b[i][j]);
 for i:=1 to n do
  for j:=1 to n do
   read(c[i][j]);

 randomize;
 for i:=1 to n do r[i][1]:=random(2*n)+1;
 fillchar(d,sizeof(d),0);
 for i:=1 to n do
  for j:=1 to n do
   for k:=1 to 1 do
    d[i][k]:=d[i][k]+b[i][j]*r[j][k];


 for i:=1 to n do
  for j:=1 to n do
   for k:=1 to 1 do
    e[i][k]:=e[i][k]+a[i][j]*d[j][k];


 for i:=1 to n do
  for j:=1 to n do
   for k:=1 to 1 do
    f[i][k]:=f[i][k]+c[i][j]*r[j][k];

 if check then writeln('YES')
          else writeln('NO');
end.
