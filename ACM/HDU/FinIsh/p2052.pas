var i,j,w,h:longint;
begin
 while not seekeof do begin
  read(w,h);

  write('+');
  for i:=1 to w do write('-');
  writeln('+');
  for i:=1 to h do begin
   write('|');
   for j:=1 to w do write(' ');
   writeln('|');
  end;

  write('+');
  for i:=1 to w do write('-');
  writeln('+');
  writeln;
 end;
end.