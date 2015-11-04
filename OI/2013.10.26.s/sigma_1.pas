var n,i,a,b,ans,t,z:longint;
function find(n:longint):longint;
var i,ans:longint;
begin
 ans:=0;
 for i:=1 to trunc(sqrt(n)) do
  if n mod i=0 then 
  if i*i=n then inc(ans) 
           else inc(ans,2);
 exit(ans);
end;
begin
 assign(input,'sigma.in');reset(input);
 assign(output,'sigma.out');rewrite(output);
 z:=0;
 while not eof do begin
  inc(z);
  readln(a,b);
  n:=1;
  ans:=0;
  for i:=1 to b do n:=n*a;
  for i:=1 to n do
   if n mod i=0 then begin
    t:=find(i);
    ans:=(ans+t*t*t) mod 10007;
   end;
  writeln('Case ',z,': ',ans);
 end;
 close(input);close(output);
end.
