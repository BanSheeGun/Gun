var a,f,l:array[1..10000] of longint;
    i,j,top,ans,pp,ll:longint;
    ch:char;
procedure work(a:char);
begin
 if ('a'<=a)and(a<='z') then begin
  pp:=pp*36+ord(a)-ord('a')+10;
  inc(ll);
 end;
 if ('A'<=a)and(a<='Z') then begin
  pp:=pp*36+ord(a)-ord('A')+10;
  inc(ll);
 end;
 if ('0'<=a)and(a<='9') then begin
  pp:=pp*36+ord(a)-ord('0');
  inc(ll);
 end;
end;
function w(b:longint):longint;
var k:longint;
begin
 if b=1 then exit(36);
 k:=w(b div 2);
 k:=k*k;
 if b mod 2=1 then k:=k*36;
 exit(k mod 28);
end;
begin
 assign(input,'lovelttr.in');reset(input);
 assign(output,'lovelttr.out');rewrite(output);
 top:=0;
 pp:=0;
 while not eof do begin
  read(ch);
  work(ch);
  pp:=pp mod 28;
  if (ch='!')or(ch='.')or(ch='?')or eof then begin
   inc(top);
   a[top]:=pp;
   l[top]:=ll;
   pp:=0;
   ll:=0;
  end;
 end;
 if l[top]=0 then dec(top);
 fillchar(f,sizeof(f),0);
 ans:=0;
 for j:=1 to top do
  for i:=1 to top-j+1 do begin
   f[i]:=(f[i]*w(l[i+j-1]+1)+a[i+j-1]) mod 28;
   if f[i] mod 28=0 then
   inc(ans);
  end;
 writeln(ans);
 close(input);close(output);
end.
