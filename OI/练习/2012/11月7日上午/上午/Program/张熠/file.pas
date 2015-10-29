var a:array[1..50]of string;
    b:array[1..50,1..5]of string;
    c:array[1..50]of longint;
    i,j,n,t,p,l:longint;
    st,s:string;
    check:boolean;
begin
assign(input,'file.in');reset(input);assign(output,'file.out');rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i]);

  for i:=1 to n-1 do
    for j:=i to n do
      if a[i]>a[j]
      then
        begin
          st:=a[i];
          a[i]:=a[j];
          a[j]:=st;
        end;
  l:=1;
  repeat inc(l);until a[1][l]='/';
  st:=copy(a[1],1,l);
  writeln(st);

  for i:=1 to n do
    begin
      p:=0;t:=l+1;
      while t<length(a[i])do
        begin
          s:='';
          while ord(a[i][t])<>ord('/') do
            begin s:=s+a[i][t];inc(t);end;
          inc(p);
          b[i,p]:=s;
          if a[i][t]='/' then inc(t);
          s:='';
        end;
      c[i]:=p;
    end;

  for i:=1 to n do
    writeln('|----',b[i,c[i]]);
end.