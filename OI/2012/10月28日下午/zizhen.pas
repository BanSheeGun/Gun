var a:array[1..100,1..100] of longint;
    s:array[0..100,1..100] of longint;
    n,m,i,j,xs,ys,xt,yt,sum,ans:longint;
begin
 assign(input,'zizhen.in');reset(input);
 assign(output,'zizhen.out');rewrite(output);
 read(n,m);
 for i:=1 to n do
  for j:=1 to m do
   read(a[i][j]);
 
 for i:=1 to n
 
 writeln(ans);
 close(input);close(output);
end.
