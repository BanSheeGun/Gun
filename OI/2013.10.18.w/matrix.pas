var a:array[1..4001,1..4001] of longint;
    s:array[0..4001,0..4001] of longint;
    x,y,b,c,j,ans,n,i:longint;

procedure js;
begin
 b:=trunc(sqrt(n));
 if b mod 2=1 then begin
  x:=1;
  y:=b;
 end
 else begin
  x:=b;
  y:=1;
 end;
 for i:=b*b to 1000000 do begin
  if a[x][y]=n then exit;
  if sqrt(i)=trunc(sqrt(i)) then begin
   if trunc(sqrt(i)) mod 2=1 then y:=y+1
                             else x:=x+1;
  end
  else begin
   b:=trunc(sqrt(i));
   c:=b+1;
   if i<=(b*b+c*c) div 2 then begin
    if b mod 2=0 then y:=y+1
                 else x:=x+1;
   end
   else begin
    if b mod 2=0 then x:=x-1
                 else y:=y-1;
   end;
  end;
 end;
end;

begin
 assign(input,'matrix.in');reset(input);
 assign(output,'matrix.out');rewrite(output);
 x:=1;y:=1;
 read(n);
 b:=trunc(sqrt(n));
 for i:=1 to (b+1)*(b+1) do begin
  a[x][y]:=i;
  if sqrt(i)=trunc(sqrt(i)) then begin
   if trunc(sqrt(i)) mod 2=1 then y:=y+1
                             else x:=x+1;
  end
  else begin
   b:=trunc(sqrt(i));
   c:=b+1;
   if i<=(b*b+c*c) div 2 then begin
    if b mod 2=0 then y:=y+1
                 else x:=x+1;
   end
   else begin
    if b mod 2=0 then x:=x-1
                 else y:=y-1;
   end;
  end;
 end;

 js;
 ans:=0;
 for i:=1 to x do
  for j:=1 to y do begin
   s[i][j]:=(s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j]) mod 1000000007;
   ans:=(ans+s[i][j]) mod 1000000007;
  end;

 writeln(ans);
 close(input);close(output);
end.
