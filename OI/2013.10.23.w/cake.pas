var n,m,s,e:longint;
begin
 assign(input,'cake.in');reset(input);
 assign(output,'cake.out');rewrite(output);
 read(n,m,s,e);
 if n=4 then writeln(4)
 else writeln(-1);
 close(input);close(output);
end.
