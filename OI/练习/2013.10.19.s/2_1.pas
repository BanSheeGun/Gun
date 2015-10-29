var a,b:array[1..100] of longint;
    n,ans,i,m:longint;
    t:array[1..100] of boolean;
procedure dfs(k,sum:longint);
var i,s:longint;
begin
 for i:=1 to n do
  if t[i] then begin
   t[i]:=false;
   s:=sum+a[i]-(k-1)*b[i];
   if k<>m then dfs(k+1,s)
   else if s>ans then ans:=s;
   t[i]:=true;
 end;
end;

begin
 assign(input,'2.in');reset(input);
 assign(output,'0.out');rewrite(output);
 read(n,m);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do read(b[i]);
 fillchar(t,sizeof(t),true);
 ans:=0;
 dfs(1,0);
 writeln(ans);
 close(input);close(output);
end.
