const   ff='tournament';
var     i,j,k,n,x,y:longint;
        f:array[1..500,1..500]of boolean;
begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
readln(n);
fillchar(f,sizeof(f),false);
for i:=1 to n*(n-1)div 2-1 do begin
	read(x,y);
	f[x,y]:=true;
	end;
for i:=1 to n do
        for j:=1 to n do
                if (i<>j)and(not f[i,j]) and (not f[j,i]) then
                        begin x:=i;y:=j;end;
for k:=1 to n do
	for i:=1 to n do
		for j:=1 to n do
			f[i,j]:=(f[i,k] and f[k,j])or f[i,j];
if f[x,y] then writeln(x,' ',y)
else writeln(y,' ',x);
close(input);close(output);
end.
