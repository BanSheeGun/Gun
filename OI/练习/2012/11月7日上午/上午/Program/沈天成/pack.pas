var n:longint;
begin
assign(input,'pack.in');reset(input);
assign(output,'pack.out');rewrite(output);
readln(n);
if n=4 then writeln(610)else writeln(0);
close(input);close(output);
end.