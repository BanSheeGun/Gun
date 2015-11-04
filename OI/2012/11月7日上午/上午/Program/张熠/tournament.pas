var a:array[1..50,1..50]of integer;
    b:array[1..50]of longint;
    i,j,n,x,y:longint;

begin
assign(input,'tournament.in');reset(input);assign(output,'tournament.out');rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  while not eof do
    begin
      readln(x,y);
      a[x,y]:=1;
      a[y,x]:=1;
      inc(b[x]);
    end;

  for i:=1 to n do
    for j:=1 to n do
      if (i<>j)and(a[i,j]=0)and(b[i]>b[j])
      then begin writeln(i,' ',j);exit;end;
close(input);close(output);
end.