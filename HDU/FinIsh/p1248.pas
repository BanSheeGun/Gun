var f:array[0..10001] of longint;
    i,j,n:longint;
begin
 for i:=0 to 10000 do f[i]:=i;
 for i:=0 to 10000 do begin
  if i>=150 then if f[i]>f[i-150] then f[i]:=f[i-150];
  if i>=200 then if f[i]>f[i-200] then f[i]:=f[i-200];
 end;
 read(n);
 for i:=n downto 1 do begin
  read(j);
  writeln(f[j]);
 end;
end.
