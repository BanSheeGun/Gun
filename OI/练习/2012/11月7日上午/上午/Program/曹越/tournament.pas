var
  n,i,p,q,j,x,y:longint;
  a,b:array[1..10000] of longint;
  flag:boolean;
begin
  assign(input,'tournament.in');reset(input);
  assign(output,'tournament.out');rewrite(output);
  readln(n);
  for i:=1 to n*(n-1) div 2-1 do
    begin
      readln(p,q);
      inc(a[p]);inc(a[q]);inc(b[p]);
    end;
  for i:=1 to n do
    if (a[i]<>n-1) and (flag=false) then
      begin
        flag:=true;
        x:=i;
      end else
        begin
          if (a[i]<>n-1) and (flag=true) then
            begin
              y:=i;
              break;
            end;
        end;
  inc(b[x]);flag:=true;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[i]=b[j] then flag:=false;
  if flag then writeln(x,' ',y) else
    begin
      flag:=true;
      dec(b[x]);inc(b[y]);
      for i:=1 to n-1 do
        for j:=i+1 to n do
          if b[i]=b[j] then flag:=false;
      if flag then writeln(y,' ',x);
    end;
  close(input);close(output);
end.