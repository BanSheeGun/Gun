type arr=array[0..200000] of boolean;
var f:array[0..9,0..200000] of int64;
    max,a:array[0..200002] of longint;
    ok:array[0..10] of arr;
    fff:arr;
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
 fillchar(fff,sizeof(fff),false);
 fff[0]:=true;
 read(n,m);
 for i:=1 to n do begin read(a[i]); a[i]:=a[i]+2000; end;
 if m*2>n then writeln('Error!')
 else begin
  f[2][1]:=a[2];
  f[3][1]:=a[3];
  max[2]:=1;
  max[3]:=1;
  ok[3][1]:=true;
  for i:=2 to n-2 do begin
   ok[(i+2) mod 10]:=fff;
   for j:=0 to max[i] do begin
    if ok[(i+1) mod 10][j]=false then begin
     ok[(i+1) mod 10][j]:=true;
     f[(i+1) mod 10][j]:=f[i mod 10][j];
     max[i+2]:=mmm(max[i+1],j);
    end
    else f[(i+1) mod 10][j]:=mmm(f[(i+1) mod 10][j],f[i mod 10][j]);

    if ok[(i+2) mod 10][j+1]=false then begin
     ok[(i+2) mod 10][j+1]:=true;
     f[(i+2) mod 10][j+1]:=f[i mod 10][j]+a[i+2];
     max[i+2]:=mmm(max[i+2],j+1);
    end
    else f[(i+2) mod 10][j]:=mmm(f[(i+1) mod 10][j],f[i mod 10][j]+a[i+2]);
   end;
  end;
  ans:=f[n mod 10][m];
  ok[0]:=fff;
  ok[1]:=fff;
  ok[2]:=fff;
  fillchar(f,sizeof(f),0);
  fillchar(max,sizeof(max),0);
  f[1][1]:=a[1];
  f[2][1]:=a[2];
  max[1]:=1;
  max[2]:=1;
  ok[2][1]:=true;
  for i:=1 to n-3 do begin
   ok[(i+2) mod 10]:=fff;
   for j:=0 to max[i] do begin
    if ok[(i+1) mod 10][j]=false then begin
     ok[(i+1) mod 10][j]:=true;
     f[(i+1) mod 10][j]:=f[i mod 10][j];
     max[i+2]:=mmm(max[i+1],j);
    end
    else f[(i+1) mod 10][j]:=mmm(f[(i+1) mod 10][j],f[i mod 10][j]);

    if ok[(i+2) mod 10][j+1]=false then begin
     ok[(i+2) mod 10][j+1]:=true;
     f[(i+2) mod 10][j+1]:=f[i mod 10][j]+a[i+2];
     max[i+2]:=mmm(max[i+2],j+1);
    end
    else f[(i+2) mod 10][j]:=mmm(f[(i+1) mod 10][j],f[i mod 10][j]+a[i+2]);
   end;
  end;

  if f[(n-1) mod 10][m]>ans then ans:=f[(n-1) mod 10][m];
  writeln(ans);
 end;
 close(input);close(output);
end.
