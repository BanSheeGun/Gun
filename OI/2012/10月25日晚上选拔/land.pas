var a:array[1..50,1..4] of longint;
    w,h,n,i:longint;
    ans:qword;
function kl(i,j:longint):boolean;
var k1,k2,b1,b2,x,y:extended;
begin
 if a[i][1]=a[i][3] then begin
  if a[j][1]=a[j][3] then exit(false);
  if (a[j][1]<a[i][1])and(a[j][3]<a[i][1]) then exit(false);
  if (a[j][1]>a[i][1])and(a[j][3]>a[i][1]) then exit(false);
  exit(true);
 end
 else begin
  if a[j][1]=a[j][3] then begin
   if (a[i][1]<=a[j][1])and(a[i][3]<=a[j][1]) then exit(false);
   if (a[i][1]>=a[j][1])and(a[i][3]>=a[j][1]) then exit(false);
   exit(true);
  end;

  k1:=(a[i][2]-a[i][4])/(a[i][1]-a[i][3]);
  b1:=a[i][2]-k1*a[i][1];
  k2:=(a[j][2]-a[j][4])/(a[j][1]-a[j][3]);
  b2:=a[j][2]-k2*a[j][1];
  if k1=k2 then exit(false);
  x:=(b2-b1)/(k1-k2);
  y:=k1*x+b1;
  if (x>0)and(y>0)and(x<w)and(y<h) then exit(true)
                       else exit(false);
 end;
end;
function pd(k:longint):qword;
var an,i:longint;
begin
 an:=0;
 for i:=1 to k-2 do
 if kl(k,i) then inc(an);
 exit(an);
end;
begin
 assign(input,'land.in');reset(input);
 assign(output,'land.out');rewrite(output);
 read(w,h);
 read(n);
 for i:=1 to n do
  read(a[i][1],a[i][2]);

 read(a[n][3],a[n][4]);
 for i:=1 to n-1 do begin
  a[i][3]:=a[i+1][1];
  a[i][4]:=a[i+1][2];
 end;

 ans:=1;
 for i:=1 to n do
  ans:=ans+1+pd(i);

 writeln(ans);
 close(input);close(output);
end.
