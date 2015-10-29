program ex;
var g:array[1..50,1..50] of 0..1;
    a:array[1..10000] of integer;
    b:array[1..50] of integer;
    c:array[1..50] of 0..1;
    n,i,x,y,f,r:longint;
    p:boolean;
begin
assign(input,'tournament.in');reset(input);
assign(output,'tournament.out');rewrite(output);
  read(n);
  fillchar(g,sizeof(g),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  for i:=1 to n*(n-1)div 2-1 do
    begin
      read(x,y);
      g[x,y]:=1;
      inc(b[x]);
      inc(b[y]);
    end;
  i:=1;
  while (i<=n)and(b[i]=n-1) do inc(i);
  x:=i;
  inc(i);
  while (i<=n)and(b[i]=n-1) do inc(i);
  y:=i;
  a[1]:=x;
  f:=1;r:=1;
  p:=false;
  c[x]:=1;
  while (f<=r)and(p=false) do
    begin
      for i:=1 to n do
        if c[i]=0 then
          if g[a[f],i]=1 then begin inc(r);a[r]:=i;c[i]:=1;end;
      if a[r]=y then p:=true;
      inc(f);
    end;
  if p=true then writeln(x,' ',y)
            else writeln(y,' ',x);
  close(input);close(output);
end.



