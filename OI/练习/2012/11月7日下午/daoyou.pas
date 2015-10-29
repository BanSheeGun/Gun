var a:array[1..17,1..17] of longint;
    t:array[1..17] of boolean;
    i,j,n,ans:longint;
procedure dfs(l,s:longint);
var i,k:longint;
begin
 k:=(l-1)*1000-s;
 if k>(n*1000-ans) then exit;
 for i:=1 to n do
  if t[i] then begin
   t[i]:=false;
   if l=n then begin if s+a[l][i]>ans then ans:=s+a[l][i]; end
   else dfs(l+1,s+a[l][i]);
   t[i]:=true;
  end;
end;
begin
 assign(input,'daoyou.in');reset(input);
 assign(output,'daoyou.out');rewrite(output);
 read(n);
 for i:=1 to n do
  for j:=1 to n do
   read(a[i][j]);
 fillchar(t,sizeof(t),true);
 dfs(1,0);
 writeln(ans);
 close(input);close(output);
end.
