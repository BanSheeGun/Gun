var a,b:longint;
function gcd(a,b:longint):longint;
begin
 if a mod b=0 then exit(b);
 exit(gcd(b,a mod b));
end;
begin
 read(a,b);
 writeln(gcd(a,b));
end.