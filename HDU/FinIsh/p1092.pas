var n,i,sum,a:longint;
begin
 read(n);
 while n<>0 do begin
  sum:=0;
  for i:=1 to n do begin
   read(a);
   sum:=a+sum;
  end;
  writeln(sum);
  read(n);
 end;
end.