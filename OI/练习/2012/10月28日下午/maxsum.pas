var a,f:array[0..1000] of longint;
    n,i,j:longint;
begin
 assign(input,'maxsum.in');reset(input);
 assign(output,'maxsum.out');rewrite(output);
 read(n);
 for i:=1 to n do
  for j:=2 to n div i do
   inc(a[i*j],i);

 f[1]:=0;
 f[0]:=0;
 for i:=0 to n do
  for j:=i to n do
   if f[i]+a[j-i]>f[j] then f[j]:=f[i]+a[j-i];

 writeln(f[n]);
 close(input);close(output);
end.
