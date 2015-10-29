var f,fl:array[-6100..6100] of longint;
    d:array[1..1000] of longint;
    st,a,b,ans,i,j,n:longint;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
begin
 assign(input,'domino.in');reset(input);
 assign(output,'domino.out');rewrite(output);
 read(n);
 for i:=1 to n do begin
  read(a,b);
  d[i]:=a-b;
 end;
 st:=0;
 for i:=1 to n do
  st:=d[i]+st;

 fillchar(f,sizeof(f),63);
 f[st]:=0;
 ans:=f[-6100];
 for i:=1 to n do begin
  fl:=f;
  for j:=-6000 to 6000 do
   f[j]:=min(f[j],fl[j+2*d[i]]+1);
 end;

 for i:=-6000 to 6000 do
  if (abs(i)<=abs(j))and(f[i]<>ans) then j:=i;
 writeln(f[j]);
 close(input);close(output);
end.
