var
  n,i,j:longint;
  map:array[1..50,1..50]of boolean;
  x,y:array[1..1000]of longint;
procedure work(x,y:longint);
var
  i:longint;
begin
  randomize;
  i:=random(10);
  if odd(i) then writeln(x,' ',y)
            else writeln(y,' ',x);
end;
begin
  assign(input,'tournament.in');
  reset(input);
  assign(output,'tournament.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      map[i,j]:=true;
  for i:=1 to n*(n-1) div 2 -1 do
    begin
      readln(x[i],y[i]);
      map[x[i],y[i]]:=false;
      map[y[i],x[i]]:=false;
      map[i,i]:=false;
    end;
  for i:=1 to n do
    for j:=1 to n do
      if map[i,j]=true then work(i,j);
  close(input);
  close(output);
end.