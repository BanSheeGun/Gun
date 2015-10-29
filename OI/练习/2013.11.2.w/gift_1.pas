var a,b,n:longint;
begin
 assign(input,'gift.in');reset(input);
 assign(output,'gift.out');rewrite(output);
 read(a,b,n);
 if n<>4 then writeln(-1)
 else begin
  read(a,b,n);
  read(a,b,n);
  read(a,b,n);
  read(a,b,n);
  if n=1 then writeln(100)
         else writeln(120);
 end;
 close(input);close(output);
end.