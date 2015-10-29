var x,l,w,y:array[1..10000] of longint;
    ans,i,n,xx,yy:longint;
function pan(i:longint):boolean;
begin
 if xx<x[i] then exit(false);
 if xx>x[i]+l[i] then exit(false);
 if yy<y[i] then exit(false);
 if yy>y[i]+w[i] then exit(false);
 exit(true);
end;
begin
 assign(input,'carpet.in');reset(input);
 assign(output,'carpet.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(x[i],y[i],l[i],w[i]);
 read(xx,yy);
 ans:=0;
 for i:=1 to n do
  if pan(i) then ans:=i;
 if ans=0 then writeln(-1)
          else writeln(ans);
 close(input);close(output);
end.