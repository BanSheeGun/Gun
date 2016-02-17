var n,max,min,a,i:longint;
begin
 read(n);
 read(max);
 min:=max;
 for i:=2 to n do begin
  read(a);
  if a>max then max:=a;
  if a<min then min:=a;
 end;
 writeln(max,' ',min);
end.
