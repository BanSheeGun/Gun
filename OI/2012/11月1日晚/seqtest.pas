var i:longint;
begin
 assign(output,'seq.out');rewrite(output);
 writeln(1500000);
 for i:=1 to 1500000 do
  writeln(i);
 close(output);
end.
