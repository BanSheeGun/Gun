var f:array[-1..9,0..5002] of longint;
    max,a:array[0..200002] of longint;
    n,m,i,j:longint;
    ans:int64;
function mmm(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

begin
 assign(input,'compile.in');reset(input);
 assign(output,'compile.out');rewrite(output);
 read(n,m);
 for i:=1 to n do begin
  read(a[i]);
  a[i]:=a[i]+1000;
 end;
 if m*2>n then writeln('Error!')
 else begin
  f[2][1]:=a[2];
  f[3][1]:=a[3];
  max[2]:=1;
  max[3]:=1;
  for i:=2 to n-1 do begin
   for j:=0 to max[i] do begin
    max[i+1]:=mmm(max[i+1],j);
    f[(i+1) mod 10][j]:=mmm(f[(i+1) mod 10][j],f[i mod 10][j]);
    max[i+2]:=mmm(max[i+2],j+1);
    f[(i+2) mod 10][j+1]:=mmm(f[(i+2) mod 10][j+1],f[i mod 10][j]+a[i+2]);
    f[i mod 10][j]:=0;
   end;
  end;
  ans:=f[n mod 10][m];
  fillchar(f,sizeof(f),0);
  fillchar(max,sizeof(max),0);
  max[1]:=1;
  max[2]:=1;
  f[1][1]:=a[1];
  f[2][1]:=a[2];

  for i:=1 to n-2 do begin
   for j:=0 to max[i] do begin
    max[i+1]:=mmm(max[i+1],j);
    f[(i+1) mod 10][j]:=mmm(f[(i+1) mod 10][j],f[i mod 10][j]);
    max[i+2]:=mmm(max[i+2],j+1);
    f[(i+2) mod 10][j+1]:=mmm(f[(i+2) mod 10][j+1],f[i mod 10][j]+a[i+2]);
    f[i mod 10][j]:=0;
   end;
  end;

  if f[(n-1) mod 10][m]>ans then ans:=f[(n-1) mod 10][m];
  writeln(ans-m*1000);
 end;
 close(input);close(output);
end.
