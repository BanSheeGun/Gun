var ans,a,b,t,d:array[1..1000] of longint;
    n,m,k,i,j,aa:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'bus.in');reset(input);
 assign(output,'bus.out');rewrite(output);
 read(n,m,k);
 for i:=1 to n-1 do read(d[i]);
 for i:=1 to m do read(t[i],a[i],b[i]);
 fillchar(ans,sizeof(ans),0);
 for i:=2 to n do
 ans[i]:=ans[i-1]+d[i];
 for i:=1 to m do ans[a[i]]:=max(ans[a[i]],t[i]);
 aa:=0;
 for i:=1 to m do
  aa:=aa+ans[b[i]]-ans[a[i]];
 writeln(aa);
 close(input);close(output);
end.