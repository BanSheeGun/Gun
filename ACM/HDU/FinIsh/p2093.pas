var a,b,i:longint;
    t:boolean;
begin
 read(a,b);
 while not ((a=0)and(b=0)) do begin
  t:=false;

  for i:=-abs(b) to abs(b) do
   if (i<>0)and(t=false) then
    if b mod i=0 then
     if i+b div i=a then t:=true;
  if t then writeln('Yes')
       else writeln('No');
  read(a,b);
 end;
end.
