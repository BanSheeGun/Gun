var c:array[0..1010] of longint;
    i,j,a,b,k,m,n,base,ans:longint;

function pow(a,n:longint):longint;
var s:longint;
begin
 if n=0 then exit(1);
 if n=1 then exit(a);
 s:=pow(a,n div 2) mod base;
 s:=s*s mod base;
 if n mod 2=1 then s:=s*a mod base;
 exit(s);
end;

begin
 assign(input,'factor.in');reset(input);
 assign(output,'factor.out');rewrite(output);
 read(a,b,k,n,m);
 c[1]:=1;
 base:=10007;
 for i:=2 to k+1 do
  for j:=i downto 1 do
   c[j]:=(c[j]+c[j-1]) mod base;
 ans:=c[n+1]*pow(a,n) mod base*pow(b,m) mod base;
 writeln(ans mod base);
 close(input);close(output);
end.
