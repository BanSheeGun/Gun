var p:boolean;
    a:longint;
begin
 while not seekeof do begin
  readln(a);
  p:=true;
  if (a>=0)and(a<=59) then begin
   writeln('E');
   p:=false;
  end;
  if (a>=60)and(a<=69) then begin
   writeln('D');
   p:=false;
  end;
  if (a>=70)and(a<=79) then begin
   writeln('C');
   p:=false;
  end;
  if (a>=80)and(a<=89) then begin
   writeln('B');
   p:=false;
  end;
  if (a>=90)and(a<=100) then begin
   writeln('A');
   p:=false;
  end;
  if p then writeln('Score is error!');
 end;
end.
