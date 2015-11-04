var n,i:longint;
    ans:extended;
begin
 read(n);
 while n<>0 do begin
  ans:=0;
  for i:=2 to n do
   ans:=ans+(n-i+1)/i;
  ans:=ans*2+n;
  writeln(ans:0:2);
  readln(n);
 end;
end.