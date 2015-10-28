var a:array[1..4] of longint;
    n,m,ans:longint;
begin
 while not seekeof do begin
  readln(n,m);
  ans:=0;
  if (n<=153)and(153<=m) then begin inc(ans); a[ans]:=153; end;
  if (n<=370)and(370<=m) then begin inc(ans); a[ans]:=370; end;
  if (n<=371)and(371<=m) then begin inc(ans); a[ans]:=371; end;
  if (n<=407)and(407<=m) then begin inc(ans); a[ans]:=407; end;

  if ans=0 then writeln('no')
   else begin
    for n:=1 to ans-1 do write(a[n],' ');
    writeln(a[ans]);
   end;
 end;
end.