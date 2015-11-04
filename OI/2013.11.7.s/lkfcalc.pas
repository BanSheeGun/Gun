var fh:array[1..20] of char;
    ch:char;
    a:array[1..20] of longint;
    ans:array[1..1100000] of longint;
    t:array[1..1100000] of boolean;
    d,s:array[1..4100000] of longint;
    f,p,n,i,tmp,tmp2:longint;
function js(a,b:longint;fh:char):longint;
begin
 case fh of
  '+':exit(a+b);
  '-':exit(a-b);
  '*':exit(a*b);
 end;
end;
begin
 assign(input,'lkfcalc.in');reset(input);
 assign(output,'lkfcalc.out');rewrite(output);
 readln(n);
 for i:=1 to n-1 do
  read(a[i]);
 readln(a[n]);
 for i:=1 to n-1 do begin
  read(fh[i]);
  read(ch);
 end;
 for i:=1 to 1<<n-1 do 
  ans[i]:=-maxlongint div 2;
 f:=1;
 fillchar(t,sizeof(t),true);
 for p:=1 to n do begin
  d[p]:=1<<(p-1);
  s[p]:=1;
  ans[d[p]]:=a[p];
  t[d[p]]:=false;
 end;
 repeat
  for i:=1 to 20 do
   if (d[f]>>(i-1)) mod 2=0 then begin
    tmp:=js(ans[d[f]],a[i],fh[s[f]]);
    tmp2:=d[f] or (1<<(i-1));
    if tmp>ans[tmp2] then begin
     ans[tmp2]:=tmp;
     if t[tmp2] then begin
      inc(p);
      d[p]:=tmp2;
      s[p]:=s[f]+1;
      t[d[p]]:=false;
     end;
    end;
   end;
  t[d[f]]:=true;
  inc(f);
 until f>p;
 writeln(ans[1<<n-1]);
 close(input);close(output);
end.
