var f1,f2:array[1..1000] of longint;
    a:array[1..1000] of extended;
    n,i,j,ans:longint;
begin
 read(n);
 for i:=1 to n do read(a[i]);

 for i:=1 to n do begin
  f1[i]:=1;
  for j:=1 to i-1 do
   if a[j]<a[i] then
    if f1[j]+1>f1[i] then f1[i]:=f1[j]+1;
 end;


 for i:=n downto 1 do begin
  f2[i]:=1;
  for j:=n downto i+1 do
   if a[j]<a[i] then
    if f2[j]+1>f2[i] then f2[i]:=f2[j]+1;
 end;
 ans:=0;
 for i:=1 to n do
  for j:=i+1 to n do
 if f1[i]+f2[j]>ans then ans:=f1[i]+f2[j];
 writeln(n-ans);
end.
