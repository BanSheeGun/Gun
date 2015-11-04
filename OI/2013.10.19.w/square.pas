var a:array[0..1000,0..1000] of boolean;
    f:array[0..1000,0..1000] of longint;
    ch:char;
    n,i,j,x,y,z,ans:longint;

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
 fillchar(a,sizeof(a),false);
 for i:=1 to n do begin
  for j:=1 to n do begin
   read(ch);
   if ch='1' then a[i][j]:=true;
  end;
  readln;
 end;

 ans:=0;
 for i:=1 to n do
  for j:=1 to n do
  if a[i][j] then begin
   f[i][j]:=1;
   z:=min(f[i-1][j],f[i][j-1]);
   z:=min(z,f[i-1][j-1]);
   f[i][j]:=max(f[i][j],z+1);
   ans:=max(ans,f[i][j]);
  end;
 writeln(ans*ans);
 close(input);close(output);
end.
