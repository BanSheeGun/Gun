var map:array[1..50,1..50]of longint;
    q,z,x,c:array[1..5000]of longint;
    b:boolean;
    i,n,x1,y1,h,t:longint;
begin
  assign(input,'tournament.in');
  assign(output,'tournament.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n*(n-1)div 2 do
  begin
    read(z[i],x[i]);
    inc(c[z[i]]);
    inc(c[x[i]]);
    map[z[i],x[i]]:=1;
  end;
  for i:=1 to n do
  begin
    if (x1=0)and(c[i]<n-1) then x1:=i;
    if (x1>0)and(c[i]<n-1) then y1:=i;
  end;
  h:=0;
  t:=1;
  q[1]:=x1;
  while h<t do
  begin
    b:=false;
    inc(h);
    for i:=1 to n do
      if map[q[h],i]=1 then
      begin
        inc(t);
        q[t]:=i;
      end;
    for i:=h to t do
      if q[i]=y1 then
      begin
        b:=true;
        break;
      end;
    if b then break;
  end;
  if b then writeln(x1,' ',y1) else writeln(y1,' ',x1);
  close(input);
  close(output);
end.