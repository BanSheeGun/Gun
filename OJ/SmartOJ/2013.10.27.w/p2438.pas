var a,ans:longint;
begin
 read(a);
 ans:=0;
 while a<>0 do begin
  ans:=ans+a mod 10;
  a:=a div 10;
 end;
 writeln(ans);
end.