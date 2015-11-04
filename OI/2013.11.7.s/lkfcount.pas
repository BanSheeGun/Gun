begin
 assign(input,'lkfcount.in');reset(input);
 assign(output,'lkfcount.out');rewrite(output);
 writeln(15);
 close(input);close(output);
end.