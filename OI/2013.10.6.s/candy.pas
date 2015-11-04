var t:array[1..1000000] of longint;
    a:array[1..1000000] of longint;
    next:array[1..1000000] of longint;
    n,i,k,z,ans,max,m:longint;

function find(k:longint):boolean;
var i,q:longint;
begin
 q:=1;
 if next[k]<>0 then q:=next[k];
 for i:=q to max div k do
  if t[i*k]>0 then begin
   z:=i*k;
   next[k]:=i;
   exit(true);
  end;
 exit(false);
end;

begin
 assign(input,'candy.in');reset(input);
 assign(output,'candy.out');rewrite(output);
 read(n);
 max:=-maxlongint;
 fillchar(t,sizeof(t),false);
 for i:=1 to n do begin
  read(k);
  inc(t[k]);
  if k>max then max:=k;
 end;

 read(m);
 ans:=0;
 for i:=1 to m do begin
  read(k);
  if find(k) then begin
   inc(ans);
   a[ans]:=z;
   dec(t[z]);
  end
  else break;
 end;
 writeln(ans);
 for i:=1 to ans do writeln(a[i]);
 close(input);close(output);
end.
