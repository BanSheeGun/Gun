var max,min:array[1..100,1..100] of longint;
    n,s,k,i,j,z:longint;
    fx:array[1..2] of longint=(-1,0);
    fy:array[1..2] of longint=(0,-1);
procedure dmax(x,y:longint);
var ii:longint;
begin
 if max[x][y]<z then begin
  max[x][y]:=z;
  for ii:=1 to 2 do
   if (x+fx[ii]>0)and(y+fy[ii]>0)and(i-x-fx[ii]<s)and(j-y-fy[ii]<s) then begin
   dmax(x+fx[ii],y+fy[ii]);
  end;
 end;
end;
procedure dmin(x,y:longint);
var ii:longint;
begin
 if min[x][y]>z then begin
  min[x][y]:=z;
  for ii:=1 to 2 do
   if (x+fx[ii]>0)and(y+fy[ii]>0)and(i-x-fx[ii]<s)and(j-y-fy[ii]<s) then begin
   dmin(x+fx[ii],y+fy[ii]);
  end;
 end;
end;
begin
 assign(input,'altitude.in');reset(input);
 assign(output,'altitude.out');rewrite(output);
 fillchar(min,sizeof(min),63);

 read(n,s,k);
 for i:=1 to n do
  for j:=1 to n do begin
   read(z);
   max[i][j]:=-maxlongint;
   dmax(i,j);
   dmin(i,j);
  end;

 for n:=1 to k do begin
  read(i,j);
  writeln(max[i][j]-min[i][j]);
 end;
 close(input);close(output);
end.
