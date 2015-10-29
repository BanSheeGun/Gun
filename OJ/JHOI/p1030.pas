var b:array['A'..'Z'] of longint;
    bm:array['A'..'Z',1..4] of longint;
    ch,max:char;
begin
 readln(n);
 readln(m);
 for ch:='A' to 'Z' do
  begin
   bm[ch][1]:=maxlongint;
   bm[ch][3]:=-maxlongint;
   bm[ch][2]:=-maxlongint;
   bm[ch][4]:=maxlongint;
  end;
 max:='A'
 for i:=1 to n do 
  begin
  for j:=1 to m do
   begin
    read(ch);
    if ch<>'.' then 
     begin
      
     end;
    if ch>max then max:=ch;
   end;
    readln;
  end;
  
end.