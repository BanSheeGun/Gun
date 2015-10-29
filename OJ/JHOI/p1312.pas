var w:array[0..200,1..2] of longint;
    f:array[1..200,1..200] of longint;
    j,n,i,ans,k:longint;

function ff(l,r:longint):longint;
var i,k:longint;
begin
 if f[l][r]<>0 then exit(f[l][r]);
 if l=r then exit(0);

 for i:=l to r-1 do
  begin
   k:=ff(l,i)+ff(i+1,r)+w[l][1]*w[r][2]*w[i][2];
   if k>f[l][r] then f[l][r]:=k;
  end;

 exit(f[l][r]);
end;


begin
 read(n);
 for i:=1 to n do
  begin
   read(w[i][1]);
   w[i-1][2]:=w[i][1];
   w[i+n][1]:=w[i][1];
   w[i+n-1][2]:=w[i-1][2];
  end;
 w[n*2][2]:=w[i][1];

 fillchar(f,sizeof(f),0);
 ans:=-maxlongint;
 for i:=1 to n do
  begin
   k:=ff(i,i+n-1);
   if k>ans then ans:=k;
  end;

 writeln(ans);
end.
