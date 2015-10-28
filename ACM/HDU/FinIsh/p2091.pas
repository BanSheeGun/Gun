var ch,ch2:char;
    n,i,j:longint;
begin
 read(ch);
 while ch<>'@' do begin
  read(ch2);
  readln(n);
  if n=1 then writeln(ch) else begin
  for j:=1 to n-1 do write(' ');
  writeln(ch);
  for i:=2 to n-1 do begin
   for j:=1 to n-i do write(' ');
   write(ch);
   for j:=1 to 2*i-3 do write(' ');
   writeln(ch);
  end;
  for i:=1 to 2*n-1 do write(ch);
  writeln;
  end;
  read(ch);
  if ch<>'@' then writeln;
 end;
end.
