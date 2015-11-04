var  f:array[0..100000] of longint;
     num,cost,worth:array[0..100000] of longint;
     i,j,k,l,n,m,ans,ty,top,top1,v:longint;
     a,b,worth1:array[0..300] of longint;
function maximum(a,b:longint):longint;
begin
  maximum:=a;
   if b>a then exit(b);
end;
procedure startput;
const filename='pack';
begin
  assign(input,filename+'.in');
  reset(input);
  assign(output,filename+'.out');
  rewrite(output);
end;
procedure overput;
begin
  close(input);
  close(output); 
end;
begin
  startput;
  top:=0;
  top1:=0;
  read(n,m);
  for i:=1 to n do
  begin
    read(ty);
    case ty of
    1:
      begin
        inc(top1);
        read(a[top1],b[top1]);
      end;
    2:begin
        inc(top);
        read(worth[top],cost[top],num[top]);
      end;
    3:begin
        inc(top);
        read(worth[top],cost[top]);
        num[top]:=m div cost[top]+1;
      end;
    end;
  end;

  for i:=1 to top do
  begin
    for j:=m downto 0 do
      for k:=1 to num[i] do
      begin
        if j-k*cost[i]<0 then continue;
        f[j]:=maximum(f[j],f[j-k*cost[i]]+k*worth[i]);
      end;
  end;


  for i:=1 to top1 do
  begin
    for j:=m downto m do
    for v:=0 to m do
    begin
      if v<0 then continue;
      if j-v<0 then continue;
      f[j]:=maximum(f[j],f[j-v]+a[i]*v*v-b[i]*v);
    end;
  end;


  writeln(f[m]);
  overput;
end.
