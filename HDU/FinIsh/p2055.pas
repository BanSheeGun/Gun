var n,i,y,ans:longint;
    ch:char;
begin
 readln(n);
 for i:=1 to n do begin
  read(ch);
  if ('A'<=ch)and(ch<='Z') then ans:=ord(ch)-ord('A')+1
             else ans:=-(ord(ch)-ord('a')+1);
  read(ch);
  readln(y);
  writeln(ans+y);
 end;
end.
