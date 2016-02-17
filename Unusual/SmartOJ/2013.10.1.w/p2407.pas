var  n,j,i:longint;
begin
 read(n);
 for i:=1 to n do begin
  for j:=1 to i do
   write((i+j-1) mod 10);
  for j:=i-1 downto 1 do
   write((i+j-1) mod 10);
  writeln;
 end;
end.
