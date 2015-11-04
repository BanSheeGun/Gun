var f:array[1..10,1..10,1..10,1..10] of longint;
    a:array[1..10,1..10] of longint;
    fx:array[1..2] of longint=(1,0);
    fy:array[1..2] of longint=(0,1);
    x,y,z,n:longint;
function p(x,y,i:longint):boolean;
begin
 if x+fx[i]<1 then exit(false);
 if x+fx[i]>n then exit(false);
 if y+fy[i]>n then exit(false);
 if y+fy[i]<1 then exit(false);
 exit(true);
end;
function max(a,b:longint):longint;
begin
 if a>b then exit(a)
        else exit(b);
end;
function d(x1,y1,x2,y2:longint):longint;
var i,j:longint;
begin
 if f[x1][y1][x2][y2]<>0 then exit(f[x1][y1][x2][y2]);
 if (x1=x2)and(y1=y2) then begin
  if (x1=n)and(y1=n) then begin
   f[x1][y1][x2][y2]:=a[x1][y1];exit(f[x1][y1][x2][y2]);
  end;
  if (x1<>1)or(y1<>1) then begin
   f[x1][y1][x2][y2]:=-maxlongint;exit(f[x1][y1][x2][y2]);
  end;
 for i:=1 to 2 do
  if p(x1,y1,i) then
  for j:=1 to 2 do
  if p(x2,y2,j) then
   f[x1][y1][x2][y2]:=max(f[x1][y1][x2][y2],d(x1+fx[i],y1+fy[i],x2+fx[j],y2+fy[j]));
 f[x1][y1][x2][y2]:=f[x1][y1][x2][y2]+a[x1][y1];
 exit(f[x1][y1][x2][y2]);
 end
 else begin
 for i:=1 to 2 do
  if p(x1,y1,i) then
  for j:=1 to 2 do
  if p(x2,y2,j) then
   f[x1][y1][x2][y2]:=max(f[x1][y1][x2][y2],d(x1+fx[i],y1+fy[i],x2+fx[j],y2+fy[j]));
 f[x1][y1][x2][y2]:=f[x1][y1][x2][y2]+a[x1][y1]+a[x2][y2];
 exit(f[x1][y1][x2][y2]);
 end;
end;
begin
 assign(input,'fang.in');reset(input);
 assign(output,'fang.out');rewrite(output);
 read(n);
 read(x,y,z);
 while (x<>0)and(y<>0)and(z<>0) do begin
  a[x][y]:=z;
  read(x,y,z);
 end;

 writeln(d(1,1,1,1));
 close(input);close(output);
end.
