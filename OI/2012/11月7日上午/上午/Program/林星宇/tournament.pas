const maxn=100;
var v,c:array[1..maxn]of longint;
    a:array[1..maxn,1..maxn]of longint;
    flag:boolean;
    x,y,n,i,s,t,num:longint;

procedure dfs(x:longint);
 var i:longint;
begin
 if x=t then begin flag:=true;exit;end;
 v[x]:=1;
 for i:=1 to n do
   if (a[x,i]=1)and(v[i]=0) then dfs(i);
end;

begin
assign(input,'tournament.in');reset(input);
assign(output,'tournament.out');rewrite(output);
readln(n);
num:=(n*(n-1) div 2)-1;
 for i:=1 to num do
   begin
	readln(x,y);
	a[x,y]:=1;
	inc(c[x]);
	inc(c[y]);
   end;
s:=0;t:=0;
for i:=1 to num do
  if c[i]=n-2 then begin
		if s=0 then s:=i
			else t:=i;
		    end;
flag:=false;
dfs(s);
 if flag then writeln(s,' ',t)
	 else writeln(t,' ',s);
close(input);
close(output);
end.
