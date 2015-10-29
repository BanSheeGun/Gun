var a,b,d,i:longint;
    s:qword;
begin
 read(a,d,b);
 s:=0;
 a:=a-d;
 for i:=1 to b do begin
  a:=a+d;
  s:=s+a;
 end;
 writeln(s);
end.
