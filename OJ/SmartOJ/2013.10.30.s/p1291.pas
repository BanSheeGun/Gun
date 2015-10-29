var ans,aa,x,y,i:longint;
begin
 ans:=0;
 aa:=0;
 for i:=1 to 7 do begin
  read(x,y);
  if x+y>8 then
   if x+y>ans then begin
    ans:=x+y;
    aa:=i;
   end;
 end;
 writeln(aa);
end.
