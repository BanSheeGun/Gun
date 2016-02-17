var a:array[0..1000] of longint;
    n,i,top:longint;
begin
 read(n);
 for i:=1 to n do
  begin
   read(top);
   inc(a[top]);
  end;

 top:=0;
 for i:=0 to 1000 do
  if a[i]<>0 then inc(top);
 writeln(top);
 for i:=0 to 1000 do
  if a[i]<>0 then write(i,' ');
 writeln;
end.
