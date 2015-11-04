var a:array[1..1000] of longint;
    n,i:longint;
begin
 a[1]:=1;a[2]:=2;a[3]:=3;
 a[4]:=4;
 for i:=5 to 55 do
  a[i]:=a[i-1]+a[i-3];
 read(n);
 while n<>0 do begin
  writeln(a[n]);
  read(n);
 end;
end.
