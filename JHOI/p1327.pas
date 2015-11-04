var n:longint;
    s1:ansistring;
    f:array[0..5000,0..5000] of longint;
function w(l,r:longint):longint;
var k:longint;
begin
 if f[l][r]<>0 then exit(f[l][r]);

 if (l>=r) then exit(0);


 if s1[l]=s1[r] then
  begin
   f[l][r]:=w(l+1,r-1);
   exit(f[l][r]);
  end;

 if s1[l]<>s1[r] then
  begin
   f[l][r]:=w(l+1,r);
   k:=w(l,r-1);
   if f[l][r]>k then f[l][r]:=k;
   inc(f[l][r],1);
   exit(f[l][r]);
  end;
end;
begin
 readln(n);
 readln(s1);
 writeln(w(1,n));
end.
