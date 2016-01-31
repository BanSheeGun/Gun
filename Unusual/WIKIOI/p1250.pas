type cw=array[1..2,1..2] of longint;
var bb:cw=((0,1),(1,1));
    a:array[1..1,1..2] of longint=((1,1));
    ans:array[1..2] of longint;
    z,p,i,n,q,j,k:longint;
    c:cw;
function chen(a,b:cw):cw;
var i,j,k:longint;
    c:cw;
begin
 fillchar(c,sizeof(c),0);
 for i:=1 to 2 do
  for j:=1 to 2 do
   for k:=1 to 2 do
    c[i][j]:=(c[i][j]+a[i][k]*b[k][j]) mod q;
 exit(c);
end;

function ef(a:cw;n:longint):cw;
var b:cw;
begin
 if n=1 then exit(a);
 b:=ef(a,n div 2);
 b:=chen(b,b);
 if n mod 2=1 then b:=chen(b,a);
 exit(b);
end;

begin
 read(z);
 for p:=1 to z do begin
  ans[1]:=0;
  ans[2]:=0;
  read(n,q);
  if n=0 then writeln(0) else begin
   c:=ef(bb,n);
   i:=1;
   for j:=1 to 2 do
    for k:=1 to 2 do
     ans[j]:=(ans[j]+a[i][k]*c[k][j]) mod q;
  end;

 writeln(ans[1] mod q);
 end;
end.
