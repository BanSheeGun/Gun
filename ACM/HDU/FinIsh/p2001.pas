var a,b,c,d:extended;
    ans:extended;
begin
 while not seekeof do begin
  readln(a,b,c,d);
  ans:=sqrt((a-c)*(a-c)+(b-d)*(b-d));
  writeln(ans:0:2);
 end;
end.