var a,b:array[1..10] of longint;
    x,top,ans,i,j:longint;
begin
 top:=0;
 for j:=1 to 10 do begin
  read(x);
  ans:=0;
  for i:=1 to top do
  if a[i]=x then ans:=i;
  if ans=0 then begin
   inc(top);
   a[top]:=x;
   b[top]:=1;
  end
  else begin
   inc(b[ans]);
  end;
 end;
 ans:=1;
 for i:=1 to top do
  if b[i]>b[ans] then ans:=i;
 writeln(a[ans],' ',b[ans]);
end.
