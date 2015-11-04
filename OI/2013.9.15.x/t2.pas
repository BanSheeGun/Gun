var n:longint;
begin
 assign(input,'t2.in');reset(input);
 assign(output,'t2.out');rewrite(output);
 read(n);
 writeln(3*n-2,' ',4*n-3);
 close(input);close(output);
end.
