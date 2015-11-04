var a,b,n,i:longint;
begin
 read(n);
 for i:=1 to n do begin
  read(a,b);
  if a mod b=0 then writeln('YES')
  else writeln('NO');
 end;
end.