type cw=array[1..2,1..2] of longint;
var bb:cw=((0,1),(1,1));
    a:array[1..1,1..2] of longint=((1,1));
    ans:array[1..2] of longint;
    z,p,i,q,j,k:longint;
    c:cw;
    n:int64;
function chenc(a,b:int64):int64;
var z,ans,k,m:int64;
begin
 m:=q;
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
    c[i][j]:=(c[i][j]+chenc(a[i][k],b[k][j])) mod q;
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
 q:=1000000007;
 while not seekeof do begin
  ans[1]:=0;
  ans[2]:=0;
  readln(n);
  n:=n-1;
  if n=0 then writeln(1) else begin begin
   c:=ef(bb,n);
   i:=1;
   for j:=1 to 2 do
    for k:=1 to 2 do
     ans[j]:=(ans[j]+chenc(a[i][k],c[k][j])) mod q;
  end;

 writeln(ans[1] mod q); end;
 end;
end.
