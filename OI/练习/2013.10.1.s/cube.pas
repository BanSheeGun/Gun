type arr=array[1..6] of longint;
var a:array[1..3,1..3,1..3] of longint=(((1,2,3),(4,5,6),(7,8,9)),
                                        ((10,11,12),(13,14,15),(16,17,18)),
                                        ((19,20,21),(22,23,24),(24,26,27)));
    ch:array[1..27] of longint;
    t:array[0..4,0..4,0..4] of boolean;
    fx:array[1..6] of longint=(0,1,0,0,-1,0);
    fy:array[1..6] of longint=(0,0,1,0,0,-1);
    fz:array[1..6] of longint=(1,0,0,-1,0,0);
    ok:boolean;
    i,j,k,la:longint;
    ans:array[1..3,1..3,1..3] of longint;
procedure sort(var n:arr;l,r,x,y,z:longint);
var i,j,mid,temp:longint;
begin
 i:=l;j:=r;mid:=n[(l+r) div 2];
 repeat
  while a[x+fx[n[i]]][y+fy[n[i]]][z+fz[n[i]]]<a[x+fx[mid]][y+fy[mid]][z+fz[mid]] do
   inc(i);
  while a[x+fx[mid]][y+fy[mid]][z+fz[mid]]<a[x+fx[n[j]]][y+fy[n[j]]][z+fz[n[j]]] do
   dec(j);
  if not(i>j) then begin
   temp:=n[i];n[i]:=n[j];n[j]:=temp;
   inc(i);dec(j);
  end;
  until i>j;
  if l<j then sort(n,l,j,x,y,z);
  if i<r then sort(n,i,r,x,y,z);
end;

procedure dfs(q,x,y,z,la:longint);
var i,top,xx,yy,zz:longint;
    ne:array[1..6] of longint;
begin
 if q=28 then begin ok:=true; exit; end;
 top:=0;
 if ch[q]=0 then begin
  xx:=x+fx[la];yy:=y+fy[la];zz:=z+fz[la];
  if t[xx][yy][zz]=true then begin
   t[xx][yy][zz]:=false;
   ans[xx][yy][zz]:=q;
   dfs(q+1,xx,yy,zz,la);
   t[xx][yy][zz]:=true;
  end;
 end
 else begin
  for i:=1 to 6 do begin
   xx:=x+fx[i];yy:=y+fy[i];zz:=z+fz[i];
   if (t[xx][yy][zz]=true)and(i<>la) then begin
    inc(top);
    ne[top]:=i;
   end;
  end;

  if top<>0 then begin
   sort(ne,1,top,x,y,z);
   for i:=1 to top do begin
    xx:=x+fx[ne[i]];yy:=y+fy[ne[i]];zz:=z+fz[ne[i]];
    if t[xx][yy][zz]=true then begin
     t[xx][yy][zz]:=false;
     ans[xx][yy][zz]:=q;
     dfs(q+1,xx,yy,zz,ne[i]);
     if ok then exit;
     t[xx][yy][zz]:=true;
    end;
   end;
  end;
 end;
end;

begin
 assign(input,'cube.in');reset(input);
 assign(output,'cube.out');rewrite(output);
 ans[1][1][1]:=1;ans[1][1][2]:=2;
 fillchar(t,sizeof(t),false);
 for i:=1 to 3 do
  for j:=1 to 3 do
   for k:=1 to 3 do begin
    t[i][j][k]:=true;
   end;
 t[1][1][1]:=false;t[1][1][2]:=false;la:=1;
 ok:=false;
 for i:=1 to 25 do read(ch[i+2]);
 dfs(3,1,1,2,1);
 if ok then
  for i:=1 to 3 do begin
   for j:=1 to 3 do begin
    for k:=1 to 2 do write(ans[i][j][k],' ');
    writeln(ans[i][j][3]);
   end;
   if i<>3 then writeln;
  end
 else writeln('No solution');
 close(input); close(output);
end.
