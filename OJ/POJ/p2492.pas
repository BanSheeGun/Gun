var f,b:array[1..2010] of longint;
    test,i,tn,l,r,x,y,n,m:longint;
    ok:boolean;
function find(x:longint):longint;
var temp:longint;
begin
 if f[x]=-1 then exit(x);
 temp:=find(f[x]);
 b[x]:=b[x]+b[f[x]];
 b[x]:=b[x] mod 2;
 f[x]:=temp;
 exit(temp);
end;
begin
 read(test);
 for tn:=1 to test do begin
  fillchar(b,sizeof(b),0);
  read(n,m);
  ok:=true;
  fillchar(f,sizeof(f),255);
  for i:=1 to m do begin
   read(x,y);
   if (not ok) then continue;
   l:=find(x);
   r:=find(y);
   if l<>r then begin
    f[l]:=r;
    b[l]:=b[y]-b[x]+1;
    b[l]:=b[l] mod 2;
   end
   else begin
    if b[x]=b[y] then begin
     ok:=false;
    end;
   end;
  end;
  writeln('Scenario #',tn,':');
  if ok then writeln('No suspicious bugs found!')
  else writeln('Suspicious bugs found!');
  writeln;
 end;
end.
