var s:string;
    g:array[1..40,1..40] of qword;
    f:array[1..40,1..40,0..6] of qword;
    n,k,i,j:longint;
function ff(l,r,k:longint):qword;
var i,j,z:longint;
begin
 if f[l][r][k]<>0 then exit(f[l][r][k]);
 if k=0 then
  begin
   f[l][r][k]:=g[l][r];
   exit(f[l][r][k]);
  end;

  for j:=1 to k do
   for i:=1 to r-1 do
    begin
     z:=ff(l,i,j-1)*ff(i+1,r,k-j);
     if z>f[l][r][k] then f[l][r][k]:=z;
    end;
  exit(f[l][r][k]);
end;

begin
 readln(n,k);
 readln(s);

 fillchar(g,sizeof(g),0);

 for i:=1 to n do
  g[i][i]:=ord(s[i])-48;

 for i:=1 to  n do
  for j:=i+1 to n do
   g[i][j]:=g[i][j-1]*10+ord(s[j])-48;

 fillchar(f,sizeof(f),0);
 writeln(ff(1,n,k));
end.
