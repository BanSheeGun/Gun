type cw=record
      x,y:longint;
     end;
var a:array[-1..104] of cw;
    n,w,h,i,j,up,down,ans:longint;
procedure sort(l,r: longint);
var i,j:longint;
begin
 i:=l; j:=r;
 a[-1]:=a[(l+r) div 2];
 repeat
    while (a[i].x<a[-1].x)or((a[i].x=a[-1].x)and(a[i].y<a[-1].y)) do inc(i);
    while (a[-1].x<a[j].x)or((a[-1].x=a[j].x)and(a[-1].y<a[j].y)) do dec(j);
    if not(i>j) then begin
    a[0]:=a[i];a[i]:=a[j];
    a[j]:=a[0];inc(i);dec(j);
   end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;
procedure sort2(l,r: longint);
var i,j:longint;
begin
 i:=l; j:=r;
 a[-1]:=a[(l+r) div 2];
 repeat
    while (a[i].y<a[-1].y)or((a[i].y=a[-1].y)and(a[i].x<a[-1].x)) do inc(i);
    while (a[-1].y<a[j].y)or((a[-1].y=a[j].y)and(a[-1].x<a[j].x)) do dec(j);
    if not(i>j) then begin
    a[0]:=a[i];a[i]:=a[j];
    a[j]:=a[0];inc(i);dec(j);
   end;
 until i>j;
 if l<j then sort2(l,j);
 if i<r then sort2(i,r);
end;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
procedure w1(i,j:longint; var u,d:longint);
var l,r,u1:longint;
begin
 l:=a[i].x;
 r:=a[j].x;
 u1:=a[j].y;
 if u1>u then exit;
 if u1<d then exit;
 if min(abs(u-d),abs(l-r))>ans then ans:=min(abs(u-d),abs(l-r));
 if abs(u1-u)<=abs(u1-d) then u:=u1
                        else d:=u1;

end;

procedure w2(i,j:longint; var u,d:longint);
var l,r,u1:longint;
begin
 l:=a[i].y;
 r:=a[j].y;
 u1:=a[j].x;
 if u1>u then exit;
 if u1<d then exit;
 if min(abs(u-d),abs(l-r))>ans then ans:=min(abs(u-d),abs(l-r));
 if abs(u1-u)<=abs(u1-d) then u:=u1
                        else d:=u1;

end;
begin
 read(w,h,n);
 for i:=1 to n do
  read(a[i].x,a[i].y);

 a[n+1].x:=0;a[n+1].y:=0;
 a[n+2].x:=w;a[n+2].y:=h;
 n:=n+2;

 sort(1,n);
 ans:=0;
 for i:=1 to n-1 do
  begin
   up:=h;down:=0;
  for j:=i+1 to n do
   w1(i,j,up,down);
  end;



  sort2(1,n);
 for i:=1 to n-1 do
  begin
   up:=w;down:=0;
  for j:=i+1 to n do
   w2(i,j,up,down);
  end;


 writeln(ans);
end.
