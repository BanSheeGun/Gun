var ans,a,b,t:longint;
function gcd(a,b:longint):longint;
begin
 if a mod b = 0 then exit(b);
 exit(gcd(b,a mod b));
end;
begin
 while not seekeof do begin
  readln(a,b);
  t:=gcd(a,b);
  ans:=a*b div t;
  writeln(ans);
 end;
end.