var an:string;
    n,i:longint;
procedure check;
var a,b,c,d:longint;
    t:boolean;
begin
 t:=false;
 for a:=1 to length(an)-3 do
  for b:=a+1 to length(an)-2 do
   for c:=b+1 to length(an)-1 do
    for d:=c+1 to length(an) do
  if ((an[a]=an[b])and(an[c]=an[d]))or((an[a]=an[d])and(an[c]=an[b])) then
  begin t:=true;break;end;
 if t then writeln('de1ete')
      else writeln('safe');
end;
begin
 readln(n);
 for i:=1 to n do begin
  readln(an);
  check;
 end;
end.
