var a,s:array[0..100000] of longint;
    now,ll,ans,n,i,ls:longint;
    sum:int64;
    ok:boolean;
begin
 assign(input,'sum.in');reset(input);
 assign(output,'sum.out');rewrite(output);
 read(n);
 for i:=1 to n do read(a[i]);
 now:=1;
 ans:=0;
 ls:=0;
 while now>ls do begin
  sum:=0;
  ok:=true;
  for i:=1 to n do begin
   sum:=sum+a[(now+i-2) mod n+1];
   s[i]:=sum;
   if sum<0 then begin
    ls:=now;
    now:=(now+i-1) mod n+1;
    ok:=false;
    break;
   end;
   
  end;
  if ok then begin
   inc(ans);
   inc(now);
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
