var next,last:array[1..5000] of longint;
    la,num:array['A'..'Z'] of longint;
    c:array[1..5000] of char;
    ch:char;
    t:boolean;
    l,r,m,n,i,q,rq,ans,cost:longint;
begin
 assign(input,'ball.in');reset(input);
 assign(output,'ball.out');rewrite(output);
 read(ch);
 m:=0;
 while ('A'<=ch)and(ch<='Z') do begin
  inc(m);
  c[m]:=ch;
  inc(num[ch]);
  if la[ch]<>0 then next[la[ch]]:=m;
  next[m]:=0;
  last[m]:=la[ch];
  la[ch]:=m;
  read(ch);
 end;
 read(n);

 ans:=0;
 for i:=1 to m do
 if num[c[i]]>ans then begin
  l:=i;r:=i;
  cost:=0;q:=1;
  t:=false;
  repeat
   if last[l]=0 then break;
   l:=last[l];
   cost:=cost+i-l-q;
   if cost>n then break;
   inc(q);
  until cost>=n;
  rq:=0;
  while cost>n do begin
   cost:=cost-(i-l-q);
   l:=next[l];
  end;
  if q>ans then ans:=q;
  repeat
   r:=next[r];
   if r=0 then break;
   inc(rq);
   cost:=cost+r-i-rq;
   while cost>n do begin
    cost:=cost-(i-l-q);
    l:=next[l];
    if l>i then break;
    dec(q);
   end;
   if (rq+q>ans)and(cost<=n) then ans:=rq+q;
  until l>i;
 end;

 writeln(ans);
 close(input);close(output);
end.
