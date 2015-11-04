var f:array[0..7000] of longint;
    v,t:array[1..100000] of longint;
    mt,ans,n,i,j,ls,sum:longint;
procedure sort(l,r:longint);
var i,j,mid,y,m2:longint;
begin
 i:=l;j:=r;mid:=t[(l+r) div 2];
 m2:=v[(l+r) div 2];
 repeat
  while (t[i]<mid)or(t[i]=mid)and(v[i]>m2) do inc(i);
  while (mid<t[j])or(t[j]=mid)and(m2>v[j]) do dec(j);
  if i<=j then begin
   y:=t[i];t[i]:=t[j];t[j]:=y;
   y:=v[i];v[i]:=v[j];v[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
begin
 assign(input,'homework.in');reset(input);
 assign(output,'homework.out');rewrite(output);
 read(n);
 for i:=1 to n do begin
  read(t[i],v[i]);
  if t[i]>mt then mt:=t[i];
 end;
 sort(1,n);
 ls:=0;sum:=0;
 for i:=1 to n do
  if (t[i]=ls) and(sum<ls)  or(t[i]<>ls) then  begin
  if t[i]<>ls then begin sum:=1; ls:=t[i] end
              else inc(sum);
   for j:=t[i] downto 1 do
    if f[j]<f[j-1]+v[i] then f[j]:=f[j-1]+v[i];
 end;

 for i:=1 to mt do
  if f[i]>ans then ans:=f[i];
 writeln(ans);
 close(input);close(output);
end.
