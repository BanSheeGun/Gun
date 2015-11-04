program wwx;
var j,i,x1,y1,n:longint;
    x,y:array[1..50] of longint;
    a:array[1..50,1..50] of longint;

function zhao(i,j:longint):boolean;
var k:longint;
    t:boolean;
begin
  for k:=1 to n do
  if (i<>k) and (a[i,k]=1) and (t<>false) then
    begin
     if k=j then t:=false
            else zhao(k,j);
    end;
  if t<>false then t:=true;
end;

begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
 read(n);
 for i:=1 to trunc((n*(n-1)/2-1)) do
  begin
   readln(x[i],y[i]);
   a[x[i],y[i]]:=2;
   a[y[i],x[i]]:=1;
  end;
 for i:=1 to n do a[i,i]:=1;
 for i:=1 to n do
  for j:=1 to n do
   if a[i,j]=0 then begin x1:=i;y1:=j;end;
 if (zhao(y1,x1)=false) then write(x1,' ',y1)
                        else write(y1,' ',x1);
close(input);close(output);
end.
