var n,i,a,ans:longint;
begin
 read(n);
 while n<>0 do begin
  ans:=0;
  for i:=1 to n do begin
   read(a);
   ans:=ans+a div 100;
   a:=a mod 100;
   ans:=ans+a div 50;
   a:=a mod 50;
   ans:=ans+a div 10;
   a:=a mod 10;
   ans:=ans+a div 5;
   a:=a mod 5;
   ans:=ans+a div 2;
   a:=a mod 2;
   ans:=ans+a;
  end;
  writeln(ans);
  read(n);
 end;
end.
