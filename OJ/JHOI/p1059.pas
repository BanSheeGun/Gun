var a,f:array[0..10000] of boolean;
    n,max,k,i,j,mm:longint;
begin
 fillchar(a,sizeof(a),true);
 read(n);
 for j:=1 to n do begin
  fillchar(f,sizeof(f),false);
  f[0]:=true;
  max:=0;
  read(k);
  while k<>-1 do begin
   if k>max then max:=k;
   for i:=max downto 0 do
    if f[i] then begin
     f[i+k]:=true;
     if i+k>max then max:=i+k;
    end;
   read(k);
  end;

  for i:=0 to 10000 do
   a[i]:=a[i] and f[i];
  if max>mm then mm:=max;
 end;


 while not a[mm] do dec(mm);
 writeln(mm);
end.
