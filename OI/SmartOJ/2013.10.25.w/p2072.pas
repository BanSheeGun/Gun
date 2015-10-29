var a:array[1..300,1..300] of longint;
    b:array[1..300,1..300] of boolean;
    n,i,j,k,x,y,z,sum,s,t,s1,top:longint;
    d:array[1..300] of longint;
    ok:boolean;
    p:array[1..300] of boolean;
    f,r,max,min:longint;
procedure dfs(z,su:longint);
var i:longint;
begin
 p[z]:=false;

 if (z=t)and(su=sum) then begin ok:=true;exit;end;
 inc(top);
 for i:=1 to n do
  if (b[z][i])and(p[i]) then
  begin
  if ok then exit;
  d[top]:=i;
  dfs(i,su+a[z][i]);
  end;
 if ok then exit;
 dec(top);
end;
procedure work(l,r:longint);
var i,j,min:longint;
begin
 max:=-maxlongint;
  for j:=1 to n do
   begin
    min:=maxlongint;
     for i:=l to r do
       if a[d[i]][j]<min then min:=a[d[i]][j];
     if max<min then max:=min;
   end;
end;
begin
 read(n,s1);
 fillchar(a,sizeof(a),63);
 fillchar(b,sizeof(b),false);
 for i:=1 to n do a[i][i]:=0;
 for i:=1 to n-1 do
  begin
   read(x,y,z);
   a[x][y]:=z;
   a[y][x]:=z;
   b[x][y]:=true;
   b[y][x]:=true;
  end;
 for k:=1 to n do
  for i:=1 to n do
   if i<>k then
     for j:=1 to n do
       if i<>j then
         if j<>k then
           if a[i][k]+a[k][j]<a[i][j] then
             begin
               a[i][j]:=a[i][k]+a[k][j];
               a[j][i]:=a[i][j];
             end;
 fillchar(p,sizeof(p),true);

 sum:=0;
 for i:=1 to n do
  for j:=i+1 to n do
   if a[i][j]>sum then
       begin
        sum:=a[i][j];
        s:=i;
        t:=j;
       end;
   d[1]:=s;
  ok:=false; top:=1;
  dfs(s,0);
 min:=maxlongint;
 f:=1;r:=1;sum:=0;
 for f:=1 to top do
  begin
   sum:=0;
   r:=f;
   while (r<top)and(sum+a[d[r]][d[r+1]]<=s1) do
    begin
     sum:=sum+a[d[r]][d[r+1]];
     inc(r);
    end;
   work(f,r);
   if max<min then min:=max;
  end;
 writeln(min);
end.
