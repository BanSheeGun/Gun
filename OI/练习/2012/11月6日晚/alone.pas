var a:array[1..9,1..9] of longint;
    d:array[1..2,1..81] of longint;
    ch:char;
    h,l,g:array[1..9,1..9] of boolean;
    t:boolean;
    i,j,n,k:longint;
function gg(x,y:longint):longint;
begin
 exit(((x+2) div 3-1)*3+(y+2) div 3);
end;

procedure dfs(k:longint);
var i,sg,x,y:longint;
begin
 sg:=gg(d[1][k],d[2][k]);
 x:=d[1][k];y:=d[2][k];
 for i:=1 to 9 do
  if h[x][i] then
  if l[y][i] then
  if g[sg][i] then begin
   a[x][y]:=i;
   h[x][i]:=false;
   l[y][i]:=false;
   g[sg][i]:=false;

   if k=n then begin
    t:=true;
    exit;
   end
   else begin
    dfs(k+1);
    if t then exit;
   end;

   h[x][i]:=true;
   l[y][i]:=true;
   g[sg][i]:=true;
  end;
end;

begin
 assign(input,'alone.in');reset(input);
 assign(output,'alone.out');rewrite(output);
 fillchar(h,sizeof(h),true);
 fillchar(l,sizeof(l),true);
 fillchar(g,sizeof(g),true);
 n:=0;
 for i:=1 to 9 do begin
  for j:=1 to 9 do begin
   read(ch);
   if ch='0' then begin
    inc(n);
    d[1][n]:=i;
    d[2][n]:=j;
   end
   else begin
    a[i][j]:=ord(ch)-48;
    h[i][a[i][j]]:=false;
    l[j][a[i][j]]:=false;
    g[gg(i,j)][a[i][j]]:=false;
   end;
  end;
  readln;
 end;

 t:=false;
 dfs(1);

 for i:=1 to 9 do begin
  for j:=1 to 9 do write(a[i][j]);
  writeln;
 end;
 close(input);close(output);
end.
