var n,i,sum,a:longint;
begin
 while not seekeof do begin
  read(n);
  sum:=0;
  for i:=1 to n do begin
   read(a);
   sum:=a+sum;
  end;
  writeln(sum);
 end;
end.
