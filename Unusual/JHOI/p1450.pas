type cw=record
      x,y,z:longint;
     end;
var a,b:array[1..200001] of cw;
    n,m,l,r,x,y,mid,i:longint;
    jh:array[1..400001] of longint;
    t:boolean;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r)>>1].z;
 repeat
  while a[i].z>x do inc(i);
  while x>a[j].z do dec(j);
  if i<=j then begin
   a[100001]:=a[i];a[i]:=a[j];a[j]:=a[100001];
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;

function find(x:longint):longint;
begin
 if jh[x]<>x then jh[x]:=find(jh[x]);
 exit(jh[x]);
end;
begin
 read(n,m);
 for i:=1 to m do begin
  read(a[i].x,a[i].y,a[i].z);
  if a[i].x>a[i].y then begin l:=a[i].x;a[i].x:=a[i].y;a[i].y:=l;end;
 end;
 sort(1,m);
 t:=false;
    for i:=1 to n*2 do
        jh[i]:= i;
    for i:=1 to m do
    begin
        x:= find(a[i].x);
        y:= find(a[i].y);
        if (x=y) then begin
         t:=true;   break; end;
        jh[x]:= find(a[i].y+n);
        jh[y]:= find(a[i].x+n);
    end;
 if t then  writeln(a[i].z)
      else writeln(0);
end.
