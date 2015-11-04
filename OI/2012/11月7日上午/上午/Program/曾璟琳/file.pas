var i1,tt,max,i,n,j,k,jj:longint;
    ttt,s:string;
    t,m:array[1..10000]of longint;
    a:array[1..10000,1..10000]of string;
    f:boolean;
begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
readln(n);
max:=0;
for i:=1 to n do
 begin
   readln(s);
   j:=1;
   k:=0;
   for i1:=1 to length(s) do
    begin
      if s[i1]='/' then
        begin
         inc(k);
         ttt:=copy(s,j,i1-1);
         f:=true;
         for tt:=1 to t[k] do
           if a[k,tt]=ttt then begin f:=false;break;end;
         if f then begin a[k,t[k]+1]:= ttt;inc(t[k]);end;
         j:=i1+1;
        end;
      end;
    ttt:=copy(s,j,length(s));
    f:=true;
    for tt:=1 to t[k+1] do
      if a[k+1,tt]=ttt then begin f:=false;break;end;
    if f then begin a[k+1,t[k+1]+1]:=ttt;inc(t[k+1]);end;

    m[i]:=k+1;
    if m[i]>max then max:=m[i];
 end;
writeln(a[1,1]);
i:=2;
 for j:=1 to t[i]-1 do
  for jj:=j+1 to t[i] do
    if a[i,jj]<a[i,j] then
     begin ttt:=a[i,jj];a[i,jj]:=a[i,j];a[i,j]:=ttt;end;
for i:=1 to t[2] do
  writeln('|----',a[2,i]);
close(input);
close(output);
end.