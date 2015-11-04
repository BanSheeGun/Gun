var f,fa:array[0..100,0..100] of longint;
    a:array[1..100,1..100] of longint;
    n,m,i,j,max,k:longint;
procedure pr(x,k:longint);
begin
 if fa[x][k]<>0 then begin
               pr(x-1,fa[x][k]);
               write(' ',k);
              end
              else write(k);
end;
begin
 read(n,m);
 for i:=1 to n do
  for j:=1 to m do
    read(a[i][j]);

 fillchar(f,sizeof(f),0);
 fillchar(fa,sizeof(fa),0);
 for i:=1 to n do
  for j:=i to m-(n-i) do
   begin
    max:=i-1;
    for k:=i-1 to j-1 do
     if f[i-1][k]>f[i-1][max] then max:=k;
    f[i][j]:=f[i-1][max]+a[i][j];
    fa[i][j]:=max;
   end;
 max:=n;
 for i:=n to m do
  if f[n][max]<f[n][i] then max:=i;
 writeln(f[n][max]);
 pr(n,max);
 writeln;
end.
