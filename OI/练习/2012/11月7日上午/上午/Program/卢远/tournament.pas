var con:array[1..100]of longint;
    map:array[1..100,1..100]of boolean;
    vis:array[1..100]of boolean;
    x,y:array[1..5000]of longint;
    n,num,i,xi,yi,j:longint;
    t:boolean;

procedure search(now:longint);
var i:longint;
begin
  if now=yi then begin t:=true;exit;end;
  for i:=1 to n do
   if (not vis[i])and(map[now,i]) then
    begin
     vis[i]:=true;
     search(i);
     if t then exit;
     vis[i]:=false;
    end;
end;

begin
 assign(input,'tournament.in');reset(input);
 assign(output,'tournament.out');rewrite(output);
  read(n);
  fillchar(con,sizeof(con),0);
  fillchar(map,sizeof(map),0);
  num:=n*(n-1)div 2;
  for i:=1 to num-1 do
   begin
    read(x[i],y[i]);
    inc(con[x[i]]);
    inc(con[y[i]]);
    map[x[i],y[i]]:=true;
   end;
  for i:=1 to n do
   if con[i]<>n-1 then
    begin
     xi:=i;
     break;
    end;
  for j:=i+1 to n do
   if con[j]<>n-1 then
    begin
     yi:=j;
     break;
    end;
  t:=false;
  fillchar(vis,sizeof(vis),0);
  search(xi);
  if t then writeln(xi,' ',yi) else writeln(yi,' ',xi);
 close(input);close(output);
end.