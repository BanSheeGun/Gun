var f:array[0..1000] of longint;
    i,n,t,x,y,j:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'medic2.in');reset(input);
 assign(output,'medic2.out');rewrite(output);
 read(t,n);
 for i:=1 to n do begin
  read(x,y);
  for j:=x to t do
   f[j]:=max(f[j],f[j-x]+y);
 end;
 writeln(f[t]);
 close(input);close(output);
end.
