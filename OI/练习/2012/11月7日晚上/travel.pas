var t:array[0..51,0..51] of boolean;
    n,m,ans,i:longint;
    fx:array[1..4] of longint=(1,0,-1,0);
    fy:array[1..4] of longint=(0,1,0,-1);
procedure dfs(x,y,deep:longint);
var i:longint;
begin
 if (x=n)and(y=1) then begin
  if deep=n*m then inc(ans)
  else exit;
 end
 else begin
  if (not t[x][y-1])and(not t[x][y+1])and(t[x+1][y])and(t[x-1][y]) then exit;
  if ( t[x][y-1])and( t[x][y+1])and(not t[x+1][y])and(not t[x-1][y]) then exit;
  for i:=1 to 4 do
   if (x+fx[i]>0)and(x+fx[i]<=n)and(y+fy[i]>0)and(y+fy[i]<=m) then
    if t[x+fx[i]][y+fy[i]] then begin
     t[x+fx[i]][y+fy[i]]:=false;
     dfs(x+fx[i],y+fy[i],deep+1);
     t[x+fx[i]][y+fy[i]]:=true;
    end;
 end;
end;
procedure q(k:longint);
var i:longint;
begin
 ans:=1;
 for i:=1 to k do
  ans:=ans *2;
end;
begin
 assign(input,'travel.in');reset(input);
 assign(output,'travel.out');rewrite(output);
 fillchar(t,sizeof(t),true);
 read(n,m);
 for i:=0 to n+1 do begin
  t[i][0]:=false;
  t[i][m+1]:=false;
 end;
 for i:=0 to m+1 do begin
  t[0][i]:=false;
  t[n+1][i]:=false;
 end;
 ans:=0;
 t[1][1]:=false;
 if (n mod 2=1)and(m mod 2=0) then ans:=0
  else if (m=3)and(n<>1) then q(n-2)
   else if (n=3) then q(m div 2)
 else dfs(1,1,1);
 writeln(ans);
 close(input);close(output);
end.
