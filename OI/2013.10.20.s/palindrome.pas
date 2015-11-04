var st:ansistring;
    f:array[0..1001,0..1001] of longint;
    n,m,i,j,ans:longint;
begin
 assign(input,'palindrome.in');reset(input);
 assign(output,'palindrome.out');rewrite(output);
 readln(st);
 m:=length(st);
 while st[m]<>' ' do begin
  n:=n*10+ord(st[m])-ord('0');
  dec(m);
 end;
 dec(m);

 ans:=0;
 fillchar(f,sizeof(f),0);
 for j:=1 to m do
  for i:=1 to m-j+1 do begin
   if st[i]=st[i+j-1] then f[i,i+j-1]:=f[i+1][i+j-2]
                      else f[i,i+j-1]:=f[i+1][i+j-2]+1;
   if f[i][i+j-1]<=n then
    if j>ans then ans:=j;
  end;
 writeln(ans);
 close(input);close(output);
end.
