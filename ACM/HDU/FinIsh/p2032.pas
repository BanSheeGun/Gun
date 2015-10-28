var a:array[0..31,0..31] of longint;
    n,i,j:longint;
begin
 fillchar(a,sizeof(a),0);
 a[1][1]:=1;
 for i:=2 to 30 do
  for j:=1 to i do
   a[i][j]:=a[i-1][j]+a[i-1][j-1];

 while not seekeof do begin
  read(n);
  for i:=1 to n do begin
   for j:=1 to i-1 do
    write(a[i][j],' ');
    writeln(a[i][i]);
   end;
  writeln;
 end;
end.