var a,c:array[1..200000] of longint;
    now,sum:array[0..50] of longint;
    n,p,k,i,j,q:longint;
    ans:int64;
   ok:boolean;
begin
 assign(input,'hotel.in');reset(input);
 assign(output,'hotel1.out');rewrite(output);
 read(n,k,p);
 fillchar(sum,sizeof(sum),0);
 for i:=1 to n do begin
  read(a[i],c[i]);
  inc(sum[a[i]]);
 end;
 ans:=0;
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if a[i]=a[j] then begin
   ok:=false;
   for q:=i to j do
    if c[q]<=p then begin
     ok:=true;break;
    end;
  if ok then inc(ans);
  end;
 writeln(ans);
 close(input);close(output);
end.
