var base:array[1..10] of longint=(9,4,3,2,1,1,1,1,1,1);
    c:array[0..10] of longint;
    i,j,p,n,ans:longint;
begin
 assign(input,'cloud.in');reset(input);
 assign(output,'cloud.out');rewrite(output);
 read(n,p);
 c[1]:=1;
 for i:=2 to n do
  for j:=9 downto 1 do
   c[j]:=(c[j]+c[j-1])mod p;
 ans:=0;
 for i:=1 to 9 do
 ans:=(ans+c[i]*base[i]) mod p;
 writeln(ans);
 close(input);close(output);
end.