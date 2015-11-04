var st:array[0..50] of ansistring;
    a:array[0..50,1..10] of string;
    b:array[1..50] of longint;
    i,j,k,n,top:longint;
procedure sort(l,r: longint);
var i,j:longint;
    y,x:ansistring;
begin
 i:=l;j:=r;
 x:=st[(l+r) div 2];
 repeat
  while st[i]<x do inc(i);
  while x<st[j] do dec(j);
  if not(i>j) then begin
   y:=st[i];st[i]:=st[j];st[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

begin
 assign(input,'file.in');reset(input);
 assign(output,'file.out');rewrite(output);

 readln(n);
 for i:=1 to n do
  readln(st[i]);
 sort(1,n);
 top:=1;
 for i:=1 to n do begin
  k:=pos('/',st[i]);
  while k<>0 do begin
   inc(b[i]);
   a[i][b[i]]:=copy(st[i],1,k-1);
   delete(st[i],1,k);
   k:=pos('/',st[i]);
  end;
  inc(b[i]);
  a[i][b[i]]:=st[i];
 end;

 writeln(a[1][1]);
 for i:=1 to n do begin
  top:=2;
  while (top<=b[i])and(a[i][top]=a[i-1][top]) do inc(top);
  if (a[i][top]<>a[i-1][top]) then dec(top);
  for j:=top+1 to b[i] do begin
   for k:=1 to j-2 do write('|    ');
   if j<>1 then write('|----');
   writeln(a[i][j]);
  end;
 end;
 close(input);close(output);
end.
