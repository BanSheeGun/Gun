var fx:array[1..4] of longint=(1,0,-1,0);
    fy:array[1..4] of longint=(0,1,0,-1);
    a:array[1..100,1..100] of 0..1;
    dx,dy,dl,dd:array[1..2000000] of longint;
    t:array[1..100,1..100,0..100] of boolean;
    i,j,n,m,d,f,p,ans,x,y,l:longint;
    tt:boolean;
procedure init;
var ch:char;
begin
 readln(n,m,d);
 for i:=1 to n do begin
  for j:=1 to m do begin
   read(ch);
   if ch='P' then a[i][j]:=0
             else a[i][j]:=1;
  end;
  readln;
 end;
end;
procedure bfs;
begin
 f:=1;p:=1;
 dx[1]:=1;dy[1]:=1;dd[1]:=0;dl[1]:=0;
 fillchar(t,sizeof(t),true);
 t[1][1][0]:=false;
 repeat
  x:=dx[f];
  y:=dy[f];
  l:=dl[f];
  for i:=1 to 4 do begin
   if (x+fx[i]>=1)and(x+fx[i]<=n) then
   if (y+fy[i]>=1)and(y+fy[i]<=m) then
   if a[x+fx[i]][y+fy[i]]=0 then
   if t[x+fx[i]][y+fy[i]][l] then begin
    inc(p);
    t[x+fx[i]][y+fy[i]][l]:=false;
    dx[p]:=x+fx[i];
    dy[p]:=y+fy[i];
    dl[p]:=l;
    dd[p]:=dd[f]+1;
    if (dx[p]=n)and(dy[p]=m) then begin
     ans:=dd[p];
     tt:=true; exit;
    end;
   end;
  end;


  for j:=1 to d-l do begin
   for i:=1 to 4 do begin
    if (x+fx[i]*j>=1)and(x+fx[i]*j<=n) then
    if (y+fy[i]*j>=1)and(y+fy[i]*j<=m) then
    if a[x+fx[i]*j][y+fy[i]*j]=0 then
    if t[x+fx[i]*j][y+fy[i]*j][l+j] then begin
     inc(p);
     t[x+fx[i]*j][y+fy[i]*j][l+j]:=false;
     dx[p]:=x+fx[i]*j;
     dy[p]:=y+fy[i]*j;
     dl[p]:=l+j;
     dd[p]:=dd[f]+1;
     if (dx[p]=n)and(dy[p]=m) then begin
      ans:=dd[p];
      tt:=true; exit;
     end;
    end;
   end;
  end;

  inc(f);
 until f>p;
end;
begin
 assign(input,'escape.in');reset(input);
 assign(output,'escape.out');rewrite(output);
 init;
 tt:=false;
 bfs;
 if tt then writeln(ans)
      else writeln('impossible');
 close(input);close(output);
end.
