var jc,a:array[1..1000000] of int64;
    ma,n,i,x,p:longint;
    f:int64;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function pow(n,a:longint):int64;
var b:int64;
begin
 if n=0 then exit(1);
 if n=1 then exit(a);
 b:=pow(n div 2,a);
 b:=(b mod p)*(b mod p) mod p;
 if n mod 2=1 then exit(b*a mod p);
 exit(b mod p);
end;
begin
 assign(input,'horror.in');reset(input);
 assign(output,'horror.out');rewrite(output);
 read(n);
 ma:=0;
 x:=0;
 for i:=1 to n do
  read(a[i]);
 read(p);
 for i:=1 to n do begin
  ma:=max(ma,a[i]);
  x:=(x+a[i]);
 end;
 jc[1]:=1;
 for i:=2 to ma do jc[i]:=jc[i-1]*i mod p;
  f:=1;
 for i:=1 to n do
 f:=f*pow(p-2,jc[a[i]]) mod p;
 for i:=1 to x do f:=f*i mod p;
 writeln(f);
 close(input);close(output);
end.
