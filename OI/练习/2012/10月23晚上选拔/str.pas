var s,t:array[1..11] of string;
    need:array[1..11] of longint;
    d:array[1..100000] of string;
    d1:array[1..100000] of longint;
    f,p,m:longint;
    p1,p2:string;
procedure init;
var i,j,n:longint;
begin
 readln(p1);
 n:=pos(' ',p1);
 p2:=copy(p1,n+1,length(p1)-n);
 delete(p1,n,length(p1)-n+1);
 m:=0;
 while not eof do begin
  inc(m);
  readln(s[m]);
  n:=pos(' ',s[m]);
  t[m]:=copy(s[m],n+1,length(s[m])-n);
  delete(s[m],n,length(s[m])-n+1);
  need[m]:=1;
 end;

 n:=m;
 for i:=1 to n do
  for j:=1 to n do
   if i<>j then
    if t[i]=s[j] then begin
     inc(m);
     s[m]:=s[i];t[m]:=t[j];need[m]:=need[i]+need[j];
     if m=11 then exit;
    end;
end;
function max(a,b:longint):longint;
begin
 if a>b then exit(a)
        else exit(b);
end;
function pan(k:longint):boolean;
var i:longint;
begin
 for i:=k-1 downto max(1,k-10000) do
  if d[i]=d[k] then exit(true);
 exit(false);
end;
procedure work;
var i,k:longint;
    temp:string;
begin
 f:=1;p:=1;d[1]:=p1;
 d1[1]:=0;

 repeat
  for i:=1 to m do begin
   temp:=d[f];
   k:=pos(s[i],temp);
   while k<>0 do
    begin
     inc(p);
     d[p]:=d[f];
     d1[p]:=d1[f]+need[i];
     delete(d[p],k,length(s[i]));
     insert(t[i],d[p],k);
     if d[p]=p2 then begin writeln(d1[p]); exit; end;
     temp[k]:=' ';
     k:=pos(s[i],temp);
     if pan(p) then dec(p);
    end;
  end;

  inc(f);
 until (f>p)or(d1[f]>10);
 writeln('NO ANSWER');
end;
begin
 assign(input,'str.in');reset(input);
 assign(output,'str.out');rewrite(output);
 init;
 work;
 close(input);close(output);
end.
