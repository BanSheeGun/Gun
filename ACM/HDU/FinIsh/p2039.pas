var n,z:longint;
    a,b,c:extended;
    t:boolean;
begin
 read(n);
 for z:=1 to n do begin
  t:=true;
  read(a,b,c);
  if a+b<=c then t:=false;
  if a+c<=b then t:=false;
  if c+b<=a then t:=false;
  if t then writeln('YES')
   else writeln('NO');
 end;
end.