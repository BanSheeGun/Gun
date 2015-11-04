var a,b:array[1..1000000] of longint;
    t,ll,rr,s:array[1..1400000] of longint;
    ans,i,j,n,m,day:longint;
procedure sort(l,r: longint);
var i,j,x,y,z:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r) div 2];
 repeat
  while (a[i]<x) do inc(i);
  while (x<a[j]) do dec(j);
  if not(i>j) then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   y:=b[i];b[i]:=b[j];b[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

procedure build(k,l,r:longint);
begin
 ll[k]:=l;rr[k]:=r;
 if ll[k]<>rr[k] then begin
  build(k*2,l,(l+r)>>1);
  build(k*2+1,(l+r)>>1+1,r);
 end
end;

procedure ec(k,q,w:longint);
var mid:longint;
begin
 if ll[k]=rr[k] then begin
  s[k]:=w;
  t[k]:=b[w];
  exit;
 end;
 mid:=(ll[k]+rr[k]) div 2;
 if q<=mid then ec(k*2,q,w)
           else ec(k*2+1,q,w);
 s[k]:=s[k*2];
 t[k]:=t[k*2];
 if t[k*2+1]<>0 then begin
  if t[k*2+1]<t[k] then begin
   t[k]:=t[k*2+1];
   s[k]:=s[k*2+1];
  end;
 end;
end;

begin
 assign(input,'homework.in');reset(input);
 assign(output,'homework.out');rewrite(output);

 m:=0;
 read(n);
 for i:=1 to n do begin
  read(a[i],b[i]);
  if a[i]>m then m:=a[i];
 end;
 sort(1,n);
 build(1,1,m);
 day:=0;
 ans:=0;
 for i:=1 to n do begin
  if day<a[i] then begin
   inc(day);
   ec(1,day,i);
   ans:=ans+b[i];
  end else begin
   if t[1]<b[i] then begin
    ans:=ans-t[1]+b[i];
    ec(1,s[1],i);
   end;
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
