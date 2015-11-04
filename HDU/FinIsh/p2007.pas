var m,n,a1,a2,i:longint;
begin
 while not seekeof do begin
  read(m,n);
  if m>n then begin
   i:=m;
   m:=n;
   n:=i;
  end;
  a1:=0;a2:=0;
  for i:=m to n do
   if odd(i) then a2:=a2+i*i*i
             else a1:=a1+i*i;
  writeln(a1,' ',a2);
 end;
end.
