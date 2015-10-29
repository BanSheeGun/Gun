var n,x,y,z,i,x1,x2,sum:longint;
    a:array[1..1000000] of longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;

begin
 assign(input,'mark.in');reset(input);
 assign(output,'mark.out');rewrite(output);
 read(n);
 sum:=n;
 for i:=1 to n do begin
  read(x,y);

  if abs(x-y)<=8 then
   a[i]:=(x+y) div 2


  else begin
   read(z);
   x1:=abs(x-z);
   x2:=abs(y-z);
   if min(x1,x2)<=8 then begin
    if x1<x2 then a[i]:=((x+z) div 2);
    if x1>x2 then a[i]:=((y+z) div 2);
    if x1=x2 then a[i]:=((max(x,y)+z) div 2);
   end

   else begin
    a[i]:=-1;
   end;

  end;
 end;
 writeln(sum);
 for i:=1 to n do
  if a[i]=-1 then writeln('wait')
             else writeln(a[i]);
 close(input);close(output);
end.
