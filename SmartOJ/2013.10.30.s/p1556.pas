var a:array[0..10000] of longint;
    x,l,r,i:longint;
begin
 read(l,r);
 for i:=1 to r do begin
  a[i]:=a[i-1];
  x:=i;
  while x<>0 do begin
   if x mod 10=2 then inc(a[i]);
   x:=x div 10;
  end;
 end;
 writeln(a[r]-a[l-1]);
end.
