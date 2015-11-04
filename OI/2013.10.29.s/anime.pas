var f,ans:array[0..10000] of int64;
    s,l,v:array[1..1000] of longint;
    n,m,i,j,k,ls,ans:longint;
function max(a,b:int64):int64;
begin
 if a>b then exit(a);
 exit(b);
end;

procedure sort(l,r:longint);
var i,j,p,q:longint;
begin
 i:=l;j:=r;
 q:=s[(l+r) div 2];
 repeat
  while (s[i]<q) do inc(i);
  while (q<s[j]) do dec(j);
  if not(i>j) then begin
   y:=s[i];s[i]:=s[j];s[j]:=y;
   y:=l[i];l[i]:=l[j];l[j]:=y;
   y:=v[i];v[i]:=v[j];v[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;


begin
 assign(input,'anime.in');reset(input);
// assign(output,'anime.out');rewrite(output);
 read(n,m);
 fillchar(f,sizeof(f),0);
 for i:=1 to m do read(s[i],l[i],v[i]);
 sort(1,m);
 ans:=0;ls:=-maxlongint;
 for i:=1 to m do begin
  for j:=1 

  ls:=s[i]+l[i]-1;
  s
 end;
 for i:=0 to n do f[n]:=max(f[n],f[i]);
 writeln(f[n]);
 close(input);close(output);
end.
