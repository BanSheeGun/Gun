var a:array[1..104] of longint;
    n,i,m,ans:longint;
procedure work1;
var i:longint;
    ok:boolean;
begin
 for i:=1 to n do begin
  inc(ans);
 end;
 for i:=1 to n-3 do begin
  ok:=false;
  if a[i]=a[i+1] then
   if a[i+1]=a[i+2] then
    if a[i+2]=a[i+3] then ok:=true;
  if ok then inc(ans);
 end;
end;
procedure work2;
var i:longint;
begin
 for i:=1 to n-1 do
  if (a[i]=a[i+1]) then inc(ans);
end;
procedure work3;
var i:longint;
begin
 for i:=1 to n-2 do
  if (a[i]=a[i+1])and(a[i+2]=a[i]+1) then inc(ans);
 for i:=1 to n-1 do
  if a[i]=a[i+1]+1 then inc(ans);
end;

procedure work4;
var i:longint;
begin
 for i:=1 to n-2 do
  if (a[i+2]=a[i+1])and(a[i+2]+1=a[i]) then inc(ans);
 for i:=1 to n-1 do
  if a[i]+1=a[i+1] then inc(ans);
end;

procedure work5;
var i:longint;
begin
 for i:=1 to n-2 do
  if (a[i]=a[i+1])and(a[i]=a[i+2]) then inc(ans);
 for i:=1 to n-1 do
  if a[i]+1=a[i+1] then inc(ans);
 for i:=1 to n-1 do
  if a[i]=a[i+1]+1 then inc(ans);
 for i:=1 to n-2 do
  if (a[i]=a[i+1]+1)and(a[i+2]=a[i+1]+1) then inc(ans);
end;
procedure work6;
var i:longint;
begin
 for i:=1 to n-2 do
  if (a[i+2]=a[i+1])and(a[i+2]=a[i]) then inc(ans);
 for i:=1 to n-1 do
  if (a[i]=a[i+1]) then inc(ans);
 for i:=1 to n-1 do
  if (a[i]=a[i+1]+2) then inc(ans);
 for i:=1 to n-2 do
  if (a[i+2]=a[i]+1)and(a[i+1]=a[i]+1) then inc(ans);
end;
procedure work7;
var i:longint;
begin
 for i:=1 to n-2 do
  if (a[i+2]=a[i+1])and(a[i+2]=a[i]) then inc(ans);
 for i:=1 to n-1 do
  if (a[i]=a[i+1]) then inc(ans);
 for i:=1 to n-1 do
  if (a[i]+2=a[i+1]) then inc(ans);
 for i:=1 to n-2 do
  if (a[i+2]+1=a[i])and(a[i+2]+1=a[i+1]) then inc(ans);
end;
begin
 assign(input,'game.in');reset(input);
 assign(output,'game.out');rewrite(output);
 read(n,m);
 ans:=0;
 for i:=1 to n do
 read(a[i]);
 case m of
  1:begin
   work1;
  end;
  2:begin
   work2;
  end;
  3:begin
   work3;
  end;
  4:begin
   work4;
  end;
  5:begin
   work5;
  end;
  6:begin
   work6;
  end;
  7:begin
   work7;
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
