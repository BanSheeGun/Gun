var head,cs:array[1..50] of longint;
    e,next:array[1..100000] of longint;
    t:array[1..50] of boolean;
    i,j,n,x,y:longint;
function find(x,y:longint):boolean;
var k:longint;
    qq:boolean;
begin
 t[x]:=false;
 k:=head[x];
 while k<>0 do begin
  qq:=false;
  if e[k]=y then exit(true)
            else qq:=find(e[k],y);
  if qq then exit(qq);
  k:=next[k];
 end;
 exit(false);
end;

begin
 assign(input,'tournament.in');reset(input);
 assign(output,'tournament.out');rewrite(output);
 read(n);
 for i:=1 to n*(n-1) div 2 -1 do begin
  read(x,y);
  inc(cs[x]);
  inc(cs[y]);
  next[i]:=head[x];
  e[i]:=y;
  head[x]:=i;
 end;

 x:=0;y:=0;
 for i:=1 to n do
  if cs[i]<n-1 then
   if x=0 then x:=i else y:=i;

 fillchar(t,sizeof(t),true);
 if find(y,x) then writeln(y,' ',x)
              else writeln(x,' ',y);
 close(input);close(output);
end.
