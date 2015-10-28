var a,b:longint;
begin
 while not seekeof do begin
  readln(a,b);
  writeln(a+b);
  writeln;
 end;
end.