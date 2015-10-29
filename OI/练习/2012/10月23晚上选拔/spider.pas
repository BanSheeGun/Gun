var a:array[1..100,1..100] of longint;
    b,i,j,k,x,y,z,x1,x2,a1,a2,n:longint;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
begin
 assign(input,'spider.in');reset(input);
 assign(output,'spider.out');rewrite(output);
 readln(n);
 fillchar(a,sizeof(a),63);
 while not eof do begin
  readln(x,y,z);
  a[x][y]:=z;
  a[y][x]:=z;
 end;

 for i:=1 to n do a[i][i]:=0;
 for k:=1 to n do
  for i:=1 to n do
   if i<>k then
   for j:=1 to n do
    if a[i][j]>a[i][k]+a[k][j] then a[i][j]:=a[i][k]+a[k][j];

 y:=maxlongint;
 for x1:=1 to n do
  for x2:=x1+1 to n do
  begin
   x:=0;
   for i:=1 to n do begin
    z:=min(a[x1][i],a[x2][i]);
    if z>x then x:=z;
   end;
   if x<y then begin y:=x;a1:=x1;a2:=x2; end;
  end;
 writeln(a1,' ',a2);
 close(input);close(output);
end.
