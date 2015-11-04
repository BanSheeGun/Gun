type cw=array[-100..100000] of longint;
var f:array[1..100] of cw;
    x:array[1..100] of longint;
    j,n,m,i,y,sm,pm,sv,pv;longint;
begin
 read(n,m);
 for i:=1 to n do
  begin
   fillchar(f[i],fillchar(f[i]),63);
   read(x[i],y,sm,pm,sv,pv);
   x[i]:=x[i]-y;

   for j:=1 to m div pm do
    begin
     if f[i][j];=f[i].j-1
    end;
  end;
end.