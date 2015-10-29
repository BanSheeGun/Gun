var head:array['A'..'Z'] of longint;
    e:array[1..16] of char;
    next,l:array[1..16] of longint;
    ch:char;
    st:string;
    ans,n,i:longint;
    t:array[1..16] of boolean;
procedure dfs(ch:char;ll:longint);
var k:longint;
begin
 if ll>ans then ans:=ll;
 k:=head[ch];
 while k<>0 do begin

  if t[k] then begin
   t[k]:=false;
   dfs(e[k],ll+l[k]);
   t[k]:=true;
  end;

  k:=next[k];
 end;
end;
begin
 assign(input,'words.in');reset(input);
 assign(output,'words.out');rewrite(output);
 readln(n);
 for i:=1 to n do begin
  readln(st);
  ch:=st[1];
  e[i]:=st[length(st)];
  next[i]:=head[ch];
  l[i]:=length(st);
  head[ch]:=i;
 end;
 fillchar(t,sizeof(t),true);
 dfs('A',0);
 dfs('E',0);
 dfs('I',0);
 dfs('O',0);
 dfs('U',0);
 writeln(ans);
 close(input);close(output);
end.

