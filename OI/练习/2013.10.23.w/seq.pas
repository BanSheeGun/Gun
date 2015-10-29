const p=1000001;
var t:array[0..1000000] of longint;
    a,b,c,top,x:longint;
    ok:boolean;
function find(x:longint):boolean;
var now:longint;
begin
 now:=x mod p;
 while true do begin
  if t[now]=x then exit(true);
  if t[now]=0 then begin
   t[now]:=x;
   exit(false);
  end;
 end;
end;
begin
 assign(input,'seq.in');reset(input);
 assign(output,'seq.out');rewrite(output);
 read(a,b,c);
 top:=1;
 x:=1;
 t[1]:=1;
 ok:=false;
 while top<=2000000 do begin
  x:=(a*x+ x mod b) mod c;
  if find(x) then begin
   ok:=true;
   writeln(top);
   break;
  end;
  inc(top);
 end;
 if not ok then writeln(-1);
 close(input);close(output);
end.
