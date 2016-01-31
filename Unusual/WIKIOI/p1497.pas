var p,k,b,ans:longint;
function ef(x:longint):longint;
var ans:longint;
begin
 if x=1 then exit(b mod k);
 ans:=ef(x div 2) mod k;
 ans:=ans*ans mod k;
 if x mod 2 =1 then ans:=ans*b mod k;
 exit(ans);
end;
begin
 read(b,p,k);
 ans:=ef(p) mod k;
 writeln(b,'^',p,' mod ',k,'=',ans);
end.