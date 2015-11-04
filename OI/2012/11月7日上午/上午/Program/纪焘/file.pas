var n,i,j,num:longint;
    st,st1,t:ansistring;
    a:array[1..10000]of ansistring;
begin
assign(input,'file.in');reset(input);
assign(output,'file.out');rewrite(output);
  readln(n);
  num:=1;
  for i:=1 to n do
    begin
      readln(st);
      j:=1;
      while st[j]<>'/' do inc(j);
      st1:=copy(st,1,j-1);
      a[num]:=copy(st,j+1,length(st)-j);
      inc(num);
    end;
  writeln(st1);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then begin
                          t:=a[i];
                          a[i]:=a[j];
                          a[j]:=t;
                        end;
  for i:=1 to n do
    writeln('|----',a[i]);
close(input);
close(output);
end.