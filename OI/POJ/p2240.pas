var name:array[1..300] of string;
    f:array[1..35,1..35] of extended;
    l:extended;
    n,i,casea,x,y,m,j,k:longint;
    ok:boolean;
    st:string;
function find(st:string):longint;
var i:longint;
begin
 for i:=1 to n do
  if st=name[i] then exit(i);
end;

function max(a,b:extended):extended;
begin
 if a>b then exit(a);
 exit(b);
end;

begin
 readln(n);casea:=1;
 while n<>0 do begin
  for i:=1 to n do
   for j:=1 to n do
    f[i][j]:=0;
  for i:=1 to n do f[i][i]:=1;
  for i:=1 to n do
   readln(name[i]);
  readln(m);
  for i:=1 to m do begin
   readln(st);
   x:=find(copy(st,1,pos(' ',st)-1));
   delete(st,1,pos(' ',st));
   val(copy(st,1,pos(' ',st)-1),l);
   delete(st,1,pos(' ',st));
   y:=find(st);
   f[x][y]:=l;
  end;

  ok:=false;
  for k:=1 to n do
   for i:=1 to n do
    if i<>k then
    for j:=1 to n do
     if (k<>j) then
      f[i][j]:=max(f[i][j],f[i][k]*f[k][j]);

  for i:=1 to n do
   if f[i][i]>1 then ok:=true;


  if ok then writeln('Case ',casea,': Yes')
  else writeln('Case ',casea,': No');
  readln;
  readln(n);
  inc(casea);
 end;
end.
