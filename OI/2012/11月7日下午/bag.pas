var d:array[1..1200000] of longint;
    w:array[1..20] of longint;
    max,i,ans,n,f,p,lp:longint;
begin
 assign(input,'bag.in');reset(input);
 assign(output,'bag.out');rewrite(output);
 read(n);
 for i:=1 to n do read(w[i]);
 read(max);
 p:=1;
 for i:=1 to n do begin
  lp:=p;
  for f:=1 to lp do begin
   if d[f]+w[i]<=max then begin
    inc(p);
    d[p]:=d[f]+w[i];
    if d[p]>ans then ans:=d[p];
   end;
  end;
 end;

 writeln(ans);
 close(input);close(output);
end.
