var a,head:array[1..50] of ansistring;
    ch:array[1..50] of longint;
    i,j,n,t,kk,k,s:longint;
    tst,l:ansistring;
begin
 assign(input,'file.in');
 reset(input);
 assign(output,'file.out');
 rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
   readln(a[i]);
   ch[i]:=pos('/',a[i]);
  end;
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if (a[i]>a[j]) then
    begin
     tst:=a[i];
     a[i]:=a[j];
     a[j]:=tst;
     t:=ch[i];
     ch[i]:=ch[j];
     ch[j]:=t;
    end;
 t:=0;
 for i:=1 to n do
  begin
  s:=pos('/',a[i]);
  l:=copy(a[i],1,s-1);
   if t=0 then
    begin
     inc(t);
     head[t]:=l;
    end
          else
   if l<>head[t] then
    begin
     inc(t);
     head[t]:=l;
    end;
  end;
 for i:=1 to t do
  begin
   writeln(head[i]);
   for k:=1 to n do
    if a[k]<>'' then
     if pos(head[i],a[k])=1 then
    begin
     write('|----');
     for kk:=ch[k]+1 to length(a[k]) do write(a[k][kk]);
     writeln;
     a[k]:='';
    end;
  end;
 close(input);
 close(output);
end.
