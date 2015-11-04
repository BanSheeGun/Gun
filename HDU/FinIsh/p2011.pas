var m,n,k,i:longint;
    ans:extended;
begin
 read(m);
 for k:=1 to m do begin
  read(n);
  ans:=0;
  for i:=1 to n do
   if odd(i) then ans:=ans+1/i
             else ans:=ans-1/i;
  writeln(ans:0:2);
 end;
end.