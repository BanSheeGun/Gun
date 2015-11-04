var a,f:array[0..1000,0..1000] of longint;
    i,j,n,ans:longint;
    ch:char;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
begin
 assign(input,'square.in');reset(input);
 assign(output,'square.out');rewrite(output);
 readln(n);
 for i:=1 to n do begin
  for j:=1 to n do begin
   read(ch);
   a[i][j]:=ord(ch)-48;
  end;
  readln;
 end;

 ans:=0;
 for i:=1 to n do
  for j:=1 to n do
   if a[i][j]=1 then begin
    f[i][j]:=min(f[i-1][j-1],f[i][j-1]);
    f[i][j]:=min(f[i][j],f[i-1][j]);
    inc(f[i][j]);
    ans:=max(ans,f[i][j]);
   end;

  writeln(ans*ans);
 close(input);close(output);
end.
