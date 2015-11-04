var f,a:array[0..501,0..501] of longint;
    n,m,i,j,ans:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function ff(x,y:longint):longint;
begin
 if f[x][y]<>0 then exit(f[x][y]);
 f[x][y]:=1;
 if a[x-1][y]<a[x][y] then f[x][y]:=max(f[x][y],ff(x-1,y)+1);
 if a[x+1][y]<a[x][y] then f[x][y]:=max(f[x][y],ff(x+1,y)+1);
 if a[x][y-1]<a[x][y] then f[x][y]:=max(f[x][y],ff(x,y-1)+1);
 if a[x][y+1]<a[x][y] then f[x][y]:=max(f[x][y],ff(x,y+1)+1);
 exit(f[x][y]);
end;
begin
 fillchar(a,sizeof(a),63);
 fillchar(f,sizeof(f),0);

 read(n,m);
 for i:=1 to n do
  for j:=1 to m do
   read(a[i][j]);

 ans:=0;
 for i:=1 to n do
  for j:=1 to m do
   if ff(i,j)>ans then ans:=f[i][j];

 writeln(ans);
end.
