var t:array[1..2000] of longint;
    c:array[1..2000] of longint;
    n,i:longint;
    ans:int64;
procedure sort(l,r: longint);
var i,j,x,y,z:longint;
begin
 i:=l;j:=r;
 x:=t[(l+r) div 2];
 z:=c[(l+r) div 2];
 repeat
  while (t[i]>x)or((t[i]=x)and(c[i]<z)) do inc(i);
  while (x>t[j])or((t[j]=x)and(z<c[j])) do dec(j);
  if not(i>j) then begin
   y:=t[i];t[i]:=t[j];t[j]:=y;
   y:=c[i];c[i]:=c[j];c[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

procedure dfs(k,sum,sj:longint;dj:int64);
begin
 if k>n then exit;
 if dj>ans then exit;
 sum:=sum+1;
 dj:=dj+c[k];
 sj:=sj+t[k];
 if sum+sj>=n then 
  if dj<ans then begin
   ans:=dj;
   exit;
  end;
 dfs(k+1,sum,sj,dj);
 sum:=sum-1;
 dj:=dj-c[k];
 sj:=sj-t[k];
 dfs(k+1,sum,sj,dj);
end;

begin
 assign(input,'ca.in');reset(input);
 assign(output,'ca.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(t[i],c[i]);

 sort(1,n);

 ans:=9223372036854775807;

 dfs(1,0,0,0);
 writeln(ans);
 close(input);close(output);
end.
