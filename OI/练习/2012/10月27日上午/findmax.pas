const maxn=10000*10000+7;
var n,k,p,z,t,i,tot,j,m:longint;
    f:array[-1..100,-1..300,-1..100] of int64;
    sum:array[-1..320,-1..320,-1..320] of longint;
function a(n,p,kk:longint):longint;
var i,j,k:longint;
begin
 //if f[n][k][p]<>0 then exit(f[n][k][p]);
 //if (n=1) then exit(1)
   for i:=1 to kk do
    begin
      f[1][0][i]:=1;
      sum[1,0,i]:=sum[1,0,i-1]+f[1,0,i];
    end;
   for i:=2 to n do
    for j:=0 to i-1 do
      for k:=1 to kk do
   begin
     if j>=1 then f[i,j,k]:=sum[i-1,j-1,k-1];
     f[i,j,k]:=sum[i-1,j-1,k-1];
     f[i][j][k]:=(f[i,j,k]+f[i-1][j][k]*k) mod maxn;
     sum[i,j,k]:=(sum[i,j,k-1]+f[i,j,k]) mod maxn;
   end;
     tot:=0;
     for j:=0 to kk do tot:=(tot+f[n][p][j]) mod maxn;
 exit(tot mod maxn);
end;
begin
 read(t);
 for z:=1 to t do begin
  read(n,k,p);
  writeln(a(n,p,k));
 end;
end.

