var a:array[1..10100] of longint;
    x,n,m,i:longint;
begin
 read(n,m);
 fillchar(a,sizeof(a),0);
 for i:=1 to m do begin
  read(x);
  a[x]:=1-a[x];
 end;
 x:=0;
 for i:=1 to n do
  if a[i]=1 then begin
   if x=0 then begin
    write(i);
    x:=1;
   end
   else write(' ',i);
  end;
 writeln;
end.
