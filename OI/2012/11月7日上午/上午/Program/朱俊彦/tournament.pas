var n,i,t,k,h,x,y,temp:longint;
    a,b:array[1..500]of longint;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
  readln(n);
  for i:=1 to n do
      a[i]:=i;
  t:=((n*(n-1))div 2)-1;
  for i:=1 to t do
      begin
        readln(k,h);
        if a[k]<a[h] then begin
                            temp:=a[k];
                            a[k]:=a[h];
                            a[h]:=temp;
                          end;
        inc(b[k]);
        inc(b[h]);
      end;
  for i:=1 to n do
      begin
        if b[i]=(n-2) then begin
                             if x<>0 then begin
                                          if y=0 then
                                          begin
                                          y:=i;
                                          break;
                                          end;
                                          end
                                     else x:=i;
                           end;
      end;
  if b[x]>b[y] then writeln(x,' ',y)
               else writeln(y,' ',x);
close(input);
close(output);
end.