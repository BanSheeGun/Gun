const maxn=1023;
var p:array[1..10,1..10,0..maxn] of boolean;
    f:array[1..10,1..10,0..maxn] of longint;
    a:array[1..10,1..10] of longint;
    fx:array[1..2] of longint=(1,0);
    fy:array[1..2] of longint=(0,1);
    d:array[1..100000,1..3] of longint;
    xx,yy,x,y,z,zz,i,j,ff,pp:longint;
begin
 fillchar(p,sizeof(p),true);
 fillchar(f,sizeof(f),63);
 for i:=1 to 10 do
  for j:=1 to 10 do begin
   read(a[i][j]);
  end;

 d[1][1]:=1;
 d[1][2]:=1;
 d[1][3]:=1<<a[1][1];
 f[1][1][d[1][3]]:=a[1][1];
 p[1][1][d[1][3]]:=false;
 ff:=1;pp:=1;
 repeat
  x:=d[ff][1];
  y:=d[ff][2];
  z:=d[ff][3];
  for i:=1 to 2 do begin
   xx:=x+fx[i];
   yy:=y+fy[i];
   if (xx>=1)and(xx<=10)and(yy>=1)and(yy<=10) then begin
    zz:=z or (1<<a[xx][yy]);
    if f[xx][yy][zz]>f[x][y][z]+a[xx][yy] then begin
     f[xx][yy][zz]:=f[x][y][z]+a[xx][yy];
     if p[xx][yy][zz] then begin
      inc(pp);
      d[pp][1]:=xx;
      d[pp][2]:=yy;
      d[pp][3]:=zz;
      p[xx][yy][zz]:=false;
     end;
    end;
   end;
  end;
  p[x][y][z]:=true;
  inc(ff);
 until ff>pp;
 writeln(f[10][10][maxn]);
end.
