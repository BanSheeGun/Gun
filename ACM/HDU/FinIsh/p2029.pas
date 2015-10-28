var s:ansistring;
    x,y,n,i:longint;
    t:boolean;
begin
 readln(n);
 for i:=1 to n do begin
  readln(s);
  t:=true;
  x:=1;
  y:=length(s);
  while (x<y)and t do begin
   if s[x]<>s[y] then t:=false;
   inc(x);
   dec(y);
  end;

  if t then writeln('yes')
       else writeln('no');
 end;
end.
