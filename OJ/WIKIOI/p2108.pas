const maxextended=1e30;
      zero=1e-8;
var ans,s,x1,x2,y1,y2:extended;
    a:array[1..100,1..2] of extended;
    n,i,j,k:longint;
begin
 read(n);
 for i:=1 to n do
  read(a[i][1],a[i][2]);

 ans:=maxextended;
 for i:=1 to n do
  for j:=1 to n do
   if i<>j then
   for k:=1 to n do
   if (i<>k)and(j<>k) then begin
    x1:=a[i][1]-a[k][1];
    y1:=a[i][2]-a[k][2];
    x2:=a[j][1]-a[k][1];
    y2:=a[j][2]-a[k][2];
    s:=abs(x1*y2-x2*y1)/2;
    if s<ans then ans:=s;
   end;
 if ans<=zero then writeln('Impossible')
              else writeln(ans:0:2);
end.
