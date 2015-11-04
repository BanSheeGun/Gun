var f:array[1..200,1..200] of int64;
    a,l,r:array[1..200] of longint;
    ans:int64;
    n,i,j,k:longint;
function max(a,b:int64):int64;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'energy.in');reset(input);
 assign(output,'energy.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(a[i]);
 for i:=1 to n do begin
  l[i]:=a[i];
  r[i]:=a[i+1];
 end;
 r[n]:=a[1];

 for i:=n+1 to 2*n do begin
  l[i]:=l[i-n];
  r[i]:=r[i-n];
 end;

 fillchar(f,sizeof(f),0);
 for i:=1 to 2*n-1 do f[i][i+1]:=l[i]*r[i]*r[i+1];

 for i:=3 to n do begin
  for j:=1 to 2*n-i+1 do
   for k:=j to j+i-2 do
    f[j,i+j-1]:=max(f[j,i+j-1],f[j,k]+f[k+1,i+j-1]+l[j]*r[k]*r[j+i-1]);
 end;
 ans:=0;
 for i:=1 to n do
  ans:=max(ans,f[i,i+n-1]);
 writeln(ans);
 close(input);close(output);
end.
