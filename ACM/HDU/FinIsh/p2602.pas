var c,v:array[1..1001] of longint;
    f:array[0..1001] of longint;
    t,y,num,i,j,n,w:longint;
begin
 readln(t);
 for num:=1 to t do begin
  readln(n,w);
  for i:=1 to n do read(v[i]);
  for i:=1 to n do read(c[i]);

  fillchar(f,sizeof(f),0);

  for i:=1 to n do
   for j:=w downto c[i] do
    if f[j]<f[j-c[i]]+v[i] then f[j]:=f[j-c[i]]+v[i];

  writeln(f[w]);
 end;
end.
