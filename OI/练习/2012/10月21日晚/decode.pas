var zm:array['A'..'Z'] of char;
    a:ansistring;
    i:longint;
    ch:char;
begin
 assign(input,'decode.in');reset(input);
 assign(output,'decode.out');rewrite(output);
 readln(a);
 for ch:='A' to 'Z' do
  read(zm[ch]);

 for i:=1 to length(a) do begin
  ch:=a[i];
  if (ch>='A')and(ch<='Z') then write(zm[ch])
                           else write(ch);
 end;

 writeln;
 close(input);close(output);
end.
