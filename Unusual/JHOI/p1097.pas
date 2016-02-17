var a:array[1..10000] of longint;
    i,ans,k,j,n:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r) div 2];
 repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
  if i<=j then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if j>l then sort(l,j);
end;
begin
 read(n);
 for i:=1 to n do
  read(a[i]);
 sort(1,n);

 ans:=0;
 for i:=1 to n-1 do begin
  inc(ans,a[1]);
  inc(ans,a[2]);
  a[2]:=a[1]+a[2];
  k:=a[2];
  a[1]:=0;
  move(a[3],a[1],(n-i)*4);

  for j:=1 to n-i-1 do
   if a[j]>k then break;
  if a[j]<k then inc(j);
  if j<=n-i-1 then move(a[j],a[j+1],(n-i-j)*4);
  a[j]:=k;
 end;

 writeln(ans);
end.
