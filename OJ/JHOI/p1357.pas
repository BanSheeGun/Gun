var a:array[1..200000] of longint;
    i,n,ls,sum:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r)div 2];
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

 ls:=a[1];sum:=1;
 for i:=2 to n do begin
  if a[i]<>ls then begin
   writeln(ls,' ',sum);
   ls:=a[i];
   sum:=1;
  end else
  inc(sum);
 end;

 writeln(ls,' ',sum);
end.
