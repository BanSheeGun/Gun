var f:array[0..100] of qword;
    n,i,j:longint;
begin
 assign(input,'power.in');reset(input);
 assign(output,'power.out');rewrite(output);
 fillchar(f,sizeof(f),0);
 f[1]:=1;
 f[0]:=0;
 read(n);
 for i:=1 to n do begin
  for j:=i+1 downto 1 do
   f[j]:=f[j]+f[j-1];
 end;

 write('(a+b)^',n,'=');
 for i:=n downto 0 do begin
  if i<>n then write('+');
  if f[i+1]<>1 then write(f[i+1]);
  if i<>0 then begin
   write('a');
   if (i<>1) then write('^',i);
  end;
  if n-i<>0 then begin
   write('b');
   if n-i<>1 then write('^',n-i);
  end;
 end;

 writeln;
 close(input);close(output);
end.
