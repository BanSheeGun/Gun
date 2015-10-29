var a:array[1..3000000] of boolean;
    i,m,j:longint;
begin
 assign(input,'prime.in');reset(input);
 assign(output,'prime.out');rewrite(output);
 fillchar(a,sizeof(a),true);
 readln(m);
 for i:=1 to m do begin
  a[i]:=a[i] and((i mod 7=1)or(i mod 7=6));
  if a[i]and(i<>1) then begin
   for j:=2 to m div i do
    a[j*i]:=a[j*i]and(not(a[i]));
  end;
 end;

 if (a[m]) then writeln(-1)
         else begin
  write(m,':');
  for i:=2 to m  do
   if (m mod i=0)and(a[i]) then write(' ',i);
  writeln;
 end;
 close(input);close(output);
end.
