type cw=array[1..2,1..2] of int64;
var bb:cw;
    ans,b:array[1..2] of int64;
    m,aa,n,g,cc,x0:int64;
    c:cw;
    j,k:longint;

function chenc(a,b:int64):int64;
var z,ans,k:int64;
begin
 k:=b;
 a:=a mod m;
 ans:=0;
 z:=a;
 while k<>0 do begin
  if k mod 2=1 then ans:=(ans+z) mod m;
  z:=z*2 mod m;
  k:=k div 2;
 end;
 exit(ans);
end;


function chen(a,b:cw):cw;
var i,j,k:longint;
    c:cw;
begin
 fillchar(c,sizeof(c),0);
 for i:=1 to 2 do
  for j:=1 to 2 do
   for k:=1 to 2 do
    c[i][j]:=(c[i][j]+chenc(a[i][k],b[k][j]) mod m) mod m;
 exit(c);
end;

function ef(a:cw;n:int64):cw;
var b:cw;
begin
 if n=1 then exit(a);
 b:=ef(a,n div 2);
 b:=chen(b,b);
 if n mod 2=1 then b:=chen(b,a);
 exit(b);
end;

begin
 read(m,aa,cc,x0,n,g);
 ans[1]:=0;ans[2]:=0;
 bb[1][1]:=aa;
 bb[1][2]:=0;
 bb[2][1]:=cc;
 bb[2][2]:=1;
                               x
 c:=ef(bb,n);

 b[1]:=x0;b[2]:=1;
 for j:=1 to 2 do
  for k:=1 to 2 do
   ans[j]:=(ans[j]+chenc(b[k],c[k][j]) mod m) mod m;
 writeln(ans[1] mod g);
end.
