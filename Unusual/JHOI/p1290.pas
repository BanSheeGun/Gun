var n,i:longint;
begin
 read(n);
 for i:=1 to n div 2 do
  begin
   writeln(i);
   writeln(n-i+1);
  end;

 if n mod 2=1 then writeln(n div 2+1);
end.
