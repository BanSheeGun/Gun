var s:ansistring;
    l,i:longint;
    max:char;
begin
 while not seekeof do begin
  readln(s);
  max:=s[1];
  l:=length(s);
  for i:=1 to l do
   if s[i]>max then max:=s[i];
  for i:=1 to l do
   if s[i]=max then write(s[i],'(max)')
   else write(s[i]);
  writeln;
 end;
end.