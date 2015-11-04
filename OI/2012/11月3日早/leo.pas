var t:array[0..120,0..120,0..60,0..60] of boolean;
    d:array[1..4,1..10000000] of longint;
    a:array[1..16] of longint;
    n,i,sum,f,p,j,ans,k:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r) div 2];
 repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
  if i<=j then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;

function pan(a,b,c,d:longint):boolean;
var i:longint;
begin
 if (a>120)or(b>120)or(c>60)or(d>60) then exit(false);
 if not t[a][b][c][d] then exit(false);
 if (a<>0)and((d>a)and(c>a)) then exit(false);
 if (b<>0)and((d>b)and(c>b)) then exit(false);
 if (c>d)and(d<>0) then exit(false);
 if (a>b)and(b<>0) then exit(false);
 t[a][b][c][d]:=false;
 exit(true);
end;
begin
 assign(input,'leo.in');reset(input);
 assign(output,'leo.out');rewrite(output);
 read(n);
  for i:=1 to n do read(a[i]);
 sort(1,n);
 fillchar(t,sizeof(t),true);
 t[0][0][0][0]:=false;
 f:=1;p:=1;
 for i:=1 to n do begin
  f:=p;
  for k:=1 to f do
   for j:=1 to 4 do begin
     inc(p);
     d[1][p]:=d[1][k];
     d[2][p]:=d[2][k];
     d[3][p]:=d[3][k];
     d[4][p]:=d[4][k];
     d[j][p]:=d[j][p]+a[i];
     if not pan(d[1][p],d[2][p],d[3][p],d[4][p]) then dec(p);
     if (d[1][p]=d[2][p])and(d[3][p]=d[4][p]) then
      if d[1][p]*d[3][p]>ans then ans:=d[1][p]*d[3][p];
    end;
 end;

 if ans=0 then writeln('No Solution')
          else writeln(ans);
 close(input);close(output);
end.
