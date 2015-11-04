var n,ans,i,a:longint;
begin
 while not seekeof do begin
  read(n);
  ans:=1;
  for i:=1 to n do begin
   read(a);
   if odd(a) then ans:=ans*a;
  end;
  writeln(ans);
 end;
end.
