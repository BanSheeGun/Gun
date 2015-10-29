var t:array[1..10000] of longint;
    b:array[1..5] of longint=(1,3,7,15,31);
    i,ans,n,m,j:longint;
function pan(k:longint):boolean;
var i:longint;
begin
 for i:=1 to 5 do
  if k+b[i]>n then exit(false)
  else if t[k+b[i]]=1 then exit(false);
 exit(true);
end;
begin
 assign(input,'damnedwords.in');reset(input);
 assign(output,'damnedwords.out');rewrite(output);
 read(n,m);
 for i:=1 to n do
  if pan(i) then begin
  for j:=1 to 5 do
   t[i+b[j]]:=1;
  inc(ans);
 end;
 writeln(ans*m);
 close(input);close(output);
end.
