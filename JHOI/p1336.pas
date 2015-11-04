 type cw=record
     x,y:longint;
     end;
var f:array[1..1001]  of longint;
    a:array[-1..1001] of cw;
    i,j,ans,n,m,k:longint;
procedure sort(l,r: longint);
var i,j:longint;
begin
 i:=l; j:=r;
 a[-1]:=a[(l+r) div 2];
 repeat
    while (a[i].x<a[-1].x)or((a[i].x=a[-1].x)and(a[i].y<a[-1].y)) do inc(i);
    while (a[-1].x<a[j].x)or((a[-1].x=a[j].x)and(a[-1].y<a[j].y)) do dec(j);
    if not(i>j) then begin
    a[0]:=a[i];a[i]:=a[j];
    a[j]:=a[0];inc(i);dec(j);
   end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

begin
 read(n,m,k);
 for i:=1 to k do
  read(a[i].x,a[i].y);
 sort(1,k);


 for i:=1 to k do
  begin
   f[i]:=1;
   for j:=1 to i-1 do
    if (a[i].x>a[j].x)and(a[i].y>a[j].y)   then
    if f[i]<f[j]+1
     then f[i]:=f[j]+1;
  end;

 ans:=0;
 for i:=1 to k do
  if f[i]>ans then ans:=f[i];
 writeln(round((n+m+ans*sqrt(2)-ans*2)*100));
end.
