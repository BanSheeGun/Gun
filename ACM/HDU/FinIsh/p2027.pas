var s:ansistring;
    n,ans,i,j:longint;
begin
 readln(n);
 for i:=1 to n do begin
  readln(s);
  ans:=0;
  for j:=1 to length(s) do
   if (s[j]='a') then inc(ans);
  writeln('a:',ans);
  ans:=0;
  for j:=1 to length(s) do
   if (s[j]='e') then inc(ans);
  writeln('e:',ans);
  ans:=0;
  for j:=1 to length(s) do
   if (s[j]='i') then inc(ans);
  writeln('i:',ans);
  ans:=0;
  for j:=1 to length(s) do
   if (s[j]='o') then inc(ans);
  writeln('o:',ans);
  ans:=0;
  for j:=1 to length(s) do
   if (s[j]='u') then inc(ans);
  writeln('u:',ans);
  if i<>n then writeln;
 end;
end.
