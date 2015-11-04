var a:array[1..100000] of longint;
    n,i,j,ans:longint;
begin
 assign(input,'3.in');reset(input);
 assign(output,'0.out');rewrite(output);
 read(n);
 for i:=1 to n do read(a[i]);

 ans:=0;
 for i:=1 to n do
  for j:=i+1 to n do
   if a[i] xor a[j]>ans then ans:=a[i] xor a[j];
 writeln(ans);
 close(input);close(output);
end.
