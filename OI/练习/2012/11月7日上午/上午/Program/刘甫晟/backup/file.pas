const   ff='file';
var	i,j,k,tot,n,t,fa,minlong:longint;
	//flag:boolean;
	s,ss:string;
	f:array[1..500]of longint;
	sr:array[1..500]of string;

function vs(x,y:longint):boolean;
begin
if length(sr[x])>length(sr[y]) then minlong:=length(sr[y])
else minlong:=length(sr[x]);
for k:=1 to minlong do begin
        if sr[x][k]<sr[y,k] then exit(false);
        if sr[x][k]>sr[y,k] then exit(true);
        end;
if minlong=length(sr[x]) then exit(false)
else exit(true);
end;

procedure dfs(x,p:longint);
var 	i,t:longint;
	a:array[1..500]of longint;
begin
for i:=1 to p-1 do write('|    ');
if p>0 then write('|----');
writeln(sr[x]);
t:=0;
fillchar(a,sizeof(a),0);
for i:=1 to tot do
	if (f[i]=x) then begin
		inc(t);a[t]:=i;end;
for i:=1 to t do
	for j:=i+1 to t do
		if vs(a[i],a[j]) then begin
			x:=a[i];a[i]:=a[j];a[j]:=x;end;
//writeln(x,' ',sr[x],':-------------');
//for i:=1 to t do writeln(a[i],' ',sr[a[i]]);
for i:=1 to t do dfs(a[i],p+1);
end;

begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
readln(n);
for t:=1 to n do begin
        readln(s);
	j:=0;fa:=0;
	repeat
		inc(j);ss:='';
		while (s[j]<>'/')and(j<=length(s)) do begin
                        ss:=ss+s[j];inc(j);end;
		for i:=1 to tot do
                        if (f[i]=fa)and(sr[i]=ss)then break;
                if (f[i]=fa)and(sr[i]=ss)then fa:=i
		else begin
			tot:=tot+1;
                        f[tot]:=fa;
                        sr[tot]:=ss;
                        fa:=tot;
                        end;
		until j>length(s);
        end;
//for i:=1 to tot do writeln(f[i],' ',sr[i]);
dfs(1,0);
close(input);close(output);
end.
