var f:array[1..100,1..100] of longint;
    n,i,j,k,x,y,ans,aa,oo,ans2:longint;
    ok,ok1:boolean;

function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

procedure check(x:longint);
var i:longint;
begin
 ok1:=false;
 for i:=1 to n do begin
  if f[x][i]=oo then exit;
  aa:=max(aa,f[x][i]);
 end;
 ok1:=true;
end;

begin
 read(n);
 while n<>0 do begin
  fillchar(f,sizeof(f),63);
  oo:=f[1][1];
  for i:=1 to n do begin
   f[i][i]:=0;
   read(k);
   for j:=1 to k do begin
     read(x,y);
     f[i][x]:=y;
   end;
  end;

  for k:=1 to n do
   for i:=1 to n do
    if i<>k then
     for j:=1 to n do
      if (j<>i)and(j<>k) then
       f[i][j]:=min(f[i][j],f[i][k]+f[k][j]);

  ok:=false; ans:=maxlongint;
  for i:=1 to n do begin
   aa:=0;
   check(i);
   if ok1 then begin
    if aa<ans then begin
     ans:=aa;
     ans2:=i;
    end;
    ok:=true;
   end;
  end;
  if ok then writeln(ans2,' ',ans)
  else writeln('disjoint');
  read(n);
 end;
end.
