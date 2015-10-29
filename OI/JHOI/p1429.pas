var a:array[1..10] of longint;
    n,i,sum:longint;
    ch:char;
begin
 n:=0;
 while not seekeoln do begin
  read(ch);
  if ch<>'-' then
   if ch='X' then begin inc(n); a[n]:=10; end
             else begin inc(n); a[n]:=ord(ch)-48;end;
 end;

 sum:=0;
 for i:=1 to 9 do
  inc(sum,a[i]*i);

 sum:=sum mod 11;
 if sum=a[10] then write('Right')
 else begin
  write(a[1],'-',a[2],a[3],a[4],'-',a[5],a[6],a[7],a[8],a[9],'-');
  if sum=10 then write('X')
              else write(sum);
 end;
end.
