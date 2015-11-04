var a:array[1..9,1..9] of longint;
    qu,h,l:array[1..9,1..9] of boolean;
    i,j,top,k:longint;
    ch:char;
    d:array[1..2,1..80] of longint;
    ok:boolean;
function qq(x,y:longint):longint;
begin
 qq:=((x-1) div 3)*3+(y+2) div 3;
end;

procedure dfs(k:longint);
var i:longint;
begin
 for i:=1 to 9 do
  if h[d[1][k]][i] then
  if l[d[2][k]][i] then
  if qu[qq(d[1][k],d[2][k])][i] then
  begin
   a[d[1][k]][d[2][k]]:=i;
   h[d[1][k]][i]:=false;
   l[d[2][k]][i]:=false;
   qu[qq(d[1][k],d[2][k])][i]:=false;
   if k=top then begin ok:=true; exit;end
   else dfs(k+1);
   if ok then exit;
   h[d[1][k]][i]:=true;
   l[d[2][k]][i]:=true;
   qu[qq(d[1][k],d[2][k])][i]:=true;
  end;
end;
begin
 assign(input,'sudoku.in');reset(input);
 assign(output,'sudoku.out');rewrite(output);
 top:=0;
 fillchar(qu,sizeof(qu),true);
 fillchar(h,sizeof(h),true);
 fillchar(l,sizeof(l),true);
 for i:=1 to 9 do begin
  for j:=1 to 9 do begin
   read(ch);
   if ch='?' then begin
    inc(top);
    d[1][top]:=i;d[2][top]:=j;
   end
   else begin
    a[i][j]:=ord(ch)-48;
    k:=qq(i,j);
    qu[k][a[i][j]]:=false;
    h[i][a[i][j]]:=false;
    l[j][a[i][j]]:=false;
   end;
  end;
  readln;
 end;
 ok:=false;
 dfs(1);
 for i:=1 to 9 do begin
  for j:=1 to 9 do
   write(a[i][j]);
  writeln;
 end;
 close(input);close(output);
end.
