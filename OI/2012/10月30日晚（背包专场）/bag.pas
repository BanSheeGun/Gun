var d:array[1..2000000] of longint;
    v:array[1..20] of longint;
    j,mv,n,p,max,i,lp:longint;
begin
 assign(input,'bag.in');reset(input);
 assign(output,'bag.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(v[i]);
 read(mv);

 d[1]:=0;
 p:=1;
 max:=0;
 for j:=1 to n do begin
  lp:=p;
  for i:=1 to lp do begin
   if d[i]+v[j]<=mv then begin
    inc(p);
    d[p]:=d[i]+v[j];
    if d[p]>max then max:=d[p];
   end;
  end;
 end;
 writeln(max);
 close(output);close(input);
end.
