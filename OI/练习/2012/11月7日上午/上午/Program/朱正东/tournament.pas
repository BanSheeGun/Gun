program ex;
var w,f,b:array[1..1000] of longint;
    a:array[1..1000,0..1000] of longint;
    i,j,n,m,x,y:longint;
begin
 assign(input,'tournament.in');reset(input);
 assign(output,'tournament.out'); rewrite(output);
 fillchar(a,sizeof(a),0);
 read(n);
 for i:=1 to n do b[i]:=0;
 m:=n*(n-1) div 2-1;
 for i:=1 to m do a[i,i]:=10000;
 for i:=1 to m do
   begin
     read(w[i],f[i]);
     a[w[i],f[i]]:=1;
     a[f[i],w[i]]:=1;
     readln;
   end;
   b[w[1]]:=1; b[f[1]]:=2;
   for i:=2 to m do
   b[f[i]]:=b[w[i]]+1;
 for i:=1 to n do
 for j:=1 to n do
   if a[i,j]=0 then begin x:=i; y:=j; break; end;
   if b[x]<b[y] then writeln(x,' ',y)
                else writeln(y,' ',x);
close(input); close(output);
end.
