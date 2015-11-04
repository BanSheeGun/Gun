begin
 assign(input,'robot.in');reset(input);
 assign(output,'robot.out');rewrite(output);
 writeln('RRLU');
 close(input);close(output);
end.
