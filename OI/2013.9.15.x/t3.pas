//NOIP2012 DAY2 T1
var a,b,x,y,t:longint;
procedure gcd(a,b:longint);
begin
 if a mod b <>0 then gcd(b,a mod b);
 t:=x;
 x:=y;
 y:=t-a div b *y;
end;
begin
 assign(input,'t3.in');reset(input);
 assign(output,'t3.out');rewrite(output);
 read(a,b);
 x:=1;y:=0;
 gcd(a,b);
 if x<0 then inc(x,b);
 writeln(x);
 close(input);close(output);
end.
