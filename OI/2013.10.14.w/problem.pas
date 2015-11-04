var fx:array[1..8] of longint=(1,1,2,2,-1,-1,-2,-2);
    fy:array[1..8] of longint=(2,-2,1,-1,2,-2,1,-1);
    aa:array[-1..28,-1..28] of longint;
    a:array[1..2000,1..2000] of longint;
    t:array[1..10000] of boolean;
    c:array[1..10000] of longint;
    ch:char;
    n,m,x,y,i,j,ans,k:longint;

function find(u:longint):boolean;
var i:longint;
begin
 for i:=1 to m do
 if (a[u][i]=1)and(t[i]=false) then begin
  t[i]:=true;
  if (c[i]=0)or(find(c[i])) then begin
   c[i]:=u;
   exit(true);
  end;
 end;
 exit(false);
end;

function pan(x,y,k:longint):boolean;
begin
 if aa[x+fx[k]][y+fy[k]]<>0 then exit(true);
 exit(false);
end;
begin
 assign(input,'problem.in');reset(input);
 assign(output,'problem.out');rewrite(output);
 fillchar(a,sizeof(a),0);
 readln(n,m);
 for i:=1 to m do begin
  read(ch);
  readln(y);
  x:=ord(ch)-ord('A')+1;
  aa[x][y]:=i;
 end;

 ans:=0;
 for i:=1 to n do
  for j:=1 to n do
   if aa[i][j]<>0 then
    for k:=1 to 8 do
     if pan(i,j,k) then begin
     x:=i+fx[k];y:=j+fy[k];
     a[aa[i][j]][aa[x][y]]:=1;
     a[aa[x][y]][aa[i][j]]:=1;
    end;

 for i:=1 to m do begin
  fillchar(t,sizeof(t),false);
  if find(i) then inc(ans);
 end;
 writeln(ans div 2);
 close(input);close(output);
end.
