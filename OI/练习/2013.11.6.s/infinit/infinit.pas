var f:array[1..93] of int64;
    m,i,q:longint;
    x,y,ansx,ansy:int64;
function find(x:int64):int64;
var i:longint;
    ans:int64;
begin
 if x=0 then exit(0);
 ans:=0;
 for i:=1 to 92 do
  if (f[i]<=x)and(x<f[i+1]) then break;
 ans:=f[i-1];
 ans:=ans+find(x-f[i]);
 exit(ans);
end;
begin
 assign(input,'infinit.in');reset(input);
 assign(output,'infinit.out');rewrite(output);
 read(m);
 f[1]:=1;
 f[2]:=1;
 for i:=3 to 92 do
  f[i]:=f[i-1]+f[i-2];
 f[93]:=9223372036854775807;
 for q:=1 to m do begin
  read(x,y);
  x:=x-1;
  ansx:=find(x);
  ansy:=find(y);
  writeln(ansy-ansx);
 end;
 close(input);close(output);
end.
