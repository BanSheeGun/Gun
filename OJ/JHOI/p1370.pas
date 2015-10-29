var s,v,t:array[1..100] of longint;
    a:array[1..101,1..101] of longint;
    f:array[1..101,0..1000] of longint;
    i,j,k,n,m:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 read(n,m);
 for i:=1 to n do
  read(s[i],v[i],t[i]);
 for i:=1 to n do
  for j:=1 to n do
   read(a[i][j]);
 s[n+1]:=maxlongint;
 for j:=1 to n+1 do
  for i:=m downto 1 do
   for k:=1 to n do
   if j<>k then begin
    if (i-a[k][j]-t[k]>=0)and(s[k]<s[j]) then
     f[j][i]:=max(f[j][i],f[k][i-a[k][j]-t[k]]+v[k]);
    if (i-a[k][j]>0) then
     f[j][i]:=max(f[j][i],f[k][i-a[k][j]]);
   end;

 k:=0;
 for i:=1 to n+1 do
  for j:=0 to m do
  k:=max(f[i][j],k);

 writeln(k);
end.
