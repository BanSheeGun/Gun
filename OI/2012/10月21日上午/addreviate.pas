var a:array[1..50] of string;
    i,n,k:longint;
    tp:string;
function jc(tp:string;k:longint):boolean;
var i:longint;
begin
 for i:=1 to n do
  if i<>k then begin
   if pos(tp,a[i])=1 then exit(false);
  end;
 exit(true);
end;
begin
 assign(input,'addreviate.in');reset(input);
 assign(output,'addreviate.out');rewrite(output);
 readln(n);
 for i:=1 to n do
 readln(a[i]);

 for i:=1 to n do begin
  for k:=1 to length(a[i]) do begin
   tp:=copy(a[i],1,k);
   if jc(tp,i) then break;
  end;
  writeln(tp);
 end;
 close(input);close(output);
end.
