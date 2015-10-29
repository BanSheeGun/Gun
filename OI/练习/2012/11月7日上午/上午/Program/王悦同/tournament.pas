//Gobble Restaurant!!

var n,i,j,k,x1,y1,flag1,flag2:longint;
    a:array[0..100] of longint;
    f:array[0..100,0..100] of longint;

begin

  assign(input,'tournament.in');
  assign(output,'tournament.out');
  reset(input);
  rewrite(output);

  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to n*(n-1) div 2-1 do
    begin
      readln(x1,y1);
      inc(a[x1]);inc(a[y1]);
      f[x1,y1]:=1;
    end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if (f[i,k]=1) and (f[k,j]=1) then f[i,j]:=1;
  flag1:=0;
  flag2:=0;
  for i:=1 to n do
    if a[i]<>n-1 then
      if flag1=0 then flag1:=i else flag2:=i;
  if f[flag1,flag2]=1 then writeln(flag1,' ',flag2)
                      else writeln(flag2,' ',flag1);

  close(input);
  close(output);
end.
