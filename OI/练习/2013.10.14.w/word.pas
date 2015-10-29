var a:array[1..100000,1..26] of longint;
    b:array[1..100000] of longint;
    st:ansistring;
    i,j,k,ans,n,m:longint;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
begin
 assign(input,'word.in');reset(input);
 assign(output,'word.out');rewrite(output);
 readln(n,m);
 readln(st);
 for i:=1 to n do begin
  b[i]:=ord(st[i])-ord('A')+1;
 end;

 for i:=1 to m do
  if i<>b[1] then a[1][i]:=1;
 for i:=2 to n do
  for j:=1 to m do begin
   a[i][j]:=maxlongint;
   for k:=1 to m do
   if j<>k then a[i][j]:=min(a[i][j],a[i-1,k]);
   if j<>b[i] then inc(a[i][j]);
  end;
 ans:=maxlongint;
 for i:=1 to m do ans:=min(ans,a[n][i]);
 writeln(ans);
 close(input);close(output);
end.
