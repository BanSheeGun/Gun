var a,b:array[1..3000] of longint;
    t:array[1..3000] of boolean;
    n,i,t1,t2,ca:longint;
    ok,oo:boolean;
procedure sort(l,r:longint);
var i,j,p,q:longint;
begin
 i:=l;j:=r;
 q:=b[(l+r) div 2];
 repeat
  while (b[i]<q) do inc(i);
  while (q<b[j]) do dec(j);
  if not(i>j) then begin
   p:=a[i];a[i]:=a[j];a[j]:=p;
   p:=b[i];b[i]:=b[j];b[j]:=p;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;
begin
 assign(input,'game.in');reset(input);
 assign(output,'game.out');rewrite(output);
 read(n);
 for i:=1 to n do read(a[i],b[i]);
 sort(1,n);
 ok:=false;
 t2:=0;ca:=0; t1:=0;
 fillchar(t,sizeof(t),true);
 while true do begin
  while b[t2+1]<=ca do begin
   inc(t2);
   if t[t2] then ca:=ca+2
            else ca:=ca+1;
   if t2=n then begin
    ok:=true;
    break;
   end;
  end;
  if ok then break;
  oo:=true;
  for i:=1 to n do
   if (t[i])and(a[i]<=ca) then begin
    oo:=false;
    break;
   end;
  if oo then break;
  inc(t1);
  t[i]:=false;
  inc(ca);
 end;
 if ok then writeln(t1+t2)
       else writeln('Too Bad');
 close(input);close(output);
end.
