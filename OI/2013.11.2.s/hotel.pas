var a,c:array[1..200000] of longint;
    now,sum:array[0..50] of longint;
    n,p,k,i,j:longint;
    ans:int64;

begin
 assign(input,'hotel.in');reset(input);
 assign(output,'hotel.out');rewrite(output);
 read(n,k,p);
 fillchar(sum,sizeof(sum),0);
 for i:=1 to n do begin
  read(a[i],c[i]);
  inc(sum[a[i]]);
 end;
 ans:=0;
 fillchar(now,sizeof(now),0);
 for i:=1 to n do begin
  inc(now[a[i]]);
  dec(sum[a[i]]);
  if c[i]<=p then begin
   for j:=0 to k-1 do
    ans:=ans+now[j]*sum[j];
   ans:=ans+now[a[i]]-1;
   fillchar(now,sizeof(now),0);
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
