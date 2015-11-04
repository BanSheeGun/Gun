var a:array[0..45000] of boolean;
    n,k,i,j,sum:longint;
begin
 fillchar(a,sizeof(a),false);
 a[0]:=true;sum:=0;
 read(n);
 for i:=1 to n do
  begin
   read(k);
   inc(sum,k);
   for j:=sum downto k do
    if a[j-k] then a[j]:=true;
  end;
 j:=sum div 2;
 while not(a[j]) do  dec(j);
 writeln(abs(sum-j-j))
end.
