program tournament(input,output);
var x,y,n,i,j,k,p,q,t,kk:longint;
    next,head,endpoint:array[0..100000] of longint;
    du:array[0..100000] of longint;
    v:array[0..100000] of boolean;
    check:boolean;

procedure filein;
begin
  assign(input,'tournament.in');
  assign(output,'tournament.out');
  reset(input);
  rewrite(output);
end;

procedure fileout;
begin
  close(input);
  close(output);
end;

function try(k:longint):boolean;
var p:longint;
begin
  if check then exit;
  if k=kk then
    begin
      check:=true;
      exit;
    end;
  p:=head[k];
  while p>0 do
    begin
      if v[endpoint[p]] then
        begin
          p:=next[p];
          continue;
        end;
      v[endpoint[p]]:=true;
      try(endpoint[p]);
      p:=next[p];
    end;
end;

begin
  filein;

  read(n);
  for i:=1 to n*(n-1) div 2-1 do
    begin
      read(x,y);
      endpoint[i]:=y;
      next[i]:=head[x];
      head[x]:=i;
      inc(du[x]);
      inc(du[y]);
    end;
  t:=0;
  for i:=1 to n do
    begin
      if du[i]=n-1 then continue;
      inc(t);
      if t=1 then p:=i;
      if t=2 then q:=i;
    end;
  fillchar(v,sizeof(v),false);
  v[q]:=true;
  check:=false;
  kk:=p;
  try(q);
  if check then writeln(q,' ',p) else writeln(p,' ',q);

  fileout;
end.
