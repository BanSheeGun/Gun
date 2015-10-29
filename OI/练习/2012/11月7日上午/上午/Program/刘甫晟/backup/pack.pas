const   ff='pack';
var     f:array[0..20000]of longint;
	x,a,b,c,n,v,i,j,k:longint;

procedure renew(var x:longint;y:longint);
begin
if x<y then x:=y;
end;

begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
readln(n,v);
for i:=1 to n do begin
	read(x,a,b);
	if x=1 then
		for j:=1 to v do
			for k:=1 to j do
				renew(f[j],f[j-k]+a*k*k-b*k);
	if x=2 then begin
		read(c);
		for j:=v downto b do
			for k:=1 to c do begin
				if j<k*b then break;
				renew(f[j],f[j-k*b]+a*k);
				end;
		end;
	if x=3 then
		for j:=b to v do
			renew(f[j],f[j-b]+a);
	end;
writeln(f[v]);
close(input);close(output);
end.
