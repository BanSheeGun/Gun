var a,c,cx:array[0..100001] of longint;
    n,i,num,z:longint;
    ans,max:longint;
begin
 readln(num);
 for z:=1 to num do begin
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(c,sizeof(c),0);
  fillchar(cx,sizeof(cx),0);

  for i:=1 to n do a[i]:=a[i]+a[i-1];
  for i:=1 to n do begin
    c[i]:=c[i-1];
    cx[i]:=cx[i-1];
    if c[i]>a[i] then begin
     c[i]:=a[i];
     cx[i]:=i;
    end;
  end;

  max:=a[1]-c[0];
  ans:=1;
  for i:=2 to n do
   if a[i]-c[i-1]>max then begin
    max:=a[i]-c[i-1];
    ans:=i;
   end;

  writeln('Case ',z,':');
  writeln(max,' ',cx[ans-1]+1,' ',ans);
  if z<>num then writeln;
 end;
end.
