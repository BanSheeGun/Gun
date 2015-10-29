var a:array[1..100,1..300] of boolean;
    t:array[1..300] of boolean;
    c:array[1..300] of longint;
    i,j,n,m,y,k,ans:longint;

function find(u:longint):boolean;
var i:longint;
begin
 for i:=1 to m do
  if (a[u][i])and(t[i]=false) then begin
   t[i]:=true;
   if (c[i]=0) or (find(c[i])) then begin
    c[i]:=u;
    exit(true);
   end;
  end;
 exit(false);
end;

begin
 read(n,m);
 fillchar(a,sizeof(a),false);
 for i:=1 to n do begin
  read(k);
  for j:=1 to k do begin
   read(y);
   a[i][y]:=true;
  end;
 end;

 ans:=0;
 for i:=1 to n do begin
  fillchar(t,sizeof(t),false);
  if find(i) then inc(ans);
 end;

 writeln(ans);
end.
