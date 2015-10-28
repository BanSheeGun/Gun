var n,i,ans:longint;
begin
 while not seekeof do begin
  read(n);
  ans:=1;
  for i:=1 to n-1 do
   ans:=(ans+1)*2;
  writeln(ans);
 end;
end.