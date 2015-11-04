var a:array[1..1500000] of longint;
    n,i,j,ans:longint;
begin
 assign(input,'1.in');reset(input);
 assign(output,'0.out');rewrite(output);
 read(n);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do begin
  read(a[n+i]);
  for j:=1 to n do
   if a[j]>a[n+i] then inc(ans);
 end;
 writeln(ans);
 close(input);close(output);
end.
