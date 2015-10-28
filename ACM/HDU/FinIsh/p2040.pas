var n,a,b,aa,bb,i,j:longint;
begin
 read(n);
 for j:=1 to n do begin
  read(a,b);
  aa:=0;
  bb:=0;
  for i:=1 to a-1 do
   if a mod i=0 then aa:=aa+i;
  for i:=1 to b-1 do
   if b mod i=0 then bb:=bb+i;

  if (aa=b)and(bb=a) then writeln('YES')
   else writeln('NO');
 end;
end.
