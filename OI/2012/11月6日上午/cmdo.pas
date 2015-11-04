var a:array[0..61,0..61] of char;
    b:array[1..60,1..60] of longint;
    t:array[1..15,1..15] of longint;
    sum:array[1..15] of longint;
    pan:array[1..15] of boolean;
    n,m,i,j,x,y,k,s,ans:longint;
    ch:char;
    f:array[0..33000] of longint;
function zt:longint;
var i:longint;
begin
 zt:=0;
 for i:=1 to s do
 if pan[i] then zt:=zt shl 1+1
           else zt:=zt shl 1
end;
function dfs(k,r:longint):longint;
var i,qq:longint;
begin
 dfs:=0;
 pan[k]:=false;
 for i:=1 to s do
  if t[k][i]=1 then dec(sum[i]);
 qq:=zt;
 if f[qq]<>0 then dfs:=f[qq] else begin
 if r=0 then inc(dfs)
 else begin
  for i:=1 to s do
   if (sum[i]=0)and(pan[i]) then dfs:=dfs+dfs(i,r-1);
 end;
 end;
 f[qq]:=dfs;
 pan[k]:=true;
 for i:=1 to s do
  if t[k][i]=1 then inc(sum[i]);
end;
begin
 assign(input,'cmdo.in');reset(input);
 assign(output,'cmdo.out');rewrite(output);
 readln(n,m);
 s:=0;
 for i:=1 to n do begin
  for j:=1 to m do begin
   read(a[i][j]);
   if (a[i][j]<>'#')and(a[i][j]<>'.') then begin
    inc(s);
    b[i][j]:=s;
   end;
  end;
  readln;
 end;

 fillchar(sum,sizeof(sum),0);
 for i:=1 to n do
  for j:=1 to m do  begin
  if (a[i][j]<>'#')and(a[i][j]<>'.') then begin
   k:=b[i][j];
   x:=i;y:=j;
   case a[i][j] of
    '<':begin
     while (y-1>0)and(a[x][y-1]<>'#') do begin
      dec(y);
      if (b[x][y]<>0) then begin
       t[k][b[x][y]]:=1;
       inc(sum[b[x][y]]);
      end;
     end;
    end;
    '>':begin
     while (y+1<=m)and(a[x][y+1]<>'#') do begin
      inc(y);
      if (b[x][y]<>0) then begin
       t[k][b[x][y]]:=1;
       inc(sum[b[x][y]]);
      end;
     end;
    end;
    'v':begin
     while (x+1<=n)and(a[x+1][y]<>'#') do begin
      inc(x);
      if (b[x][y]<>0) then begin
       t[k][b[x][y]]:=1;
       inc(sum[b[x][y]]);
      end;
     end;
    end;
    '^':begin
     while (x-1>0)and(a[x-1][y]<>'#') do begin
      dec(x);
      if (b[x][y]<>0) then begin
       t[k][b[x][y]]:=1;
       inc(sum[b[x][y]]);
      end;
     end;
    end;
   end;
  end;
 end;
 ans:=0;
 for i:=1 to s do
 if sum[i]=0 then begin
  fillchar(pan,sizeof(pan),true);
  inc(ans,dfs(i,s-1));
 end;
 if ans=0 then writeln('Impossible')
          else writeln(ans);
 close(input);close(output);
end.
