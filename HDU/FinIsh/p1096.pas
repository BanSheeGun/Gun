var t,tt,n,i,sum,a:longint;
begin
 read(t);
 for tt:=1 to t do begin
  read(n);
  sum:=0;
  for i:=1 to n do begin
   read(a);
   sum:=a+sum;
  end;
  writeln(sum);
  if tt<>t then writeln;
 end;
end.
