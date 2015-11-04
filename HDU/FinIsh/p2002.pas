var a,b:extended;
    ans:extended;
begin
 b:=3.1415927;
 while not seekeof do begin
  readln(a);
  ans:=a*a*a*b*4/3;
  writeln(ans:0:3);
 end;
end.
