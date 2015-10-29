type cw=array[1..60] of longint;
var a:array[1..60] of longint;
    sum,n,i,m,ll:longint;
    t,cp:boolean;
    d:array[0..60] of cw;
    ans:cw;
function check(l:longint):boolean;
var i:longint;
procedure dfs(k:longint);
var i,j:longint;
begin
 for i:=1 to m do begin
  d[k]:=d[k-1];
  d[k][i]:=d[k][i]+a[k];
  if k=n then begin
   cp:=true;
   for j:=1 to m do
    if ans[j]<>d[k][j] then begin cp:=false; break end;
   if cp then begin
    t:=true;
    exit;
   end;
  end
  else begin
   if d[k][i]<=ll then dfs(k+1);
   if t then exit;
  end;
 end;
end;
begin
 m:=sum div l;
 ll:=l;
 for i:=1 to m do ans[i]:=l;
 fillchar(d,sizeof(d),0);
 t:=false;
 dfs(1);
 exit(t);
end;
begin
 assign(input,'stick.in');reset(input);
 assign(output,'stick.out');rewrite(output);
 read(n);
 for i:=1 to n do begin
  read(a[i]);
  inc(sum,a[i]);
 end;

 for i:=1 to sum do
  if sum mod i=0 then
   if check(i) then break;
 writeln(i);
 close(input);close(output);
end.
