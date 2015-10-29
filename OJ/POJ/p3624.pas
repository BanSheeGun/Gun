var f:array[0..1360800] of longint;
    i,j,m,n,v,w:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 read(n,m);
 for i:=1 to n do begin 
  read(w,v);
  for j:=m downto w do
   f[j]:=max(f[j],f[j-w]+v); 
 end;
 writeln(f[m]);
end.