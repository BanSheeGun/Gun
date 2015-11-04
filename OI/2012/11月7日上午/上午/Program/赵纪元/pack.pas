var a,b,c:array[1..100]of longint;
    f:array[0..3000]of longint;
    i,j,k,na,nb,nc,v:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'pack.in');
  assign(output,'pack.out');
  reset(input);
  rewrite(output);
  readln(n,v);
  for i:=1 to n do
  begin
    read(sort);
    if sort=1 then
    begin
      inc(na);
      read(a[na,1],a[na,2]);
    end;
    if sort=2 then
    begin
      inc(nb);
      read(b[nb,1],b[nb,2],b[nb,3]);
    end;
    if sort=3 then
    begin
      inc(nc);
      read(c[nc,1],c[nc,2]);
      c[nc,3]:=v div c[nc,2];
    end;
  end;
  for i:=1 to nb do
    for j:=1 to b[i,3] do
      for k:=v-b[i,2] downto 0 do
        f[k+b[i,2]]:=max(f[k+b[i,2]],f[k]+b[i,1]);
  for i:=1 to nc do
    for j:=1 to c[i,3] do
      for k:=v-c[i,2] downto 0 do
        f[k+c[i,2]]:=max(f[k+c[i,2]],f[k]+c[i,1]);
  writeln(f[v]);
end.