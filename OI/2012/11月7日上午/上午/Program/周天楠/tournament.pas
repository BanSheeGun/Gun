var
  c:array[1..10] of longint;
  k:array[1..60,1..2] of longint;
  l,i,n:longint;
  p:array[1..60,1..2] of longint;
begin
  assign(input,'tournament.in');
  reset(input);
  assign(output,'tournament.out');
  rewrite(output);
  fillchar(k,sizeof(k),0);
  readln(n);
  for i:=1 to (n*(n-1) div 2)-1 do
    begin
     readln(p[i,1],p[i,2]);
     inc(k[p[i,1],1]);
     inc(k[p[i,2],1]);
     inc(k[p[i,1],2]);
    end;
  l:=1;
  for i:=1 to n do
   begin
     if k[i,1]<>n-1 then begin c[l]:=i; inc(l) end;
   end;
  if k[c[1],2]>k[c[2],2] then writeln(c[1],' ',c[2])
                         else writeln(c[2],' ',c[1]);
  close(input);
  close(output);
end.