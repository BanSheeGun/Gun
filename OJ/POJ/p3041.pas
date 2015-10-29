var a:array[1..500,1..500] of longint;
    t:array[1..500] of boolean;
    con:array[1..500] of longint;
    n,m,ans,i,x,y:longint;

function find(u:longint):boolean;
var i:longint;
begin
 for i:=1 to n do
  if (a[u][i]=1)and(t[i]=false) then begin
   t[i]:=true;
   if (con[i]=0)or(find(con[i])) then begin
    con[i]:=u;
    exit(true);
   end;
  end;
  exit(false);
end;

begin
 read(n,m);
 fillchar(a,sizeof(a),0);
 for i:=1 to m do begin
  read(x,y);
  a[x][y]:=1;
 end;

 ans:=0;
 for i:=1 to n do begin
  fillchar(t,sizeof(t),false);
  if find(i) then inc(ans);
 end;

 writeln(ans);
end.
