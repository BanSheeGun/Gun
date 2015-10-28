var n,r,t,i:longint;
    f:array[0..10000] of longint;
begin
 while not seekeof do begin
  read(n);r:=2;
  t:=0;
  if n<0 then write('-');
  if n=0 then write(0);
  n:=abs(n);
  while n<>0 do begin
   inc(t);
   f[t]:=n mod r;
   n:=n div r;
  end;
  for i:=t downto 1 do write(f[i]);
  writeln;
 end;
end.
