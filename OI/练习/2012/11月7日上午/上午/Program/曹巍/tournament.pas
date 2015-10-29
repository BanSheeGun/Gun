var head:array[1..50] of longint;
    e,next:array[1..1400] of longint;
    a:array[1..50,1..50] of boolean;
    d:array[1..1000] of longint;
    tt:array[1..50] of boolean;
    t:boolean;
    x,y,n,i,j,f,p,k:longint;
procedure bfs;
begin
 t:=false;
 f:=1;p:=1;
 d[1]:=x;
 tt[x]:=false;
 repeat
  k:=head[d[f]];
  while k<>0 do begin
   if tt[e[k]] then begin
    inc(p);
    d[p]:=e[k];
    tt[e[k]]:=false;
    if e[k]=y then begin t:=true; exit;end;
   end;
   k:=next[k];
  end;
  inc(f);
 until f>p;
end;
begin
 assign(input,'tournament.in');reset(input);
 assign(output,'tournament.out');rewrite(output);
 read(n);
 fillchar(a,sizeof(a),false);
 for i:=1 to n*(n-1) div 2 -1 do begin
  read(x,y);
  a[x][y]:=true;
  a[y][x]:=true;
  e[i]:=y;
  next[i]:=head[x];
  head[x]:=i;
 end;

 for x:=n downto 1 do
  begin
  for y:=n downto 1 do
   if x<>y then
    if not a[x][y] then break;
    if not a[x][y] then break;
  end;
 fillchar(tt,sizeof(tt),true);
 bfs;

 if t then writeln(x,' ',y)
      else writeln(y,' ',x);
 close(input);close(output);
end.
