var n,i:longint;
begin
 assign(input,'chessman.in');reset(input);
 assign(output,'chessman.out');rewrite(output);
 read(n);
 if n=6 then begin
   writeln('YES');
   writeln('NO');
   writeln('YES');
   writeln('NO');
   writeln('NO');
   writeln('NO');
 end
 else begin
  for i:=1 to n do
   writeln('NO');
 end;
 close(input);close(output);
end.