var fx:array[1..4] of longint=(1,0,-1,0);
    fy:array[1..4] of longint=(0,1,0,-1);
    t:array[0..101,0..101,0..100] of boolean;
    d:array[1..4,1..1000010] of longint;
    a,b:array[0..101,0..101] of longint;
    n,m,i,j,k,kk,xx,yy,sx,sy,ex,ey,ans,f,p:longint;
    ch:char;
    ok:boolean;
begin
 assign(input,'snail.in');reset(input);
 assign(output,'snail.out');rewrite(output);
 readln(n,m,sx,sy,ex,ey,k);
 for i:=1 to n do begin
  for j:=1 to m do begin
   read(ch);
   a[i][j]:=ord(ch)-48;
  end;
  readln;
 end;
 fillchar(t,sizeof(t),false);
 for i:=1 to n do
  for j:=1 to m do
   for f:=0 to k do t[i][j][f]:=true;
 f:=1;p:=1;
 fillchar(b,sizeof(b),63);
 d[1][1]:=sx;
 d[2][1]:=sy;
 d[3][1]:=0;
 d[4][1]:=0;
 ok:=false;
 repeat
  for i:=1 to 4 do begin
   xx:=d[1][f]+fx[i];
   yy:=d[2][f]+fy[i];
   kk:=d[3][f];
   if a[xx][yy]=1 then inc(kk);
   if t[xx][yy][kk] then
    if (b[xx][yy]>=kk)and(kk<=k) then begin
     b[xx][yy]:=kk;
     inc(p);
     d[1][p]:=xx;
     d[2][p]:=yy;
     d[3][p]:=kk;
     d[4][p]:=d[4][f]+1;
     t[xx][yy][kk]:=false;
     if (xx=ex)and(yy=ey) then begin
      ok:=true;
      ans:=d[4][p];
      break;
     end;
    end;
  end;
  if ok then break;
  inc(f);
 until f>p;
 writeln(ans);
 close(input);close(output);
end.
