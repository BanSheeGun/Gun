var a,b:array[0..2000,0..2000] of longint;
begin
 reqad(n,m);
 for i:=1 to n do
  for j:=1 to n do begin
   read(a[i][j]);
   a[i][j]:=a[i][j]+a[i][j-1];
  end;
 for i:=1 to n do
  for j:=1 to n do begin
   read(b[i][j]);
   b[i][j]:=b[i][j]+b[i-1][j];
  end;
 
 for i:=1 to n
end.