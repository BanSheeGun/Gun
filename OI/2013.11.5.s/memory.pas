var st:string;
    uu,dd,u,d,s,t,n,i,de,nn:longint;
    ok:boolean;
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
function check:boolean;
var h:longint;
begin
 for i:=1 to length(st) do begin
  if uu<u then exit(false);
  if dd<d then exit(false);
  if st[i]='U' then begin
   dec(u);
   h:=uu;
   uu:=u;
   s:=s+h-uu;
  end
  else begin
   dec(d);
   h:=dd;
   dd:=max(d,dd-s);
   s:=s-h+dd;
  end;
 end;
 if uu>0 then exit(false);
 if dd>0 then exit(false);
 if u>0 then exit(false);
 if d>0 then exit(false);
 exit(true);
end;
begin
 assign(input,'memory.in');reset(input);
 assign(output,'memory.out');rewrite(output);
 while not eof do begin
  readln(n,s,t);
  readln(st);
  u:=0;d:=0;
  for i:=1 to length(st) do
   if st[i]='U' then inc(u)
                else inc(d);
  de:=s-t;
  nn:=n-de;
  if nn mod 2=1 then ok:=false
  else begin
   uu:=nn div 2;
   dd:=(n+de) div 2;
   ok:=check;
  end;
  if ok then writeln('YES')
        else writeln('NO');
 end;
 close(input);close(output);
end.
