var a:array[1..20,1..20] of longint;
    n,i,j,k,m,ans:longint;
    t:array[1..20] of longint;
    s:array[1..20] of string;
    s1,s2:string;
    ch:char;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
procedure dfs(k,l:longint);
var i:longint;
begin
 if l>ans then ans:=l;
   for i:=1 to n do
   begin
    if a[k][i]<>0 then
     if t[i]<2 then
     begin
      inc(t[i]);
      dfs(i,l+length(s[i])-a[k][i]);
      dec(t[i])
     end;
   end;
end;
begin
 readln(n);
 for i:=1 to n do
  readln(s[i]);
 readln(ch);
 fillchar(a,sizeof(a),0);
 for i:=1 to n do
  for j:=1 to n do
    begin
     m:=min(length(s[i]),length(s[j]));
     for k:=1 to m-1 do
      begin
       s1:=copy(s[i],length(s[i])-k+1,k);
       s2:=copy(s[j],1,k);
       if s1=s2 then
        begin
         a[i][j]:=k;
         break;
        end;
      end;
    end;
  ans:=0;
  for i:=1 to n do
   if s[i][1]=ch then
    begin
     fillchar(t,sizeof(t),0);
     t[i]:=1;
     dfs(i,length(s[i]));
    end;

 writeln(ans);
end.
