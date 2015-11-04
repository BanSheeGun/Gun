var i,j,n,p,q,x,y:longint;
    a,c:array[1..100] of longint;
procedure setup;
begin
  assign(input,'tournament.in');
  reset(input);
  assign(output,'tournament.out');
  rewrite(output);
end;
procedure endit;
begin
  close(input);
  close(output);
end;
begin
  setup;
  readln(n);
  for i:=1 to n do
    c[i]:=n;
  for i:=2 to n*(n-1) div 2 do
    begin
      readln(x,y);
      inc(a[x]);
      inc(a[y]);
      c[y]:=c[x]-1;
    end;
  for i:=1 to n do
    if a[i]<>n-1 then begin
                        if p=0 then p:=i
                               else q:=i;
                      end;
  if c[p]>c[q] then writeln(p,' ',q)
               else writeln(q,' ',p);
  endit;
end.