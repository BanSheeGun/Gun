var n,i:longint;
    a,b:int64;
begin
 read(n);
 for i:=1 to n do begin
  read(a,b);
  writeln((a+b) mod 100);
 end;
end.