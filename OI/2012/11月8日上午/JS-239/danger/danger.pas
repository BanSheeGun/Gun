type cw=record
      x,y:longint;
     end;
var jh,j:array[1..150] of longint;
    a:array[0..5000] of cw;
    n,m,i,k,x,y:longint;
    t:array[1..5000] of boolean;
procedure sort(l,r:longint);
var mx,my,i,j:longint;
begin
 i:=l;j:=r;
 mx:=a[(l+r) div 2].x;
 my:=a[(l+r) div 2].y;
 repeat
  while (a[i].x<mx)or((a[i].x=mx)and(a[i].y<my)) do inc(i);
  while (mx<a[j].x)or((a[j].x=mx)and(my<a[j].y)) do dec(j);
  if i<=j then begin
   a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
function find(x:longint):longint;
begin
 if j[x]<>x then j[x]:=find(j[x]);
 exit(j[x]);
end;
begin
 assign(input,'danger.in');reset(input);
 assign(output,'danger.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(a[i].x,a[i].y);
  if a[i].x>a[i].y then begin
   k:=a[i].x;
   a[i].x:=a[i].y;
   a[i].y:=k;
  end;
 end;

 sort(1,m);
 for i:=1 to n do jh[i]:=i;
 fillchar(t,sizeof(t),true);
 for i:=1 to m do begin
  j:=jh;
  if t[i] then
  for k:=1 to m do
   if i<>k then begin
    x:=find(a[k].x);
    y:=find(a[k].y);
    if x=y then t[k]:=false;
    j[x]:=j[y];
    if find(a[i].x)=find(a[i].y) then begin t[i]:=false; break; end;
   end;
  if t[i] then writeln(a[i].x,' ',a[i].y);
 end;
 close(input);close(output);
end.
