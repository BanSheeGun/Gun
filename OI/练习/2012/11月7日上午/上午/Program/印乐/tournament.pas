var n,i,j,m,a,b,k:longint;
    f:array[1..50,1..50] of longint;

procedure setup;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
end;

procedure endit;
begin
close(input);
close(output);
end;

begin
setup;
  readln(n);
  m:=(n*(n-1))div 2-1;
  for i:=1 to n do for j:=1 to n do f[i,j]:=0;
  for i:=1 to m do
      begin
      readln(a,b);
      f[a,b]:=1; f[b,a]:=-1;
      end;
  for i:=1 to n do for j:=1 to n do if (i<>j)and(f[i,j]=0) then break;
  for k:=1 to n do
      if (k<>i)and(k<>j) then
         begin
         if (f[i,k]=1)and(f[k,j]=1) then begin writeln(i,' ',j); endit; halt; end;
         if (f[k,i]=1)and(f[j,k]=1) then begin writeln(j,' ',i); endit; halt; end;
         end;
  endit;
end.
