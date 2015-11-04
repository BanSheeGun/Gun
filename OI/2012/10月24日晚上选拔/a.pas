var a:array[1..10000] of boolean;
    n,sum,i,j:longint;
begin
 assign(input,'a.in');reset(input);
 assign(output,'a.out');rewrite(output);
 fillchar(a,sizeof(a),true);
 read(n);
 for i:=2 to n do
  for j:=1 to n div i do
   if a[j*i] then a[j*i]:=false
             else a[j*i]:=true;
 sum:=0;
 for i:=1 to n do
  if a[i] then inc(sum);
 writeln(sum);
 close(input);close(output);
end.
