var i,a,b:longint;
    t:boolean;
function p(n:longint):boolean;
var i:longint;
begin
 if n=1 then exit(false);
 for i:=2 to trunc(sqrt(n)) do
  if n mod i=0 then exit(false);
 exit(true);
end;
begin
 read(a,b);
 while (a<>0)or(b<>0) do begin
  t:=true;

  for i:=a to b do
   if not p(i*i+i+41) then t:=false;

  if t then writeln('OK')
       else writeln('Sorry');
  read(a,b);
 end;
end.
