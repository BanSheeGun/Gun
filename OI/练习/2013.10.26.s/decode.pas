var t:array[0..51,0..1,0..51,0..1] of boolean;
    a,ans,b:array[0..51] of longint;
    ok:boolean;
    n,i:longint;
    st:string;

procedure dfs(k:longint);
var i:longint;
begin
 for i:=0 to 1 do begin
  if k<>1 then dec(a[k-1],i);
  dec(a[k],i);
  if k<>n then dec(a[k+1],i);
  ans[k]:=i;
  if t[k][ans[k]][k-1][ans[k-1]] then
  if ((a[k]>=0)and(a[k+1]>=0)and(a[k-1]=0)) then
   if k=n then begin ok:=true;exit; end
          else dfs(k+1);
  if k<>1 then inc(a[k-1],i);
  inc(a[k],i);
  if k<>n then inc(a[k+1],i);
  if ok then exit;
 end;
 t[k-1][ans[k-1]][k-2][ans[k-2]]:=false;
end;

begin
 assign(input,'decode.in');reset(input);
 assign(output,'decode.out');rewrite(output);
 readln(st);
 fillchar(t,sizeof(t),true);
 n:=length(st);
 for i:=1 to n do a[i]:=ord(st[i])-48;
 b:=a;
 ok:=false;
 ans[1]:=0;
 dfs(2);
 if ok then begin
  for i:=1 to n do
   write(ans[i]);
  writeln;
 end
 else writeln('NONE');
 a:=b;
 ok:=false;
 dec(a[1]);
 dec(a[2]);
 ans[1]:=1;
 if (a[1]<0)or(a[2]<0) then ok:=false
                       else dfs(2);
 if ok then begin
  for i:=1 to n do
   write(ans[i]);
  writeln;
 end
 else writeln('NONE');
 close(input);close(output);
end.
