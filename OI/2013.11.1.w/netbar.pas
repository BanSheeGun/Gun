var a:array[1..200,1..200] of extended;
    t:array[1..200,1..200] of boolean;
    aa,ans,ll:extended;
    i,j,k,n:longint;
    st:string;
    x,y:array[1..200] of longint;
    ma:array[1..200] of extended;
function min(a,b:extended):extended;
begin
 if a<b then exit(a);
 exit(b);
end;
function max(a,b:extended):extended;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'netbar.in');reset(input);
 assign(output,'netbar.out');rewrite(output);
 readln(n);
 for i:=1 to n do
  readln(x[i],y[i]);
 for i:=1 to n do begin
  readln(st);
  for j:=1 to n do begin
   a[i][j]:=1e30;
   t[i][j]:=false;
   if st[j]='1' then begin
    t[i][j]:=true;
    a[i][j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
   end;
  end;
 end;
 for i:=1 to n do begin
  t[i][i]:=true;
  a[i][i]:=0;
 end;
 for k:=1 to n do
  for i:=1 to n do
   if i<>k then
    for j:=1 to n do
     if (j<>i)and(j<>k) then begin
      a[i][j]:=min(a[i][j],a[i][k]+a[k][j]);
      t[i][j]:=t[i][j] or (t[i][k] and t[k][j]);
     end;

 for i:=1 to n do begin
  ma[i]:=0;
  for j:=1 to n do
   if t[i][j] then
   ma[i]:=max(ma[i],a[i][j]);
 end;
 ans:=1e30;
 for i:=1 to n do
  for j:=1 to n do
   if t[i][j]=false then begin
    ll:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
    aa:=ll+ma[i]+ma[j];
    ans:=min(ans,aa);
   end;
 writeln(ans:0:6);
 close(input);close(output);
end.
