var x,y1,y2:array[1..200] of extended;
    n,i,j:longint;
    ans:extended;
    ok:boolean;
procedure check(q,w:longint;y11,y22:extended);
var aa,x1,x2,k,b,y,k1,b1:extended;
    i,j:longint;
begin
 x1:=x[q];
 x2:=x[w];
 aa:=0;
 if x1-x2=0 then exit;
 k:=(y11-y22)/(x1-x2);
 b:=y11-x1*k;
 for i:=1 to n do begin
  y:=k*x[i]+b;
  if not((y1[i]>=y)and(y>=y2[i])) then begin
   if i=1 then exit;
   k1:=(y1[i]-y1[i-1])/(x[i]-x[i-1]);
   if k>k1 then b1:=y1[i]-x[i]*k1
           else b1:=y2[i]-x[i]*k1;
   if k-k1=0 then exit;
   aa:=(b1-b)/(k-k1);
   if aa>ans then ans:=aa;
   exit;
  end;
  if i=n then ok:=true;
 end;
end;
begin
 readln(n);
 while n<>0 do begin
  for i:=1 to n do begin
   readln(x[i],y1[i]);
   y2[i]:=y1[i]-1;
  end;

  ans:=x[1];
  ok:=false;
  for i:=1 to n do begin
   for j:=1 to n do
    if i<>j then begin
    check(i,j,y2[i],y1[j]);
    check(i,j,y1[i],y2[j]);
    if ok then break;
   end;
   if ok then break;
  end;
  if ok then writeln('Through all the pipe.')
        else writeln(ans:0:2);
  read(n);
 end;
end.
