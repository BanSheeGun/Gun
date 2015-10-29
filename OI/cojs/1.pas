var a,b:extended;
begin
 assign(input,'aplusb.in');reset(input);
 assign(output,'aplusb.out');rewrite(output);
 read(a,b);
 writeln(a+b:0:0);
 close(input);close(output);
end.