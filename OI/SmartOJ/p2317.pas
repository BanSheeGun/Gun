var a,b:array[0..2000,0..2000] of longint;
    i,j,x,n,m,x1,x2,y1,y2,top:longint;
    ans:int64;
    c:array[1..100] of longint;
procedure print;
var i:longint;
begin
 write(c[top]);
 for i:=top-1 downto 1 do begin
  write(c[i] div 100000 mod 10);
  write(c[i] div 10000 mod 10);
  write(c[i] div 1000 mod 10);
  write(c[i] div 100 mod 10);
  write(c[i] div 10 mod 10);
  write(c[i] mod 10);
 end;
 writeln;
end;

procedure plus(x:int64);
var i:longint;
begin
 i:=1;
 c[1]:=c[1]+x;
 while c[i]>1000000 do begin
  c[i+1]:=c[i+1]+c[i] div 1000000;
  c[i]:=c[i] mod 1000000;
  inc(i);
  if i>top then top:=i;
 end;
end;

begin
 fillchar(a,sizeof(a),0);
 fillchar(b,sizeof(b),0);

 read(n,m);
 for i:=1 to n do
  for j:=1 to n do begin
   read(a[i][j]);
   inc(a[i][j],a[i-1][j]);
  end;

 for i:=1 to n do
  for j:=1 to n do begin
   read(b[i][j]);
   inc(b[i][j],b[i][j-1]);
  end;

 for j:=1 to m do begin
  top:=1;
  fillchar(c,sizeof(c),0);
  read(x1,y1,x2,y2);
  if x1>x2 then begin
   x:=x1;
   x1:=x2;
   x2:=x;
  end;
  if y1>y2 then begin
   x:=y1;
   y1:=y2;
   y2:=x;
  end;
  ans:=0;
  for i:=1 to n do begin
   ans:=(a[x2][i]-a[x1-1][i])*(b[i][y2]-b[i][y1-1]);
   plus(ans);
  end;
  print;
 end;
end.
