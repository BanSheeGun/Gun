const pp=1000000007;
var c:array[0..300,0..300] of int64;
    f:array[1..101,1..101,0..301] of longint;
    t,tt,i,j,n,k,p:longint;
function df(n,k,p:longint):longint;
var i,j,ans:longint;
begin
 if f[n][k][p]<>0 then exit(f[n][k][p]);
 if (n<=p)or(k<=p) then exit(0);
 if p=1 then exit(k-1);
 if k=1 then exit(1);
 ans:=0;
 for i:=p to n-1 do
  for j:=p to k-1 do
   ans:=(ans+df(i,j,p-1)*c[j][n-i-1]) mod pp;
 f[n][k][p]:=ans;
 exit(ans);
end;

begin
 assign(input,'findmax.in');reset(input);
 assign(output,'findmax.out');rewrite(output);
 read(t);
 for i:=1 to 300 do begin c[i][1]:=1; c[i][0]:=1; c[0][i]:=1; end;
 for i:=1 to 300 do
  for j:=1 to 100 do
   c[i][j]:=(c[i][j-1]*i) mod pp;
 for tt:=1 to t do begin
  read(n,k,p);
  writeln(df(n+1,k+1,p+1));
 end;
 close(input);close(output);
end.
