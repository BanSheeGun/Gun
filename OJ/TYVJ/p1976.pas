uses math;
var x,h,rad,dl,dr:array[1..50000] of extended;
    l,r,ma,mid,la,ra,y:extended;
    n,i:longint;

procedure sort(l,r:longint);
var i,j:longint;
    q,y:extended;
begin
 i:=l;j:=r;
 q:=dl[(l+r) div 2];
 repeat
  while (dl[i]<q) do inc(i);
  while (q<dl[j]) do dec(j);
  if not(i>j) then begin
  y:=dl[i];dl[i]:=dl[j];dl[j]:=y;
  y:=dr[i];dr[i]:=dr[j];dr[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

function max(a,b:extended):extended;
begin
 if a>b then exit(a);
 exit(b);
end;

function check(t:extended):boolean;
var i,w:longint;
    now,a,b,gg:extended;
begin
 now:=l;  w:=0;
 for i:=1 to n do
 if h[i]>=t then begin
  inc(w);
  gg:=pi/2-rad[i];
  a:=tan(gg);
  b:=h[i]-a*x[i];
  dl[w]:=(t-b)/a;
  dr[w]:=2*x[i]-dl[w];
 end;
 sort(1,w);
 for i:=1 to w do
  if dl[i]<=now then now:=max(dr[i],now);
 if now>=r then exit(true);
 exit(false);
end;

begin
 ma:=0;
 read(n,l,r);
 for i:=1 to n do begin
  read(x[i],h[i]);
  read(y);
  rad[i]:=y/180*pi;
  if h[i]>ma then ma:=h[i];
 end;
 la:=0;ra:=ma;
 while la<ra do begin
  mid:=(la+ra)/2;
  if check(mid) then la:=mid+0.00001
                else ra:=mid;
  if abs(la-ra)<0.00001 then break;
 end;
 writeln(la:0:3);
end.
