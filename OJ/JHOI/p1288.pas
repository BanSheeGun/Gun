var a:array[1..50,1..6] of longint;
    d:array[1..50] of longint;
    n,m,i,j:longint;
    ans:extended;
    mj:array[1..50] of extended;
function mj2(a1,a2,a3,a4,a5,a6:longint):extended;
var p,a,b,c:extended;
begin
  a:=sqrt(sqr(a1-a3)+sqr(a2-a4));
  b:=sqrt(sqr(a1-a5)+sqr(a2-a6));
  c:=sqrt(sqr(a3-a5)+sqr(a4-a6));
  p:=(a+b+c)/2;
  if (p<a)or(p<b)or(p<c) then exit(0);
  exit(sqrt(p*(p-a)*(p-b)*(p-c)));
end;


function pan(x,y:longint):boolean;
var i:longint;
    s:extended;
begin
 for i:=1 to 3 do
  begin
   s:=0;
   s:=s+mj2(a[x][i*2-1],a[x][i*2],a[y][1],a[y][2],a[y][3],a[y][4]);
   s:=s+mj2(a[x][i*2-1],a[x][i*2],a[y][1],a[y][2],a[y][5],a[y][6]);
   s:=s+mj2(a[x][i*2-1],a[x][i*2],a[y][3],a[y][4],a[y][5],a[y][6]);

   if abs(s-mj[y])>=0.00001 then exit(false);
  end;

 exit(true);
end;
begin
 read(n,m);
 for i:=1 to n do
  read(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6]);


 for i:=1 to n do
  mj[i]:=mj2(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6]);
 ans:=0;
 fillchar(d,sizeof(d),0);

 if m=0 then ans:=10000;
 for i:=1 to n do
  begin
   d[i]:=1;
   for j:=1 to n do
    if i<>j then
     if pan(i,j) then inc(d[i]);
    if d[i]=m then ans:=ans+mj[i];
    if d[i]=m+1 then ans:=ans-mj[i];
   end;

 writeln(ans/10000:0:5);
end.
