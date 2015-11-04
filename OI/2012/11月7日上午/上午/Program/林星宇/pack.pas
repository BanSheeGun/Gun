var a,b,cnt,maxv,n,k,ans,tmp,t,num,pri,vol,i,j,sum,numc:longint;
    p,v,kind,pot:array[1..10000]of longint;
    f:array[0..2000]of longint;
    h:array[1..200,0..2000]of longint;
function max(x,y:longint):longint;
begin
 if x>y then exit(x)
        else exit(y);
end;
begin
assign(input,'pack.in');reset(input);
assign(output,'pack.out');rewrite(output);
 readln(cnt,maxv);
 for i:=1 to cnt do
   begin
    read(k);
    if k=3 then
	begin
	 inc(n);
	 readln(p[n],v[n]);
         kind[n]:=3;
	end;
    if k=2 then
      begin
 	readln(pri,vol,num);
	t:=1;
        sum:=0;
	while true do
	  begin
           sum:=sum+t;
           if sum>num then
                begin
                 sum:=sum-t;
                 break;
                end;
           inc(n);
           kind[n]:=2;
           p[n]:=t*pri;
           v[n]:=t*vol;
           t:=t*2;
          end;

        if sum<>num then
         begin
          inc(n);
          kind[n]:=2;
          t:=num-sum;
          p[n]:=t*pri;
          v[n]:=t*vol;
         end;
      end;
    if k=1 then
       begin
         read(a,b);
	 inc(numc);
         inc(n);
         kind[n]:=1;
	 pot[n]:=numc;
         for j:=0 to maxv do
           h[numc][j]:=a*sqr(j)-b*j;
       end;
   end;
 for i:=1 to n do
  begin
   if kind[i]=3 then for j:=v[i] to maxv do
                        f[j]:=max(f[j],f[j-v[i]]+p[i]);
   if kind[i]=2 then for j:=maxv downto v[i] do
                        f[j]:=max(f[j],f[j-v[i]]+p[i]);
   if kind[i]=1 then
      begin
       t:=pot[i];
        for j:=0 to maxv do
          for k:=0 to j do
            f[j]:=max(f[j],f[j-k]+h[t][k]);
      end;
  end;
 ans:=0;
 for i:=0 to maxv do
  if f[i]>ans then ans:=f[i];
 writeln(ans);
close(input);
close(output);
end.
