var a:array[1..40] of extended;
    f:array[1..40,1..40,1..40] of extended;
    n,m,x,z,y,k,i,j:longint;
    ans,c:extended;
function max(a,b:extended):extended;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'scope.in');reset(input);
 assign(output,'scope.out');rewrite(output);
 read(n,m);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do f[i][i][1]:=0;
 for i:=1 to n-1 do
  for j:=i+1 to n do f[i][j][2]:=sin((a[j]-a[i])*2*pi)/2;
 for z:=3 to m do
  for x:=1 to n-z+1 do
   for y:=x+z-1 to n do
     for k:=x+z-2 to y-1 do begin
      c:=sin((a[y]-a[k])*2*pi)/2;
      f[x][y][z]:=max(f[x][y][z],f[x][k][z-1]+c);
     end;

 ans:=0;
 for i:=1 to n-m+1 do
  for j:=i+m-1 to n do
   ans:=max(ans,f[i,j,m]+sin(2*pi-(a[j]-a[i])*2*pi)/2);
 writeln(ans:0:6);
 close(input);close(output);
end.
