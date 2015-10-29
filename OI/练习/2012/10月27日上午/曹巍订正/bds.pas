var a:array[1..20] of longint;
    i,j,n,m:longint;
    s:array[1..20] of longint;
    s1:array[1..20] of longint;
    t:boolean;
    s2:array[1..600000] of boolean;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
procedure dfs(deep,sum:longint);
var su,i,j:longint;
begin
 for i:=1 to min(sum,n)  do
  if s2[i] then begin
  s[deep]:=i;
  su:=sum-a[deep]*i;
  if (su=0)and(deep=n) then begin
   t:=true;
   for j:=1 to n-1 do
    write(s[j],' ');writeln(s[n]);
   exit;
   end;
  if su<0 then exit;
  s[deep]:=i;
  s2[i]:=false;
  if deep<n then dfs(deep+1,su);
  s2[i]:=true;
  if t then exit;
 end;
end;
begin
 assign(input,'bds.in');reset(input);
 assign(output,'bds.out');rewrite(output);
 read(n,m);
 a[1]:=1;
 for i:=2 to n do
  for j:=i downto 2 do
   a[j]:=a[j]+a[j-1];

 s1[n]:=1;
 t:=false;
 fillchar(s2,sizeof(s2),true);
 for i:=n-1 downto 1 do
  s1[i]:=s1[i+1]+a[i];

 dfs(1,m);
 close(input);close(output);
end.
