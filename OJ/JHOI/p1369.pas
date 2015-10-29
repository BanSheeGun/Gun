var f,a,b1,b2:array[0..300000] of longint;
    n,k,i,len,ml,ans:longint;

function find(l,r,k:longint):longint;
var mid:longint;
begin
 if l>r then exit(0);
 mid:=(l+r) shr 1;
 if (b1[mid]<k)and(b1[mid+1]>=k) then exit(mid);
 if k<=b1[mid] then exit(find(l,mid-1,k))
   else exit(find(mid+1,r,k));
 if l=r then exit(l);
end;

function find2(l,r,k:longint):longint;
var mid:longint;
begin
 if l>r then exit(0);
 mid:=(l+r) shr 1;
 if (b2[mid]<k)and(b2[mid+1]>=k) then exit(mid);
 if k<=b2[mid] then exit(find2(l,mid-1,k))
   else exit(find2(mid+1,r,k));
 if l=r then exit(l);
end;

begin
 read(n,k);
 for i:=1 to n do
  read(a[i]);
 fillchar(b1,sizeof(b1),63);
 fillchar(b2,sizeof(b2),63);
 fillchar(f,sizeof(f),0);
 ml:=0;
 for i:=1 to k do
  if (a[i]<a[k])or(i=k) then
  begin
   len:=find(1,ml,a[i]);
   f[i]:=len+1;
   inc(len);
   if len>ml then ml:=len;
   while (b1[len]>a[i])and(len>=1) do
    begin
     b1[len]:=a[i];
     dec(len);
    end;
  end;
 ans:=f[k];
 ml:=0;
 for i:=k+1 to n do
  if a[i]>a[k] then
   begin
   len:=find2(1,ml,a[i]);
   f[i]:=len+1;
   inc(len);
   if len>ml then ml:=len;
   while (b2[len]>a[i])and(len>=1) do
    begin
     b2[len]:=a[i];
     dec(len);
    end;
   end;
 ml:=0;
 for i:=k+1 to n do
  if f[i]>ml then ml:=f[i];
 writeln(ml+ans);
end.
