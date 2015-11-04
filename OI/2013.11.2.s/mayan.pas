type cw=array[0..6,0..8] of longint;
var s:array[0..5] of cw;
    a:cw;
    cz:array[1..2,1..10] of longint;
    ok:boolean;
    i,j,nn,n:longint;
function check(a:cw):boolean;
var i,j:longint;
begin
 for i:=1 to 5 do
  for j:=1 to 7 do
   if a[i][j]<>0 then exit(false);
 exit(true);
end;

procedure game(var a:cw;var change:boolean);
var i,j,s,x,z,y,k:longint;
begin
 change:=false;
 for i:=1 to 5 do
  for j:=1 to 7 do
   if a[i][j]<>0 then begin
    s:=j;
    while a[i][s-1]=0 do begin
     change:=true;
     a[i][s-1]:=a[i][s];
     a[i][s]:=0;
     dec(s);
    end;
  end;

 for i:=1 to 5 do
  if a[i][1]=0 then begin
   for j:=1 to 7 do begin
    a[i][j]:=a[i+1][j];
    change:=true;
    a[i+1][j]:=0;
   end;
  end;
 for i:=1 to 5 do
  for j:=1 to 7 do if a[i][j]<>0 then begin
   s:=0;
   while a[i][j]=a[i][j+s+1] do inc(s);
   x:=0;
   while a[i][j]=a[i][j-x-1] do inc(x);
   z:=0;
   while a[i+z][j]=a[i+z+1][j] do inc(z);
   y:=0;
   while a[i][j]=a[i-y-1][j] do inc(y);
   if s>=2 then begin
    change:=true;
    for k:=0 to s do a[i][j+k]:=0;
   end;
   if x>=2 then begin
    change:=true;
    for k:=0 to x do a[i][j-k]:=0;
   end;
   if z>=2 then begin
    change:=true;
    for k:=0 to z do a[i+k][j]:=0;
   end;
   if y>=2 then begin
    change:=true;
    for k:=0 to y do a[i-k][j]:=0;
   end;
  end;
end;

procedure dfs(k:longint);
var i,j,temp:longint;
    c:boolean;
begin
 for i:=1 to 4 do
  for j:=1 to 7 do
   if not ((s[k-1][i][j]=0)and(s[k-1][i+1][j]=0)) then begin
    cz[1][k]:=i;cz[2][k]:=j;
    s[k]:=s[k-1];
    temp:=s[k][i][j];
    s[k][i][j]:=s[k][i+1][j];
    s[k][i+1][j]:=temp;
  {  if ((k=1)and(i=3)and(j=2)) then begin
     writeln;
    end;
    if ((k=2)and(i=4)and(j=2)) then begin
     writeln;
    end;
    if ((k=3)and(i=4)and(j=1)) then begin
     writeln;
    end;  }
    c:=true;
    while c do
     game(s[k],c);
    if check(s[k]) then begin
     ok:=true;
     nn:=k;
     exit;
    end;
    if k+1<=n then dfs(k+1);
    if ok then exit;
   end;
end;

begin
 assign(input,'mayan.in');reset(input);
 assign(output,'mayan.out');rewrite(output);
 read(n);
 for i:=0 to 6 do begin
  a[i][0]:=-1;
  a[i][8]:=-1;
 end;
 for i:=0 to 8 do begin
  a[0][i]:=-1;
  a[6][i]:=-1;
 end;
 for i:=1 to 5 do begin
  j:=1;
  read(a[i][j]);
  while a[i][j]<>0 do begin
   inc(j);
   read(a[i][j]);
  end;
 end;

 ok:=false;
 s[0]:=a;
 dfs(1);

 if not ok then writeln(-1)
 else begin
  for i:=1 to nn do
   writeln(cz[1][i]-1,' ',cz[2][i]-1,' 1');
 end;
 close(input);close(output);
end.
