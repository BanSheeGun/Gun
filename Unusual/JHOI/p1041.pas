var ans:longint;
    x1,x2:extended;
begin
 read(x1,x2);
 x1:=x1/100;
 x2:=x2/100;
 for ans:=1 to 100000 do
  begin
   if trunc(ans*x1)+1>ans*x1 then
    if trunc(ans*x2)<ans*x2 then
     if trunc(ans*x1)+1<=trunc(ans*x2) then
     break;
  end;
 writeln(ans);
end.
