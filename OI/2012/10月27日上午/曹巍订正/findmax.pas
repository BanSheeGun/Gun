const maxn=10000*100000+7;
type btype=record
       n,k,p:longint;
     end;
var n,k,p,z,t,i,tot,j,m:longint;
    f:array[-1..300,-1..300,-1..300] of int64;
    sum:array[-1..320,-1..320,-1..320] of longint;
    b:array[1..10000] of btype;
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
  assign(input,'findmax.in');reset(input);
 assign(output,'findmax.out');rewrite(output);
 read(t);
 for z:=1 to t do begin
  read(b[z].n,b[z].k,b[z].p);
  if b[z].n>n then n:=b[z].n;
  if b[z].k>k then k:=b[z].k;
  if b[z].p>p then p:=b[z].p;
  //writeln(a(n,p,k));
 end;
a(n,p,k);
for i:=1 to t do
  begin
    tot:=0;
     for j:=0 to b[i].k do tot:=(tot+f[b[i].n][b[i].p][j]) mod maxn;
   writeln(tot mod maxn);
  end;
close(input);
close(output);
end.

