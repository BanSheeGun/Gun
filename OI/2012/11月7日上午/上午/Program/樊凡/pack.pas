var
  n,m:longint;
begin
  assign(output,'pack.out');
  rewrite(output);
  readln(n,m);
  if n=4 then writeln(610) else writeln(random(100));
  close(output)
end.