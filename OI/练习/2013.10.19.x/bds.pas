var c:array[0..20] of longint;
    t:array[1..20] of boolean;
    a:array[1..20] of longint;
    ok:boolean;
    n,i,j,sum:longint;
procedure dfs(k,ss:longint);
var i,s:longint;
begin
 for i:=1 to n do
 if t[i] then begin
  t[i]:=false;
  a[k]:=i;
  s:=ss+c[k]*i;
  if s<sum then begin
   if k<n then dfs(k+1,s);
  end
  else if (s=sum)and(k=n) then begin
   ok:=true;
   exit;
  end;
  t[i]:=true;
  if ok then exit;
 end;
end;

begin
 assign(input,'bds.in');reset(input);
 assign(output,'bds.out');rewrite(output);
 c[1]:=1;
 read(n,sum);
 for i:=2 to n do
  for j:=n downto 1 do
   c[j]:=c[j]+c[j-1];

 fillchar(t,sizeof(t),true);
 ok:=false;
 dfs(1,0);
 for i:=1 to n-1 do write(a[i],' ');writeln(a[n]);
 close(input);close(output);
end.
