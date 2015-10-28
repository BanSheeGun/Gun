var a,b:longint;
function f(n:longint):longint;
var q:longint;
begin
 if n=1 then exit(a mod 1000);
 q:=f(n div 2);
 q:=q*q mod 1000;
 if n mod 2=0 then exit(q);
 q:=q*a mod 1000;
 exit(q);
end;
begin
 read(a,b);
 while (a<>0)or(b<>0) do begin
  writeln(f(b));
  read(a,b);
 end;
end.