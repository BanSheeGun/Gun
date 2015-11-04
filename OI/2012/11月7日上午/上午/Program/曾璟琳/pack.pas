var n,m:longint;
begin 
assign(input,'pack.in');
reset(input);
assign(output,'pack.out');
rewrite(output);
readln(n,m);
if m=0 then writeln(0);
if m<>0 then writeln(m*61);
close(input);
close(output);
end.