const n=43;
var x,y,ans:qword;
    lcm:array[0..n] of qword;
    b:array[0..n] of qword;
    i,j,k:longint;

function gcd(a,b:qword):qword;
var t:qword;
begin
  if a<b then begin t:=a; a:=b; b:=t; end;
  if b=0 then exit(a)
    else exit(gcd(b,a mod b));
end;

begin
  assign(input,'snaga.in');reset(input);
  assign(output,'snaga.out');rewrite(output);
  read(x,y);x:=x-1;
  lcm[1]:=1;
  for i:=2 to n-1 do
    lcm[i]:=lcm[i-1] div (gcd(lcm[i-1],int64(i)))*int64(i);
  for i:=2 to n-1 do begin
   b[i]:=1;
   j:=i;
   while j<>2 do begin
    for k:=2 to j do
     if j mod k<>0 then break;
    b[i]:=b[i]+1;
    j:=k;
    end;
   end;
  ans:=0;
  for i:=2 to n-1 do
   ans:=ans+((y div lcm[i-1]-y div lcm[i])-(x div lcm[i-1]-x div lcm[i]))*(b[i]+1);
  writeln(ans);
  close(input); close(output);
end.
