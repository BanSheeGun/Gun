var a,b:extended;
begin
 while not seekeof do begin
  readln(a);
  b:=-a;
  if a>b then writeln(a:0:2)
         else writeln(b:0:2);
 end;
end.
