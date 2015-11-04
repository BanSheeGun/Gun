var a:array[1..10] of longint;
    i,m,ans:longint;
begin
 for i:=1 to 10 do read(a[i]);
 read(m);
 m:=m+30;
 ans:=0;
 for i:=1 to 10 do
  if a[i]<=m then inc(ans);
 writeln(ans);
end.
