var x,y,i:longint;
begin
 assign(input,'spring.in');reset(input);
 assign(output,'spring.out');rewrite(output);
 while not eof do begin
  readln(x,y);
  if y=0 then writeln(-1)
  else begin
   if x<=8 then writeln(0)
   else begin
    for i:=1 to x div 9 do write(555555555);
    for i:=1 to y do write(0);
    writeln;
  end;
  end;
 end;
 close(input);close(output);
end.
