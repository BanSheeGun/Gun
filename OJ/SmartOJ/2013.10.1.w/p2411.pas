var t:array[1..1000000] of boolean;
    x,y:array[1..1000000] of extended;
    ax,ay,ansx,ansy:extended;
    n,i,j:longint;
function pan(x1,x2,y1,y2:extended):boolean;
var k:extended;
begin
 k:=x1*x2+y1*y2;
 if k>=0 then exit(true);
 exit(false);
end;

begin
 fillchar(t,sizeof(t),true);
 read(n);
 for i:=1 to n do
  read(x[i],y[i]);

 for i:=1 to n do
  if t[i] then begin
   ax:=x[i];ay:=y[i];
   t[i]:=false;
   for j:=i+1 to n do
    if pan(ax,x[j],ay,y[j]) then begin
     ax:=ax+x[j];
     ay:=ay+y[j];
     t[j]:=false;
    end;
   if sqr(ax)+sqr(ay)>sqr(ansx)+sqr(ansy) then begin
    ansx:=ax;
    ansy:=ay;
   end;
  end;

 writeln(sqr(ansx)+sqr(ansy):0:3);
end.
