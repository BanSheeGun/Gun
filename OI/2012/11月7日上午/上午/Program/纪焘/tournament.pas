var n,m,i,j,x,y:longint;
    shen,fu:array[1..50,1..50]of longint;
    num:array[1..50]of longint;
    t:boolean;
begin
assign(input,'tournament.in');reset(input);
assign(output,'tournament.out');rewrite(output);
  read(n);
  m:=n*(n-1)div 2-1;
  for i:=1 to m do
    begin
      read(x,y);
      shen[x,y]:=1;
      fu[y,x]:=1;
      inc(num[x]);
      inc(num[y]);
    end;
  x:=0;
  for i:=1 to n do
    if (num[i]<>n-1)and(x=0) then x:=i
      else if(num[i]<>n-1)and(x<>0) then y:=i;
  t:=false;
  for i:=1 to n do
    if (shen[x,i]=1)and(fu[y,i]=1) then t:=true;
  if t=false then writeln(y,' ',x) else writeln(x,' ',y);
close(input);
close(output);
end.
