var a:array[1..100] of longint;
    n,i:longint;
procedure sort(l,r:longint);
var i,j,p,q:longint;
begin
 i:=l;j:=r;
 q:=a[(l+r) div 2];
 repeat
  while (a[i]<q) do inc(i);
  while (q<a[j]) do dec(j);
  if not(i>j) then begin
   p:=a[i];a[i]:=a[j];a[j]:=p;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;
begin
 read(n);
 for i:=1 to n do read(a[i]);
 sort(1,n);
 for i:=1 to n-1 do write(a[i],' ');
 writeln(a[n]);
end.
