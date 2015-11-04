var t,q,m,n,k,i:longint;
function gcd(a,b:longint):longint;
begin
 if a mod b=0 then exit(b);
 exit(gcd(b,a mod b));
end;
begin
 read(t);
 for i:=1 to t do begin
  read(n,m);
  n:=n-1;
  m:=m-1;
  if n=0 then writeln(m+1)
  else if m=0 then writeln(n+1)
       else begin
        k:=gcd(m,n);
        writeln(k+1);
       end;
 end;
end.
