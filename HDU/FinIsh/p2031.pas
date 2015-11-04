var z:array[0..15] of char=('0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F');
    n,r,t,i:longint;
    f:array[0..10000] of longint;
begin
 while not seekeof do begin
  read(n,r);
  t:=0;
  if n<0 then write('-');
  if n=0 then write(0);
  n:=abs(n);
  while n<>0 do begin
   inc(t);
   f[t]:=n mod r;
   n:=n div r;
  end;
  for i:=t downto 1 do write(z[f[i]]);
  writeln;
 end;
end.
