var dc:array[1..100] of string;
    st:string;
    s,t:array[1..100000] of longint;
    ans,now:array[1..100000] of longint;
    head:array[1..100] of longint;
    e,next:array[1..100000] of longint;
    use:array[1..100000] of boolean;
    ml,top,l,i,n,j,m:longint;

procedure dfs(q:longint);
var k:longint;
begin
 l:=l+1;
 now[l]:=q;
 if l>ml then begin
  ml:=l;
  ans:=now;
 end;
 k:=head[q];
 while k<>0 do begin
  if use[e[k]] then begin
   use[e[k]]:=false;
   dfs(e[k]);
   use[e[k]]:=true;
  end;
  k:=next[k];
 end;
 l:=l-1;
end;

function find(st:string):longint;
var i:longint;
begin
 for i:=1 to n do
  if dc[i]=st then exit(i);
end;

begin
 assign(input,'language.in');reset(input);
 assign(output,'language.out');rewrite(output);
 readln(n,m);
 for i:=1 to n do
  readln(dc[i]);
 for i:=1 to m do begin
  readln(st);
  j:=pos(' ',st);
  s[i]:=find(copy(st,1,j-1));
  t[i]:=
  find(copy(st,j+1,length(st)-j));
 end;

 top:=0;
 for i:=1 to m do
  for j:=1 to m do
   if i<>j then
    if t[i]=s[j] then begin
     inc(top);
     e[top]:=j;
     next[top]:=head[i];
     head[i]:=top;
    end;

 fillchar(use,sizeof(use),true);
 for i:=1 to m do begin
  use[i]:=false;
  l:=0;
  dfs(i);
  use[i]:=true;
 end;

 writeln(ml+1);
 write(dc[s[ans[1]]]);
 for i:=1 to ml do write(' ',dc[t[ans[i]]]);
 writeln;
 close(input);close(output);
end.
