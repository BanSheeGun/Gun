program ppp;
var a:array[1..15] of longint;
    f:array[1..15,1..15,0..14] of int64;
    pan:array[1..15,1..15,0..14] of boolean;
    n,i,j,k:longint;
function fck(x,y,z:longint):int64;
var i,l,mid:longint;
    k:int64;
begin
 fck:=0;
 if (f[x,y,z]<>0)or(z=0)or(pan[x][y][z]) then exit(f[x,y,z]);
 for mid:=x to  y-1 do
  for l:=0 to z-1 do
  if(l<(mid-x+1))and(l<(y-mid+1)) then
  begin
   k:=fck(x,mid,l)*fck(mid+1,y,z-1-l);
   if k>fck then fck:=k;
  end;
 for mid:=x to  y-1 do
  for l:=0 to z do
  if(l<(mid-x+1))and(l<(y-mid+1)) then
  begin
   k:=fck(x,mid,l)+fck(mid+1,y,z-l);
   if k>fck then fck:=k;
  end;

 f[x][y][z]:=fck; pan[x][y][z]:=true;
end;
begin
 assign(input,'bigexp.in');reset(input);
 assign(output,'bigexp.out');rewrite(output);
 read(n,k);
 fillchar(f,sizeof(f),0);
 fillchar(pan,sizeof(pan),false);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do f[i][i][0]:=a[i];
 for i:=1 to n do
  for j:=i+1 to n do
   f[i][j][0]:=f[i][j-1][0]+a[j];
 writeln(fck(1,n,k));
 close(input);close(output);
end.
