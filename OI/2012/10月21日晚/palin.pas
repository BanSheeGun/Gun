var f:array[-1..100000] of longint;
    n,i:longint;
begin
 assign(input,'palin.in');reset(input);
 assign(output,'palin.out');rewrite(output);
 f[-1]:=1;
 f[0]:=1;
 f[1]:=2;
 readln(n);
 for i:=2 to n div 2 do
  f[i]:=(f[i-1]+f[i div 2]) mod 1000000007;
 writeln(f[n div 2]);
 close(input);close(output);
end.
