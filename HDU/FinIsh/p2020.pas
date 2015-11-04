var a:array[1..101] of longint;
    n,i:longint;
procedure sort(l,r:longint);
var i,j,x,y: longint;
begin
 i:=l;j:=r;
 x:=abs(a[(l+r) div 2]);
 repeat
  while abs(a[i])>x do inc(i);
  while x>abs(a[j]) do dec(j);
  if not(i>j) then begin
   y:=a[i];
   a[i]:=a[j];
   a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;
begin
 read(n);
 while n<>0 do begin
  for i:=1 to n do
   read(a[i]);
  sort(1,n);

  for i:=1 to n-1 do write(a[i],' ');
  writeln(a[n]);
  read(n);
 end;
end.
