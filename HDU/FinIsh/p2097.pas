var n,a,b,c,t,i:longint;
begin
 read(n);
 while n<>0 do begin
  t:=n;
  a:=0;b:=0;c:=0;
  for i:=1 to 4 do begin
   a:=a+t mod 10;
   t:=t div 10;
  end;

  t:=n;
  while t<>0 do begin
   b:=b+t mod 16;
   t:=t div 16;
  end;
  t:=n;
  while t<>0 do begin
   c:=c+t mod 12;
   t:=t div 12;
  end;

  if (a=b)and(b=c) then writeln(n,' is a Sky Number.')
  else writeln(n,' is not a Sky Number.');
  read(n);
 end;
end.
