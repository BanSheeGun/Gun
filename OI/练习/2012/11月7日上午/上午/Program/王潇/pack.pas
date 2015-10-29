Const maxn=111; maxm=2222;
Var i,j,m,n,x,v,k,res:longint;
    a,b,c:array[0..maxn]of longint;
    f:array[0..maxn,0..maxm]of longint;

Function min(x,y:longint):longint;
begin
  if x<y then min:=x else min:=y;
end;

Begin
  assign(input,'pack.in'); reset(input);
  assign(output,'pack.out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      read(x);
      if x=3 then begin read(a[i],b[i]); c[i]:=m div b[i]; end
	     else read(a[i],b[i],c[i]);
    end;

  for v:=1 to m do
    for i:=1 to n do
      for k:=1 to min(c[i],v div b[i]) do
        begin
          if f[i-1][v-k*b[i]]+k*a[i]>f[i][v] then f[i][v]:=f[i-1][v-k*b[i]]+k*a[i];
	  if f[i][v]>res then res:=f[i][v];
        end;
  writeln(res);
  close(input); close(output);
End.