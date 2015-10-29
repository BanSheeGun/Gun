const oo=2147483647;
var f:array[0..2000] of longint;
    n,i,c,t,j:longint;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
begin
 assign(input,'ca.in');reset(input);
 assign(output,'ca.out');rewrite(output);
 read(n);
 for i:=1 to n do f[i]:=oo;
 f[0]:=0;
 for i:=1 to n do begin
  read(t,c);
  t:=t+1;
  for j:=n downto 1 do begin
   if j-t<0 then f[j]:=min(f[j],c)
   else if f[j-t]<>oo then f[j]:=min(f[j],f[j-t]+c);
  end;
 end;
 writeln(f[n]);
 close(input);close(output);
end.
