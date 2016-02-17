var f:array[0..8000] of longint;
    d,b,c:array[1..3] of longint;
    n,m,i,j,v,kk,k,z,top,v1,w1:longint;
function get(kk:longint):longint;
var i:longint;
begin
 for i:=1 to 3 do
  if kk=d[i] then exit(i);
end;
begin
 read(n,m);
 for i:=1 to 3 do read(d[i],b[i],c[i]);

 for i:=1 to n do begin
  read(v,kk);
  z:=get(kk);
  v1:=v*c[z]+v;w1:=v*b[z];
  for k:=m downto v1 do
   if f[k]<f[k-v1]+w1 then f[k]:=f[k-v1]+w1;
 end;
 writeln(f[m]);
end.
