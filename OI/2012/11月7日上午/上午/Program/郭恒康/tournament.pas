program tournament(input,output);
var i,j,k,l,n,m,x,y,top,cnt,get,anstop:longint;
    link:array[0..100,0..100] of longint;
    du:array[0..10000] of longint;
    stark:array[0..10000] of longint;
    ans:array[0..10000] of longint;
    v:array[0..10000] of boolean;
procedure startput;
const filename='tournament';
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
  read(n);
  for i:=1 to n*(n-1) div 2 -1 do
  begin
    read(x,y);
    link[x,y]:=1;
    link[y,x]:=-1;
    inc(du[y]);
  end;

  fillchar(v,sizeof(v),0);

  top:=0;
  for i:=1 to n do if du[i]=0 then
  begin
    inc(top);
    stark[top]:=i;
    v[i]:=true;
  end;
  anstop:=0;
  while top>0 do
  begin
    get:=stark[top];
    inc(anstop);
    ans[anstop]:=get;
    for i:=1 to n do
    if link[get][i]=1 then dec(du[i]);
    dec(top);
    for i:=1 to n do
    if du[i]=0 then
    begin
      if v[i] then continue;
      inc(top);
      stark[top]:=i;
      v[i]:=true;
    end;
  end;
  for i:=1 to n do
   for j:=i+1 to n do
   if ((link[ans[i],ans[j]]<>1)and(link[ans[i]][ans[j]]<>-1)) then
   begin
     writeln(ans[i],' ',ans[j]);
     break;
   end;
  overput;
end.
