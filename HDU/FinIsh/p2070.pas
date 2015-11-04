var f:array[0..51] of int64;
    i,k:longint;
begin
 f[0]:=0;
 f[1]:=1;
 f[2]:=1;
 for i:=3 to 50 do f[i]:=f[i-1]+f[i-2];

 read(k);
 while k<>-1 do begin
  writeln(f[k]);
  read(k);
 end;
end.