var f:array[1..202,1..202,-1..202] of boolean;
    i,j,k,n,m:longint;
    a:array[1..200,1..200] of char; 
    ans:int64;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;

function pan(x,y,k:longint):boolean;
var i:longint;
begin
 for i:=1 to k do begin
  if a[x+i-1][y+i-1]<>a[x+k-i][y+i-1] then exit(false);
  if a[x+i-1][y+i-1]<>a[x+i-1][y+k-i] then exit(false);
  if a[x+i-1][y+i-1]<>a[x+k-i][y+k-i] then exit(false);
 end;
 exit(true);
end;


begin
 assign(input,'gift.in');reset(input);
 assign(output,'gift.out');rewrite(output);
 readln(n,m);
 for i:=1 to n do begin
  for j:=1 to m do
   read(a[i][j]);
  readln;
 end;
 ans:=0;
 fillchar(f,sizeof(f),true);
 for k:=1 to min(n,m) do
  for i:=1 to n do
   for j:=1 to m do
    if (i+k-1<=n)and(j+k-1<=m) then begin
     f[i][j][k]:=false;
     if f[i+1][j+1][k-2] then f[i][j][k]:=pan(i,j,k);
     ans:=ans+ord(f[i][j][k]);
    end;
 writeln(ans);
 close(input);close(output);
end.
