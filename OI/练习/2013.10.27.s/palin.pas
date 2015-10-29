const base=1000000007;
var a:array[0..100000] of longint;
    n,i:longint;
begin
 assign(input,'palin.in');reset(input);
 assign(output,'palin.out');rewrite(output);
 read(n);
 a[0]:=1;
 a[1]:=2;
 for i:=2 to n-1 do begin
  a[i]:=a[i div 2];
  a[i]:=(a[i-1]+a[i div 2]) mod base
 end;
 writeln(a[n div 2]);
 close(input);close(output);
end.
