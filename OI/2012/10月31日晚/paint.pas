var f:array[1..100,1..100] of longint;
    s:string;
    n,i,j,m,ans:longint;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

function d(l,r:longint):longint;
var tt:array['A'..'Z'] of boolean;
    zm:array[1..26] of char;
    m,i,p,lp,k:longint;
begin
 if f[l][r]<>0 then exit(f[l][r]);
 if l=r then begin f[l][r]:=1; exit;end;
 fillchar(tt,sizeof(tt),true);
 m:=0;
 for i:=l to r do begin
  if tt[s[i]] then begin
   tt[s[i]]:=false;
   inc(m);
   zm[m]:=s[i];
  end;
 end;

 f[l][r]:=maxlongint;
 for i:=1 to m do begin
  k:=0;
  p:=l;
  while p<=r do begin
   if s[p]=zm[i] then begin
    inc(p);
   end
   else begin
    lp:=p;
    while (s[p]<>zm[i]) do
    if p=r then break else
     begin inc(p); end;
    if s[p]=zm[i] then dec(p);
    inc(k,d(lp,p));
    inc(p);
   end;
  end;
  f[l][r]:=min(f[l][r],k);
 end;
 inc(f[l][r]);

 for i:=l to r-1 do
 f[l][r]:=min(f[l][r],d(l,i)+d(i+1,r));
 exit(f[l][r]);
end;

begin
assign(input,'paint.in');reset(input);
 assign(output,'paint.out');rewrite(output);
 ans:=maxlongint;
 readln(s);
 n:=length(s);
 ans:=d(1,n);
 writeln(ans);
 close(input);close(output);
end.
