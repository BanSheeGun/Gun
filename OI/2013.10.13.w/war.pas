var t,i,n:longint;
begin
 assign(input,'war.in');reset(input);
 assign(output,'war.out');rewrite(output);
 read(t);
 for i:=1 to t do begin
  read(n);
  writeln(trunc(sqrt(n)));
 end;
 close(input);close(output);
end.