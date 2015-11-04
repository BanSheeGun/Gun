var t,n,i:longint;
    a,b:int64;
function gcd(a,b:longint):longint;
begin
 if a mod b = 0 then exit(b);
 exit(gcd(b,a mod b));
end;
begin
 while not seekeof do begin
  read(n);
  read(b);
  for i:=2 to n do begin
   read(a);
   t:=gcd(a,b);
   b:=a div t*b;
  end;

  writeln(b);
 end;
end.
