var a:array[1..50,1..5] of int64;
    n,m,i,j:longint;
    ans:int64;
function f(x,y:longint):int64;
var i,j:longint;
begin
 if y>x then exit(0);
 if a[x][y]<>0 then exit(a[x][y]);
 if x=1 then
  begin
   a[x][y]:=1;
   exit(1);
  end;
 if y<>1 then a[x][y]:=f(x-1,y-1)
         else
 begin
  a[x][y]:=1;
  for i:=1 to x-2 do
   for j:=1 to m-1 do
    inc(a[x][y],f(i,j));
 end;
 exit(a[x][y]);
end;
begin
 fillchar(a,sizeof(a),0);
 read(n,m);

 for i:=n downto 1 do
  for j:=1 to m-1 do
 inc(ans,f(i,j));

 writeln(ans+1);
end.
