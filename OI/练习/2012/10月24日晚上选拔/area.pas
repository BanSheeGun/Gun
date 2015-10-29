var a:array[1..40,0..41] of char;
    n,m,sum,i,j,s:longint;
function ps(x,y:longint):boolean;
var i:longint;
begin
 for i:=1 to x do
  if a[i][y]='*' then exit(true);
 exit(false);
end;
function px(x,y:longint):boolean;
var i:longint;
begin
 for i:=x to n do
  if a[i][y]='*' then exit(true);
 exit(false);
end;
function pz(x,y:longint):boolean;
var i:longint;
begin
 for i:=1 to y do
  if a[x][i]='*' then exit(true);
 exit(false);
end;
function py(x,y:longint):boolean;
var i:longint;
begin
 for i:=y to m do
  if a[x][i]='*' then exit(true);
 exit(false);
end;
function p(x,y:longint):boolean;
begin
 p:=true;
 p:=p and ps(x,y) and px(x,y) and pz(x,y) and py(x,y);
end;
begin
 assign(input,'area.in');reset(input);
 assign(output,'area.out');rewrite(output);
 n:=0;s:=0;
 while not eof do begin
  inc(n);m:=0;
  while not eoln do begin
   inc(m);
   read(a[n][m]);
   if a[n][m]='*'then inc(s);
  end;
  readln
 end;
 sum:=0;
 for i:=1 to n do
  for j:=1 to m do
   if p(i,j) then a[i][j]:='*';
 for i:=1 to n do
  for j:=1 to m do
   if a[i][j]='*'then inc(sum);
 writeln(sum-s);
 close(input);close(output);
end.

