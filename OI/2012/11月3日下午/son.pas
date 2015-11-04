var n,i,x1,y1,x2,y2,ans,j,x,y:longint;
function gcd(m,n:longint):longint;
begin
 if m mod n = 0 then exit(n)
                else exit(gcd(n,m mod n));
end;
begin
 assign(input,'son.in');reset(input);
 assign(output,'son.out');rewrite(output);
 read(n);
 for i:=1 to n do begin
  read(x1,y1,x2,y2);
  x1:=x1 div y1;
  x2:=y2 div x2;
  if y2 mod y1<>0 then ans:=0
  else begin
   ans:=0;
   for j:=1 to trunc(sqrt(y2 div y1)) do
    begin
     x:=j;
     if gcd(x,x1)=1 then
      if y2 div y1 mod x=0 then
       if gcd(y2 div y1 div x,x2)=1 then inc(ans);
     y:=y2 div y1 div x;
     if y<>x then 
     if gcd(y,x1)=1 then
      if y2 div y1 mod y=0 then
       if gcd(y2 div y1 div y,x2)=1 then inc(ans);
    end;
  end;
  writeln(ans);
 end;
 close(input);close(output);
end.
