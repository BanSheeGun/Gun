var t:array[0..10] of longint=(1,2,4,8,16,32,64,128,256,512,1024);
    a:array[0..10,1..1024] of longint;
    n,m,ans,i,j,x:longint;
begin
 assign(input,'football.in');reset(input);
 assign(output,'football.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(x);
  a[n][x]:=1;
 end;
 ans:=0;
 for i:=n-1 downto 0 do begin
  for j:=1 to t[i] do begin
   a[i][j]:=a[i+1][j*2-1] and a[i+1][j*2];
   if a[i+1][j*2-1] <> a[i+1][j*2] then inc(ans);
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
