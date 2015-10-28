var f:array[1..50] of int64;
    n,i,a,b:longint;
begin
 f[1]:=1;f[2]:=2;
 for i:=3 to 50 do
  f[i]:=f[i-1]+f[i-2];
 read(n);
 for i:=1 to n do begin
  read(a,b);
  writeln(f[b-a]);
 end;
end.
