type cw=record
      x,y,num,w:longint;
     end;
var a:array[1..100000] of cw;
    jh,ans:array[1..100000] of longint;
    top,n,m,i,x,y,w:longint;
procedure sort(l,r: longint);
var i,j:longint;
    x,y:cw;
begin
 i:=l;j:=r;
 x:=a[(l+r) div 2];
 repeat
  while (a[i].w<x.w) do inc(i);
  while (x.w<a[j].w) do dec(j);
  if not(i>j) then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;
procedure sort1(l,r: longint);
var i,j:longint;
    x,y:longint;
begin
 i:=l;j:=r;
 x:=ans[(l+r) div 2];
 repeat
  while (ans[i]<x) do inc(i);
  while (x<ans[j]) do dec(j);
  if not(i>j) then begin
   y:=ans[i];ans[i]:=ans[j];ans[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort1(l,j);
 if i<r then sort1(i,r);
end;

function find(x:longint):longint;
begin
 if x<>jh[x] then jh[x]:=find(jh[x]);
 exit(jh[x]);
end;

begin
 assign(input,'rumor.in');reset(input);
 assign(output,'rumor.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(x,y,w);
  a[i].num:=i;
  a[i].x:=x;
  a[i].y:=y;
  a[i].w:=w;
 end;
 sort(1,m);
 top:=0;
 for i:=1 to n do jh[i]:=i;
 for i:=1 to m do
  if find(a[i].x)<>find(a[i].y) then begin
   top:=top+1;
   ans[top]:=a[i].num;
   jh[find(a[i].x)]:=find(a[i].y);
  end;

 writeln(top);
 sort1(1,top);
 for i:=1 to top do writeln(ans[i]);
 close(input);close(output);
end.
