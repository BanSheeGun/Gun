var a,b,c,d,e,f,n,i:longint;
begin
 read(n);
 for i:=1 to n do begin
  read(a,b,c,d,e,f);
  a:=a+d;
  b:=b+e;
  c:=c+f;
  b:=b+c div 60;
  a:=a+b div 60;
  b:=b mod 60;
  c:=c mod 60;
  writeln(a,' ',b,' ',c);
 end;
end.