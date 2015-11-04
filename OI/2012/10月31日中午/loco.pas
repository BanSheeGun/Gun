var f:array[1..3,1..50000] of longint;
    a,sum:array[1..50000] of longint;
    n,i,m,j,max:longint;
begin
 assign(input,'loco.in');reset(input);
 assign(output,'loco.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(a[i]);
 read(m);
 for i:=1 to m do inc(sum[1],a[i]);
 for i:=2 to n-m+1 do
  sum[i]:=sum[i-1]-a[i-1]+a[i+m-1];

 for i:=1 to n-m+1 do
  f[1][i]:=sum[i];

 for i:=2 to 3 do begin
  max:=0;
  for j:=(i-1)*m+1 to n do begin
   if f[i-1][j-m]>max then max:=f[i-1][j-m];
   f[i][j]:=max+sum[j];
  end;
 end;

 max:=0;
 for i:=2*m+1 to n do
  if f[3][i]>max then max:=f[3][i];

 writeln(max);
 close(input);close(output);
end.
