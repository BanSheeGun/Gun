const ma=2147483647;
var a:array[1..1000,1..1000] of longint;
    t:array[0..1000,0..1000] of boolean;
    f2,f5:array[1..1000,1..1000] of longint;
    n,k,i,j,mi:longint;
function d5(n:longint):longint;
var ans,k:longint;
begin
 ans:=0;
 k:=n;
 while (k mod 5=0)and(k<>0) do begin
  inc(ans);
  k:=k div 5;
 end;
 exit(ans);
end;

function d2(n:longint):longint;
var ans,k:longint;
begin
 ans:=0;
 k:=n;
 while (k mod 2=0)and(k<>0) do begin
  inc(ans);
  k:=k div 2;
 end;
 exit(ans);
end;

function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

begin
 fillchar(t,sizeof(t),false);
 read(n);
 for i:=1 to n do
  for j:=1 to n do begin
   read(k);
   if k<>0 then begin
    t[i][j]:=true;
    f2[i][j]:=d2(k);
    f5[i][j]:=d5(k);
   end
   else t[i][j]:=false;
  end;

 for i:=1 to n do
  for j:=1 to n do
   if t[i][j] then begin
    mi:=ma;
    if t[i][j-1] then mi:=min(mi,f2[i][j-1]);
    if t[i-1][j] then mi:=min(mi,f2[i-1][j]);
    if mi<>ma then f2[i][j]:=f2[i][j]+mi;
    mi:=ma;
    if t[i][j-1] then mi:=min(mi,f5[i][j-1]);
    if t[i-1][j] then mi:=min(mi,f5[i-1][j]);
    if mi<>ma then f5[i][j]:=f5[i][j]+mi;
    if (mi=ma)and((i<>1)and(j<>1)) then t[i][j]:=false;
   end;

  writeln(min(f5[n][n],f2[n][n]));
end.
