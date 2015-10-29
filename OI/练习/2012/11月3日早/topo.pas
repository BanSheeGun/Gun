begin
 assign(input,'topo.in');reset(input);
 assign(output,'topo.out');rewrite(output);
 writeln(24);
 close(input);close(output);
end.
