Const maxn=55;
Var i,j,n,x,y,t,num:longint;
    a,b,d,tt:array[0..maxn] of longint;
    c:array[0..maxn,0..maxn]of longint;
    e:array[0..maxn]of boolean;

Begin
  assign(input,'tournament.in'); reset(input);
  assign(output,'tournament.out'); rewrite(output);
  readln(n);
  for i:=1 to n*(n-1)div 2-1 do
    begin
      readln(x,y);	//x赢y  x-->y
      inc(a[x]);	//出度
      inc(b[y]);	//入度
      c[x,a[x]]:=y;	//邻接表
    end;

  for i:=1 to n do	//找到漏掉的点
    if a[i]+b[i]=n-2 then
       begin
	 inc(num);
	 d[num]:=i;
       end;

  num:=n; t:=0;		//拓扑
  while num>0 do
    begin
      inc(t);
      for i:=1 to n do
        if not e[i] then
        if b[i]=0 then
           begin
             dec(num);
	     tt[i]:=t;
           end;
      for i:=1 to n do
        if tt[i]=t then
           begin
	     for j:=1 to a[i] do
               dec(b[c[i,j]]);
             e[i]:=true;
           end;
    end;

  if tt[d[1]]<tt[d[2]] then writeln(d[1],' ',d[2])
  		       else writeln(d[2],' ',d[1]);

  close(input); close(output);
End.
