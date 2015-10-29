var f:array[1..100,1..100] of int64;
    a:array[1..100,1..2] of longint;
    i,n:longint;
function min(a,b:int64):int64;
begin
 if a>b then exit(b);
 exit(a);
end;
function d(l,r:longint):int64;
var i:longint;
begin
 if f[l][r]<>0 then exit(f[l][r]);
 if l=r then exit(0);
 f[l][r]:=maxlongint;
 for i:=l to r-1 do
  f[l][r]:=min(f[l][r],d(l,i)+d(i+1,r)+a[l][1]*a[i][2]*a[r][2]);

 exit(f[l][r]);
end;
begin
 assign(input,'matrix.in');reset(input);
 assign(output,'matrix.out');rewrite(output);
 fillchar(f,sizeof(f),0);
 read(n);
 for i:=1 to n do begin
  read(a[i][1],a[i][2]);
 end;

 for i:=1 to n-1 do
  f[i][i+1]:=a[i][1]*a[i][2]*a[i+1][2];

 writeln(d(1,n));
 close(input);close(output);
end.
