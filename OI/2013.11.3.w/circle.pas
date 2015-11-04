var i,j,n,t,test:longint;
    ok:boolean;
    a:array[1..3000] of longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
function check(i,j:longint):boolean;
var l2,r2,l1,r1:longint;
    l3:qword;
begin
 l1:=min(a[i],a[i+1]);
 r1:=max(a[i],a[i+1]);
 l2:=min(a[j],a[j+1]);
 r2:=max(a[j],a[j+1]);
 if (l1<l2)and(l2<r1)and(r1<r2) then exit(true);
 if (l2<l1)and(l1<r2)and(r2<r1) then exit(true);
 exit(false);
end;
begin
 assign(input,'circle.in');reset(input);
 assign(output,'circle.out');rewrite(output);
 read(t);
 for test:=1 to t do begin
  read(n);
  for i:=1 to n do read(a[i]);
  ok:=true;
  for i:=2 to n-1 do begin
   for j:=1 to i-1 do
    if check(i,j) then begin
     ok:=false;
     break;
    end;
   if not ok then break;
  end;

  if not ok then writeln('yes')
  else writeln('no');
 end;
 close(input);close(output);
end.
