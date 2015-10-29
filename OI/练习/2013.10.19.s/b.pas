var a,b:array[1..100] of longint;
    n,j,i,m:longint;
    f:array[0..100,0..100] of int64;

procedure sort(l,r: longint);
var i,j,x,y,z:longint;
begin
 i:=l;j:=r;
 x:=b[(l+r) div 2];
 repeat
  while (b[i]>x) do inc(i);
  while (x>b[j]) do dec(j);
  if not(i>j) then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   y:=b[i];b[i]:=b[j];b[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

begin
 assign(input,'b.in');reset(input);
 assign(output,'b.out');rewrite(output);
 read(n,m);
 fillchar(f,sizeof(f),0);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do read(b[i]);
 sort(1,n);
 for i:=1 to n do
  for j:=m downto 1 do begin
   f[i][j]:=f[i-1][j];
   f[i][j]:=max(f[i][j],f[i-1][j-1]+a[i]-(j-1)*b[i])
  end;

 writeln(f[n][m]);
 close(input);close(output);
end.
