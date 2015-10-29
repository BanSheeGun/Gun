program ex;
var n,m:longint;
begin
   assign(input,'pack.in');reset(input);
   assign(output,'pack.out'); rewrite(output);
   read(n,m);
   if m=0 then writeln(0);
   close(input); close(output);
end.