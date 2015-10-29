var st:ansistring;
    z:array['A'..'Z'] of char;
    n,i:longint;
    ch:char;
begin
 assign(input,'decode.in');reset(input);
 assign(output,'decode.out');rewrite(output);
 readln(st);
 for ch:='A' to 'Z' do
  read(z[ch]);

 for i:=1 to length(st) do
  if st[i]=' ' then write(st[i])
               else write(z[st[i]]);
 writeln;
 close(input);close(output);
end.
