var s:ansistring;
    l,i:longint;
begin
 while not seekeof do begin
  readln(s);
  s:=' '+s;
  l:=length(s);
  for i:=2 to l do
   if s[i-1]=' ' then write(chr(ord(s[i])-32))
    else write(s[i]);
  writeln;
 end;
end.