var f:array[1..41] of longint;
    i,n,a:longint;
begin
 f[2]:=1;
 f[3]:=2;
 for i:=4 to 40 do
  f[i]:=f[i-1]+f[i-2];

 read(n);
 for i:=1 to n do begin
  read(a);
  writeln(f[a]);
 end;
end.
