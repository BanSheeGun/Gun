var q,p1,p2,m,n,i,j,k:longint;
    t:array[0..51,0..51]of boolean;
    f:boolean;

procedure clo;
begin
close(input);close(outpuT);
end;

begin
assign(input,'tournament.in');reset(input);
assign(output,'tournament.out');rewrite(output);
readln(n);m:=(n-1)*n div 2;
for i:=1 to m-1 do
 begin
 read(p1,p2);
 t[p1,p2]:=true;
 end;
for k:=1 to n do
 for i:=1 to n do
  for j:=1 to n do
   if (t[i,j]=false)and(t[i,k])and(t[k,j]) then begin writeln(i,' ',j);clo;exit;end;
clo;
end.
