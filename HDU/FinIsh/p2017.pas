var s:ansistring;
    n,ans,i,j:longint;
begin
 readln(n);
 for i:=1 to n do begin
  ans:=0;
  readln(s);
  for j:=1 to length(s) do
   if ('0'<=s[j])and(s[j]<='9') then inc(ans);      ;
  writeln(ans);
 end;
end.
