const ba=1000000007;
type cw=array[1..2,1..2] of int64;
var n,i:longint;
    f:array[1..2] of longint;
    a:cw;
    ans:int64;
function chen(a,b:cw):cw;
var i,j,k:longint;
begin
 fillchar(chen,sizeof(chen),0);
 for i:=1 to 2 do
  for j:=1 to 2 do
   for k:=1 to 2 do
    chen[i][j]:=(chen[i][j]+a[i][k]*b[k][j]) mod ba;
end;

function e(n:longint):cw;
var b:cw;
begin
 if n=1 then exit(a);
 b:=e(n div 2);
 b:=chen(b,b);
 if n mod 2=1 then b:=chen(b,a);
 exit(b);
end;

begin
 read(n);
 a[1][1]:=0;
 a[1][2]:=4;
 a[2][1]:=1;
 a[2][2]:=1;
 if n<>1 then a:=e(n-1);
 f[1]:=1;
 f[2]:=5;
 if n<>1 then begin
  ans:=(f[1]*a[1][1]+f[2]*a[2][1]) mod ba;
  writeln(ans)
 end
 else writeln(1);
end.
