var x,y:array[1..1000] of longint;
    i,n,ans:longint;
function check(q:longint):boolean;
var i,b,z:longint;
begin
 b:=0;
 for i:=1 to n do begin
  z:=sqr(x[q]-x[i])+sqr(y[q]-y[i]);
  if z=0 then begin end
  else if b=0 then begin
        b:=z;
       end
       else if b<>z then exit(false);
 end;
 exit(true);
end;
begin
 assign(input,'InvisibleFullMoon.in');reset(input);
 assign(output,'InvisibleFullMoon.out');rewrite(output);
 read(n);
 for i:=1 to n do begin
  read(x[i],y[i]);
 end;
 for i:=1 to n do begin
  if check(i) then begin
   ans:=i;
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
