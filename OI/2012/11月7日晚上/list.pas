var word:array[1..100] of string;
    e,next,head:array[1..10000] of longint;
    t:array[1..1000] of boolean;
    d:array[1..10000] of longint;
    st:string;
    n,i,j,ss,sum:longint;
    tt:boolean;
procedure dfs(z:longint);
var k:longint;
begin
 k:=head[z];
 while k<>0 do begin
  if t[e[k]] then begin
   t[e[k]]:=false;
   d[z]:=e[k];
   if z=n then tt:=true
          else dfs(z+1);
   if tt then exit;
   t[e[k]]:=true;
  end;
  k:=next[k];
 end;
end;
begin
 assign(input,'list.in');reset(input);
 assign(output,'list.out');rewrite(output);
 readln(n);
 sum:=0;
 fillchar(t,sizeof(t),true);
 for i:=1 to n do begin
  readln(word[i]);
  readln(st);
  if st='SAME' then ss:=1;
  if st='UP' then ss:=2;
  if st='DOWN' then ss:=3;
  case ss of
   1:begin
    inc(sum);
    e[sum]:=i;
    head[i]:=sum;
    next[sum]:=0;
    t[i]:=false;
   end;
   2:begin
    for j:=i+1 to n do
     if t[i] then begin
      inc(sum);
      e[sum]:=i;
      next[sum]:=head[j];
      head[j]:=sum;
     end;
   end;
   3:begin
    for j:=1 to i-1 do
     if t[i] then begin
      inc(sum);
      e[sum]:=i;
      next[sum]:=head[j];
      head[j]:=sum;
     end;
   end;
  end;
 end;

 tt:=false;
 fillchar(t,sizeof(t),true);
 dfs(1);

 for i:=1 to n do
  writeln(word[d[i]]);
 close(input);close(output);
end.
