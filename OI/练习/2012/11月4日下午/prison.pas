type cw=record
      x,y,z:longint;
     end;
var a,b:array[1..100001] of cw;
    n,m,l,r,mid,i:longint;
    jh:array[1..20001] of longint;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r)>>1].z;
 repeat
  while a[i].z<x do inc(i);
  while x<a[j].z do dec(j);
  if i<=j then begin
   a[100001]:=a[i];a[i]:=a[j];a[j]:=a[100001];
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;

procedure sort1(l,r:longint);
var i,j,x:longint;
begin
 i:=l;j:=r;
 x:=b[(l+r)>>1].x;
 repeat
  while b[i].x<x do inc(i);
  while x<b[j].x do dec(j);
  if i<=j then begin
   b[100001]:=b[i];b[i]:=b[j];b[j]:=b[100001];
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
function check(k:longint):boolean;
var i:longint;
begin
 fillchar(jh,sizeof(jh),0);
 b:=a;
 sort1(k+1,m);
 for i:=k+1 to m do begin
  if (jh[b[i].x]=0)and(jh[b[i].y]=0) then begin jh[b[i].x]:=1;jh[b[i].y]:=2; end;
  if (jh[b[i].x]=1)and(jh[b[i].y]=0) then begin jh[b[i].y]:=2; end;
  if (jh[b[i].x]=1)and(jh[b[i].y]=1) then begin exit(false); end;
  if (jh[b[i].x]=2)and(jh[b[i].y]=0) then begin jh[b[i].y]:=1; end;
  if (jh[b[i].x]=2)and(jh[b[i].y]=2) then begin exit(false);end;
 end;
 exit(true);
end;
begin
 assign(input,'prison.in');reset(input);
 assign(output,'prison.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(a[i].x,a[i].y,a[i].z);
  if a[i].x>a[i].y then begin l:=a[i].x;a[i].x:=a[i].y;a[i].y:=l;end;
 end;
 sort(1,m);
 l:=1;r:=m;
 while l<r-1 do begin
  mid:=(l+r)>>1;
  if check(mid) then r:=mid
                else l:=mid;
 end;
 if check(l) then writeln(a[l].z)
             else writeln(a[r].z);
 close(input);close(output);
end.
