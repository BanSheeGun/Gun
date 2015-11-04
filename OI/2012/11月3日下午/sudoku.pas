type cw=record
      x,y:longint;
     end;
var w:array[1..9,1..9] of longint=(
    (6,6,6,6,6,6,6,6,6),
    (6,7,7,7,7,7,7,7,6),
    (6,7,8,8,8,8,8,7,6),
    (6,7,8,9,9,9,8,7,6),
    (6,7,8,9,10,9,8,7,6),
    (6,7,8,9,9,9,8,7,6),
    (6,7,8,8,8,8,8,7,6),
    (6,7,7,7,7,7,7,7,6),
    (6,6,6,6,6,6,6,6,6));
    h,l,g:array[1..9,1..9] of boolean;
    d:array[1..81] of cw;
    k,ans,i,j,n,ks:longint;
    t:boolean;
function sg(x,y:longint):longint;
begin
 exit(((x+2) div 3-1)*3+(y+2) div 3);
end;
procedure dfs(k,s:longint);
var i:longint;
begin
 if (ans-s)/(k)>75 then exit;
 for i:=1 to 9 do
  if h[d[k].x][i] then
  if l[d[k].y][i] then
  if g[sg(d[k].x,d[k].y)][i] then begin
   if k=1 then begin
    t:=true;
    if s+i*w[d[k].x][d[k].y]>ans then ans:=s+i*w[d[k].x][d[k].y];
   end
   else begin
    h[d[k].x][i]:=false;
    l[d[k].y][i]:=false;
    g[sg(d[k].x,d[k].y)][i]:=false;
    dfs(k-1,s+i*w[d[k].x][d[k].y]);
    h[d[k].x][i]:=true;
    l[d[k].y][i]:=true;
    g[sg(d[k].x,d[k].y)][i]:=true;
   end;
  end;
end;
begin
 assign(input,'sudoku.in');reset(input);
 assign(output,'sudoku.out');rewrite(output);
 n:=0;
 fillchar(h,sizeof(h),true);
 fillchar(l,sizeof(l),true);
 fillchar(g,sizeof(g),true);
 for i:=1 to 9 do
  for j:=1 to 9 do begin
   read(k);
   if k=0 then begin
    inc(n);
    d[n].x:=i;d[n].y:=j;
   end
   else begin
    h[i][k]:=false;
    l[j][k]:=false;
    g[sg(i,j)][k]:=false;
    ans:=ans+w[i][j]*k;
   end;
 end;
 t:=false;
 dfs(n,ans);
 if t then writeln(ans)
      else writeln(-1);
 close(input);close(output);
end.
