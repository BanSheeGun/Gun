const fx:array[1..7] of longint=(1,0,-1,0,0,1,0);
      fy:array[1..7] of longint=(0,1,0,0,-1,0,1);
      fz:array[1..7] of longint=(0,0,0,1,0,0,0);
var q,u:longint;
    a:array[1..2,1..2,1..2] of longint;
    t:array[1..2,1..2,1..2] of boolean;
    ok:boolean;
    x,y,z,x1,y1,z1,i:longint;
begin
 assign(input,'t4.in');reset(input);
 assign(output,'t4.out');rewrite(output);
 read(q);
 for u:=1 to q do begin
  read(a[1][1][1]);
  read(a[1][1][2]);
  read(a[1][2][2]);
  read(a[1][2][1]);
  read(a[2][1][1]);
  read(a[2][1][2]);
  read(a[2][2][2]);
  read(a[2][2][1]);

  x:=1;y:=1;z:=1;
  for i:=1 to 7 do begin
   x1:=x+fx[i];
   y1:=y+fy[i];
   z1:=z+fz[i];
   a[x1][y1][z1]:=a[x1][y1][z1]-a[x][y][z];
   a[x][y][z]:=0;
   x:=x1;y:=y1;z:=z1;
  end;
  if a[x][y][z]=0 then writeln(1)
                  else writeln(0);
 end;
 
 close(input);close(output);
end.