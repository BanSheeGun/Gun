var n,i,j:longint;
begin
 assign(output,'spider.in');rewrite(output);
 randomize;
 read(n);
 writeln(n);
 for i:=1 to n do
  for j:=i+1 to n do
   writeln(i,' ',j,' ',random(n*n));
 close(output);
end.
