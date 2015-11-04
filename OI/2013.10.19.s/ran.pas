var a,b:array[1..100] of longint;
    n,j,i,m:longint;
    t:array[1..100] of boolean;
    f:array[0..100] of longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

begin
 randomize;
 assign(output,'2.in');rewrite(output);
  n:=random(10)+1;
  m:=random(n)+1;
  writeln(n,' ',m);
  for i:=1 to n do write(random(2000),' ');
  writeln;
  for i:=1 to n do write(random(2000),' ');
  
 close(output);
end.
