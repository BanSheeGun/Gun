var mi,ma:array[1..50000,0..16] of longint;
    n,i,j,k,am,bm,l,r,m:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

begin
 read(n,m);
 for i:=1 to n do begin
  read(ma[i][0]);
  mi[i][0]:=ma[i][0];
 end;

 for i:=1 to 16 do
  for j:=1 to (n-(1<<i)+1) do begin
    k:=1<<(i-1);
    mi[j][i]:=min(mi[j][i-1],mi[j+k][i-1]);
    ma[j][i]:=max(ma[j][i-1],ma[j+k][i-1]);
  end;

 for i:=1 to m do begin
  read(l,r);
  k:=trunc(ln(r-l+1)/ln(2));
  am:=max(ma[l][k],ma[r-1<<k+1][k]);
  bm:=min(mi[l][k],mi[r-1<<k+1][k]);
  writeln(am-bm);
 end;
end.
