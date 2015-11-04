var a:array[1..1000] of longint;
    n,x,xx,i:longint;
begin
 read(n,x);
 while (n<>0)or(x<>0) do begin
  for i:=1 to n do read(a[i]);
  xx:=n+1;
  for i:=n downto 1 do
   if a[i]>x then xx:=i;

  for i:=1 to xx-1 do
   write(a[i],' ');
  if xx=n+1 then writeln(x)
   else begin
    write(x,' ');
    for i:=xx to n-1 do
     write(a[i],' ');
     writeln(a[n]);
   end;
  read(n,x);
 end;
end.
