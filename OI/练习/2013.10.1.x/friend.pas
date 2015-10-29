var a:array[1..100,1..100] of longint;
    m,n,ax,ay,x,y,i,j,k:longint;
begin
 assign(input,'friend.in');reset(input);
 assign(output,'friend.out');rewrite(output);
 read(m,n);
 read(x,y);
 for i:=1 to m do
  for j:=1 to n do
   read(a[i][j]);
 k:=a[x][y];
 ax:=-1;
 for i:=1 to m do
  for j:=1 to n do
   if (a[i][j]=k)and((i<>x)or(j<>y)) then begin
    if (ax=-1) then begin
     ax:=i;
     ay:=j;
    end
   else begin
    if abs(i-x)+abs(j-y)<abs(ax-x)+abs(ay-y) then begin
      ax:=i;
      ay:=j;
     end
    else if abs(i-x)+abs(j-y)=abs(ax-x)+abs(ay-y) then  begin
    if (i<ax)or((i=ax)and(j<ay)) then begin
     ax:=i;
     ay:=j;
    end;
    end;
   end;
  end;
 writeln(ax,' ',ay);
 close(input);close(output);
end.
