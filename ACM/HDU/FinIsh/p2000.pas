var a,b,c:char;
begin
 while not seekeof do begin
  readln(a,b,c);
  if (a<b)and(b<c) then writeln(a,' ',b,' ',c);
  if (a<c)and(c<b) then writeln(a,' ',c,' ',b);
  if (b<a)and(a<c) then writeln(b,' ',a,' ',c);
  if (b<c)and(c<a) then writeln(b,' ',c,' ',a);
  if (c<b)and(b<a) then writeln(c,' ',b,' ',a);
  if (c<a)and(a<b) then writeln(c,' ',a,' ',b);
 end;
end.