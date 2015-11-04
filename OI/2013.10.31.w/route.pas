var f:array[0..101,0..101,0..1023] of longint;
    t:array[0..101,0..101,0..1023] of boolean;
    a,b:array[1..100,1..100] of longint;
    fx:array[1..4] of longint=(1,0,-1,0);
    fy:array[1..4] of longint=(0,1,0,-1);
    jd:array[1..10,1..2] of longint;
    d1,d2,d3:array[1..10000000] of longint;
    ff,p,n,m,i,j,k,ans,oo,x,y,z,xx,yy,zz:longint;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

function pan(x,y:longint):boolean;
begin
 if x<=0 then exit(false);
 if x>n then exit(false);
 if y<=0 then exit(false);
 if y>m then exit(false);
 exit(true);
end;
begin
 assign(input,'route.in');reset(input);
 assign(output,'route.out');rewrite(output);
 read(n,m);
 for i:=1 to n do
  for j:=1 to m do
   read(a[i][j]);
 read(k);
 fillchar(b,sizeof(b),false);
 for i:=1 to k do begin
  read(jd[i][1],jd[i][2]);
  b[jd[i][1]][jd[i][2]]:=i;
 end;

 oo:=1<<k-1;
 ff:=1;
 p:=1;
 fillchar(f,sizeof(f),63);
 d1[1]:=1;
 d2[1]:=1;
 if b[1][1]<>0 then d3[1]:=1<<(b[1][1]-1)
 else d3[1]:=0;
 f[1][1][d3[1]]:=0;
 fillchar(t,sizeof(t),true);
 t[1][1][d3[1]]:=false;
 repeat
  x:=d1[ff];y:=d2[ff];z:=d3[ff];
  for i:=1 to n do begin
   xx:=x+fx[i];
   yy:=y+fy[i];
   if pan(xx,yy) then begin
    if b[xx][yy]<>0 then zz:=z or 1<<(b[xx][yy]-1)
                    else zz:=z;
    if f[x][y][z]+sqr(a[x][y]-a[xx][yy])+1<f[xx][yy][zz] then begin
     f[xx][yy][zz]:=f[x][y][z]+sqr(a[x][y]-a[xx][yy])+1;
     if t[xx][yy][zz] then begin
      inc(p);
      t[xx][yy][zz]:=false;
      d1[p]:=xx;d2[p]:=yy;d3[p]:=zz;
     end;
    end;
   end;
  end;
  t[x][y][z]:=true;
  inc(ff);
 until ff>p;
 ans:=maxlongint;
 for i:=1 to k do
  ans:=min(ans,f[jd[i][1]][jd[i][2]][oo]);
 writeln(ans);
 close(input);close(output);
end.
