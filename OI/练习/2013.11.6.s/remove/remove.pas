var a:array[1..100] of longint;
    f:array[1..100,1..100] of int64;
    i,j,l,n:longint;
    tmp:int64;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function dj(l,r:longint):int64;
begin
 if l=r then exit(a[l]);
 exit(abs(a[l]-a[r]) * (r - l + 1));
end;
begin
 assign(input,'remove.in');reset(input);
 assign(output,'remove.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(a[i]);

 fillchar(f,sizeof(f),0);
 for i:=1 to n do f[i][i]:=a[i];
 for l:=2 to n do
  for i:=1 to n-l+1 do begin
   f[i][i+l-1]:=dj(i,i+l-1);
   for j:=i+1 to l+i-1 do begin
    tmp:=dj(j+1,l+i-1);
    f[i][i+l-1]:=max(f[i][i+l-1],f[i][j]+tmp);
    tmp:=dj(i,j-1);
    f[i][i+l-1]:=max(f[i][i+l-1],f[j][i+l-1]+tmp);
   end;
  end;
 writeln(f[1][n]);
 close(input);close(output);
end.
