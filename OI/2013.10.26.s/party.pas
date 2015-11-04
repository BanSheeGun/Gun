var a,g:array[1..3000,1..3000] of longint;
    d,ans:array[1..9000] of longint;
    t:array[1..3000] of boolean;
    top,i,n,m,oo,x,y,z:longint;
procedure dd(x:longint);
var f,p,i:longint;
begin
 fillchar(t,sizeof(t),true);
 f:=1;p:=1;
 d[1]:=x;
 g[x][x]:=0;
 repeat
  for i:=1 to n do
  if g[x][d[f]]+a[d[f]][i]<g[x][i] then begin
   g[x][i]:=g[x][d[f]]+a[d[f]][i];
   if not t[i] then begin
    inc(p);
    d[p]:=i;
   end;
  end;
  t[d[f]]:=true;
  inc(f);
 until f>p;
end;


function check(k:longint):boolean;
var i,j:longint;
begin
 for i:=1 to n do
  if g[k][i]<>oo then begin
  for j:=1 to 3 do
   if a[j][i]+g[k][j]=g[k][i] then exit(false);
 end;
 exit(true);
end;

begin
 assign(output,'party.out');rewrite(output);
 assign(input,'party.in');reset(input);

 fillchar(a,sizeof(a),63);oo:=a[1][1];
 read(n,m);
 for i:=1 to m do begin
  read(x,y,z);
  a[x][y]:=z;
  a[y][x]:=z;
 end;
 g:=a;
 dd(1);
 dd(2);
 dd(3);

 top:=0;
 for i:=1 to n do
  if check(i) then begin
   inc(top);
   ans[top]:=i;
  end;

 if top=0 then writeln('impossible')
 else begin
  writeln(top);
  for i:=1 to top-1 do write(ans[i],' ');
  writeln(ans[top]);
 end;
 close(input);close(output);
end.
