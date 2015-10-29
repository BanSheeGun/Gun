type cw=record
      x,y:longint;
     end;
var jh:array[0..501,0..501] of cw;
    tu:array[0..501,0..501] of longint;
    fx:array[1..4] of longint=(1,0,0,-1);
    fy:array[1..4] of longint=(0,1,-1,0);
    ans,c,x,y,x1,y1,n,m,i,j,k,a1:longint;
    k1,k2:cw;
function find(x,y:longint):cw;
begin
 if (jh[x][y].x<>x)or(jh[x][y].y<>y) then
  jh[x][y]:=find(jh[x][y].x,jh[x][y].y);
 exit(jh[x][y]);
end;
begin
 assign(input,'blocks.in');reset(input);
 assign(output,'blocks.out');rewrite(output);
 read(n,m);
 ans:=0;
 for k:=1 to m do begin
  read(c,x,y);
  inc(ans);
  a1:=0;
  tu[x][y]:=c+1;
  jh[x][y].x:=x;
  jh[x][y].y:=y;

  for i:=1 to 4 do begin
   x1:=x+fx[i];
   y1:=y+fy[i];
   if tu[x1][y1]=tu[x][y] then begin
    k1:=find(x,y);
    k2:=find(x1,y1);
    if (k1.x<>k2.x)or(k1.y<>k2.y) then begin
    inc(a1);
    jh[k1.x][k1.y]:=jh[k2.x][k2.y];
    end;
   end;
  end;
  dec(ans,a1);
  writeln(ans);
 end;
 close(output);close(input);
end.
