var hx,mm,money,x:longint;
    t:boolean;
begin
 mm:=0;
 t:=true;
 for x:=1 to 12 do begin 
  read(hx);
  inc(money,300);
  dec(money,hx);
  if money<0 then begin 
   writeln(-x);
   t:=false;
   break; 
  end;
  mm:=mm+money div 100;
  money:=money mod 100;
 end;
 if t then writeln(money+mm*120);
end.