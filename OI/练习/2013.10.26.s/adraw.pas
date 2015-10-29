var d:array[0..9,1..7] of longint=((1,1,1,0,1,1,1),
                                   (0,0,1,0,0,1,0),
                                   (1,0,1,1,1,0,1),
                                   (1,0,1,1,0,1,1),
                                   (0,1,1,1,0,1,0),
                                   (1,1,0,1,0,1,1),
                                   (1,1,0,1,1,1,1),
                                   (1,0,1,0,0,1,0),
                                   (1,1,1,1,1,1,1),
                                   (1,1,1,1,0,1,1));
    a:array[1..100] of longint;
    i,j,m,k,s,n:longint;
    st:string;
procedure d1;
begin
 for i:=1 to m-1 do begin
  write(' ');
  for j:=1 to k do
   if d[a[i]][1]=1 then write('-') else write(' ');
  write(' ');
  for j:=1 to s do write(' ');
 end;
 i:=m;
 write(' ');
 for j:=1 to k do
  if d[a[i]][1]=1 then write('-') else write(' ');
 write(' ');
 writeln;
end;

procedure d2;
begin
 for i:=1 to m-1 do begin
  if d[a[i]][2]=1 then write('|') else write(' ');
  for j:=1 to k do write(' ');
  if d[a[i]][3]=1 then write('|') else write(' ');
  for j:=1 to s do write(' ');
 end;
 i:=m;
 if d[a[i]][2]=1 then write('|') else write(' ');
 for j:=1 to k do write(' ');
 if d[a[i]][3]=1 then write('|') else write(' ');
 writeln;
end;

procedure d3;
begin
 for i:=1 to m-1 do begin
  write(' ');
  for j:=1 to k do
   if d[a[i]][4]=1 then write('-') else write(' ');
  write(' ');
  for j:=1 to s do write(' ');
 end;
 i:=m;
 write(' ');
 for j:=1 to k do
  if d[a[i]][4]=1 then write('-') else write(' ');
 write(' ');
 writeln;
end;

procedure d4;
begin
 for i:=1 to m-1 do begin
  if d[a[i]][5]=1 then write('|') else write(' ');
  for j:=1 to k do write(' ');
  if d[a[i]][6]=1 then write('|') else write(' ');
  for j:=1 to s do write(' ');
 end;
 i:=m;
 if d[a[i]][5]=1 then write('|') else write(' ');
 for j:=1 to k do write(' ');
 if d[a[i]][6]=1 then write('|') else write(' ');
 writeln;
end;
procedure d5;
begin
 for i:=1 to m-1 do begin
  write(' ');
  for j:=1 to k do
   if d[a[i]][7]=1 then write('-') else write(' ');
  write(' ');
  for j:=1 to s do write(' ');
 end;
 i:=m;
 write(' ');
 for j:=1 to k do
  if d[a[i]][7]=1 then write('-') else write(' ');
 write(' ');
 writeln;
end;

begin
 assign(input,'adraw.in');reset(input);
 assign(output,'adraw.out');rewrite(output);
 readln(k,s);
 readln(st);
 m:=length(st);
 for i:=1 to m do
  a[i]:=ord(st[i])-48;

 d1;
 for n:=1 to k do d2;
 d3;
 for n:=1 to k do d4;
 d5;
 close(input);close(output);
end.
