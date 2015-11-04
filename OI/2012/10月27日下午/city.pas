var f:array[1..3000,1..3000] of integer;
    a:array[1..3001] of integer;
    x,y,n,i,j:integer;
    ok:boolean;
function find(k,i:longint):longint;
var ii:longint;
begin
 for ii:=i to n do
  if ii<>k then
  if f[ii][k]=0 then
  if a[ii]<>0 then exit(ii);
 exit(n+1);
end;
function pan:boolean;
var i:longint;
begin
 for i:=1 to n do
  if a[i]<>0 then exit(false);
 exit(true);
end;
procedure dfs(h:longint);
var l:longint;
begin
 l:=find(h,h);

 dec(a[h]); dec(a[l]);
 f[h][l]:=1;f[l][h]:=1;
 if (h=n+1)or(l=n+1) then begin
  if pan then begin
   ok:=true;
   exit;
  end
  else begin
   f[h][l]:=0;f[l][h]:=0;
   inc(a[h]);inc(a[l]);
   exit;
  end
 end
 else begin
  dfs(find(n+1,h));
  if ok then exit;
  inc(a[h]);inc(a[l]);
  f[h][l]:=0;f[l][h]:=0;
 end;
end;
begin
 assign(input,'city.in');reset(input);
 assign(output,'city.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(a[i]);
 a[n+1]:=-1;
 ok:=false;
 dfs(find(n+1,1));
 if ok then begin
  for i:=1 to n do begin
   for j:=1 to n-1 do
    write(f[i][j],' ');
   writeln(f[i][n]);
  end;
 end
 else writeln('No Solution');
 close(input);close(output);
end.
