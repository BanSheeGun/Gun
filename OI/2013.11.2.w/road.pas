var x,y,z,k:array[1..100000] of longint;
    ans,i,n,m:longint;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
function gcd(a,b:longint):longint;
begin
 if a mod b=0 then exit(b);
 exit(gcd(b,a mod b));
end;

begin
 assign(input,'road.in');reset(input);
 assign(output,'road.out');rewrite(output);
 read(n,m);
 for i:=1 to m do
  read(x[i],y[i],z[i]);
 if n-m=1 then begin
  ans:=z[1];
  for i:=2 to m do
   ans:=gcd(ans,z[i])
 end
 else if n=m then begin
  ans:=z[1];
  for i:=2 to m do
  ans:=ans*z[i] div gcd(ans,z[i]);
 end
 else begin
  ans:=z[1];
  for i:=2 to n do
   ans:=gcd(ans,z[i]);
 end;
 writeln(ans);
 close(input);close(output);
end.
