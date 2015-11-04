var i,j,k,x,y,st,des,n,l:longint;
    can:boolean;
    a:array [0..60] of longint;
    g:array [0..60,0..60] of boolean;

procedure search(dep:longint);
var i:longint;
begin
  if can then exit;
  if dep=des then begin
                    can:=true;
                    exit;
                  end;
  for i:=1 to n do
    begin
      if g[i,dep] then search(i);
      if can then exit;
    end;
end;

begin
  assign(input,'tournament.in');
  assign(output,'tournament.out');
  reset(input);
  rewrite(output);
  readln(n);
  l:=n*(n-1) div 2-1;
  fillchar(g,sizeof(g),0);
  fillchar(a,sizeof(a),0);
  for i:=1 to l do
    begin
      read(x);
      readln(y);
      g[x,y]:=true;
      inc(a[x]);
      inc(a[y]);
    end;
  st:=0;
  des:=0;
  for i:=1 to n do
    if a[i]<n-1 then begin
                       if st=0 then st:=i
                               else des:=i;
                     end;
  can:=false;
  search(st);
  if can then writeln(des,' ',st)
         else writeln(st,' ',des);
  close(input);
  close(output);
end.