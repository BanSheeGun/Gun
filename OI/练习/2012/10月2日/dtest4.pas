var t,m,i,j:longint;
    v,c:array[1..30] of longint;
    ans:array[0..1000] of longint;
begin
 assign(input,'dtest4.in');reset(input);
 assign(output,'dtest4.out');rewrite(output);
 read(t,m);
 for i:=1 to t do
  read(c[i]);
 for i:=1 to t do
  read(v[i]);

 fillchar(ans,sizeof(ans),0);
 for i:=1 to t do
  for j:=m downto c[i] do
   if ans[j]<ans[j-c[i]]+v[i] then
     ans[j]:=ans[j-c[i]]+v[i];

 writeln(ans[m]);
 close(input);close(output);
end.

