var n,m,k,z:longint;
function f(n:longint):boolean;
var i:longint;
begin
 if n=1 then exit(false);
 for i:=2 to trunc(sqrt(n)) do
  if n mod i=0 then exit(false);
 exit(true);
end;
begin
 read(m,n);
 if m mod 10=n then begin
  if f(m) then writeln('true')
          else writeln('false');
 end
 else writeln('false');
end.
