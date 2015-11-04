var a:array[1..1000] of longint;
    n,i,min,t:longint;
begin
 read(n);
 while n<>0 do begin
  for i:=1 to n do read(a[i]);
  min:=1;
  for i:=2 to n do
   if a[i]<a[min] then min:=i;
  t:=a[min];
  a[min]:=a[1];
  a[1]:=t;
  for i:=1 to n-1 do write(a[i],' ');
  writeln(a[n]);
  read(n);
 end;
end.