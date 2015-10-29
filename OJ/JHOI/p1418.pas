var ff:array[1..50,1..50,1..50,1..50] of longint;
    a:array[1..50,1..50] of longint;
    n,m,i,j:longint;
function pan(x,y:longint):boolean;
begin
 if x<1 then exit(false);
 if y<1 then exit(false);
 if x>n then exit(false);
 if y>m then exit(false);
 exit(true);
end;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function f(x1,y1,x2,y2:longint):longint;
begin
 if (not pan(x1,y1))or(not pan(x2,y2)) then exit(-maxlongint);
 if ff[x1][y1][x2][y2]<>0 then exit(ff[x1][y1][x2][y2]);
 if (x1=1)and(x2=1)and(y1=1)and(y2=1) then
  begin
    ff[x1][y1][x2][y2]:=-a[1][1];
  end
  else begin
 if (x1=n)and(x2=m)and(y1=n)and(y2=m) then
  begin
    ff[x1][y1][x2][y2]:=a[n][m];
    exit(a[n][m]);
  end else

 if (x1=x2)and(y1=y2) then
  begin
   ff[x1][y1][x2][y2]:=-maxlongint;
   exit(-maxlongint);
  end;
  end;
 ff[x1][y1][x2][y2]:=max(ff[x1][y1][x2][y2],f(x1+1,y1,x2+1,y2));
 ff[x1][y1][x2][y2]:=max(ff[x1][y1][x2][y2],f(x1+1,y1,x2,y2+1));
 ff[x1][y1][x2][y2]:=max(ff[x1][y1][x2][y2],f(x1,y1+1,x2,y2+1));
 ff[x1][y1][x2][y2]:=max(ff[x1][y1][x2][y2],f(x1,y1+1,x2+1,y2));
 ff[x1][y1][x2][y2]:=ff[x1][y1][x2][y2]+a[x1][y1]+a[x2][y2];
 exit(ff[x1][y1][x2][y2]);
end;
begin
 read(n,m);
 for i:=1 to n do
  for j:=1 to m do
   begin
    read(a[i][j]);
   end;
  writeln(f(1,1,1,1));
end.
