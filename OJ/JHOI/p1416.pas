var a:array['a'..'z'] of longint;
    ch:char;
    s:string;
    i,max,min:longint;
function check(k:longint):boolean;
var i:longint;
begin
 if k=0 then exit(false);
 if k=1 then exit(false);
 for i:=2 to trunc(sqrt(k)) do
  if k mod i=0 then exit(false);
 exit(true);
end;
begin
 readln(s);
 for i:=1 to length(s) do
  inc(a[s[i]]);

 max:=0;
 min:=maxlongint;
 for ch:='a' to 'z' do begin
  if a[ch]>max then max:=a[ch];
  if (a[ch]<>0)and(a[ch]<min) then min:=a[ch];
 end;

 if check(max-min) then begin writeln('Lucky Word');writeln(max-min) end
                   else begin writeln('No Answer');writeln(0);    end;
end.
