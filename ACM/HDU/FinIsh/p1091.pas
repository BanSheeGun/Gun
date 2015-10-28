var a,b:longint;
begin
 read(a,b);
 while not((a=0)and(b=0)) do begin
  writeln(a+b);
  read(a,b);
 end;
end.
