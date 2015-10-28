var i,a,b:longint;
    f:array[0..1000000] of longint;
function p(n:longint):boolean;
var i,m:longint;
begin
 m:=n;
 while n<>0 do begin
  if n mod 100=62 then exit(false);
  n:=n div 10;
 end;
 n:=m;
 while n<>0 do begin
  if n mod 10=4 then exit(false);
  n:=n div 10;
 end;
 exit(true);
end;
begin
 fillchar(f,sizeof(f),0);
 for i:=1 to 1000000 do
  if p(i) then f[i]:=f[i-1]+1
          else f[i]:=f[i-1];
 read(a,b);
 while (a<>0)or(b<>0) do begin
  writeln(f[b]-f[a-1]);
  read(a,b);
 end;
end.
