var
  a,b:array[0..10000] of string;
  i,n,j,k,l,m,x:longint;
  st,st1,g:string;
  flag:boolean;
begin
  assign(input,'file.in');reset(input);
  assign(output,'file.out');rewrite(output);
  readln(n);
  for i:=1 to n do begin readln(a[i]);end;

  for i:=1 to n do
    for j:=i+1 to n do
      if a[j]<a[i] then
        begin
          a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];end;
  for i:=1 to n do
  writeln('|----',a[i]);
  close(input);close(output);
end.