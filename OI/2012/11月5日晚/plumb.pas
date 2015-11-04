var d:array[1..2,1..1000000] of longint;
    ans:array[1..60000] of longint;
    l,c,f,p,i,k,lp,pp,dd:longint;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
begin
 assign(input,'plumb.in');reset(input);
 assign(output,'plumb.out');rewrite(output);
 read(dd,pp);
 d[1][1]:=0;
 d[2][1]:=maxlongint;
 f:=1;p:=1;
 for i:=1 to pp do begin
  lp:=p;
  read(l,c);
  for f:=1 to lp do begin
   k:=min(d[2][f],c);
   if (ans[d[1][f]+l]<k)and(d[1][f]+l<=dd) then begin
    ans[d[1][f]+l]:=k;
    inc(p);
    d[1][p]:=d[1][f]+l;
    d[2][p]:=k;
   end;
  end;
 end;
 writeln(ans[dd]);
 close(input);close(output);
end.
