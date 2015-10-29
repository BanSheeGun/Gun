var i,n,b:longint;
    a:array[0..20] of longint=(0,1,1,2,3,3,4,4,5,6,6,7,8,8,9,9,10,11,11,12,12);
begin
 read(n);
 b:=n div 21*13;
 writeln(a[n mod 21]+b);
end.
