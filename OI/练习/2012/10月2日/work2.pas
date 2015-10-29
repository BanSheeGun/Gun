var f:array[0..20000] of longint;
    w:array[1..10] of longint;
    i,j,n:longint;
begin
 assign(input,'work2.in');reset(input);
 assign(output,'work2.out');rewrite(output);
 for i:=1 to 10 do
  read(w[i]);
 read(n);

 fillchar(f,sizeof(f),63);
  f[0]:=0;

 for i:=0 to n do
  begin
   for j:=1 to 10 do
   if f[i+j]>f[i]+w[j] then
    f[i+j]:=f[i]+w[j];
  end;
 writeln(f[n]);
 close(input);close(output);
end.
