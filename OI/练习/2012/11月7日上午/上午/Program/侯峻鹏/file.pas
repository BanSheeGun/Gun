const maxn=500;
      fb='|    ';
      fn='|----';
//
type treelink=^node;
     node=record
      data:integer;
      next:treelink;
end;
//
var names,tmp:array[0..maxn] of string;
    fa,val,num:array[0..maxn] of longint;
    hash:array[0..maxn shl 2] of longint;
    i,j,k,n,m,tot,l:longint;
    son:array[0..maxn] of treelink;
    p:treelink;
    st:string;
//
function calcval(st:string):longint;
var i,tmp:longint;
begin
 tmp:=0;
 for i:=1 to length(st) do
  if st[i] in ['a'..'z'] then inc(tmp,ord(st[i])-97)
                         else inc(tmp,ord(st[i])-46);
 exit(tmp);
end;
//
function find(st:string):longint;
var kao:longint;
begin
 kao:=calcval(st);
 while true do
  begin
   if names[hash[kao]]=st then exit(0);
   if names[hash[kao]]='' then exit(kao);
   inc(kao);
  end;
end;
//
function find1(st:string):longint;
var kao:longint;
begin
 kao:=calcval(st);
 while true do
  begin
   if names[hash[kao]]=st then exit(kao);
   inc(kao);
  end;
end;
//
procedure dfs(k,kao:integer);
var p:treelink;
    i:integer;
begin
 if fa[num[k]]<>0 then
  begin
   for i:=1 to kao-1 do write(fb);
   write(fn);
  end;
 writeln(names[k]);
 p:=son[num[k]];
 while p<>nil do
  begin
   dfs(p^.data,kao+1);
   p:=p^.next;
  end;
end;
//
begin
assign(input,'file.in'); reset(input);
assign(output,'file.out'); rewrite(output);
//
 for i:=1 to maxn do son[i]:=nil;
 for i:=1 to maxn do names[i]:='';
 fillchar(hash,sizeof(hash),0);
 fillchar(fa,sizeof(fa),0);
 tot:=0;
 readln(n);
 for i:=1 to n do
  begin
   readln(st);
   m:=0;
   k:=pos('/',st);
   while k<>0 do
    begin
     inc(m);
     tmp[m]:=copy(st,1,k-1);
     delete(st,1,k);
     k:=pos('/',st);
    end;
   inc(m);
   tmp[m]:=st;
   for j:=1 to m do
    begin
     l:=find(tmp[j]);
     if l=0 then continue;
     inc(tot);
     names[tot]:=tmp[j];
     num[tot]:=tot;
     val[tot]:=l;
     hash[val[tot]]:=tot;
     if j<>1 then fa[tot]:=hash[find1(tmp[j-1])];
    end;
  end;
//
 for i:=1 to tot-1 do
  for j:=i+1 to tot do
   if names[i]<names[j] then
    begin
     st:=names[i]; names[i]:=names[j]; names[j]:=st;
     m:=num[i]; num[i]:=num[j]; num[j]:=m;
    end;
//
 for i:=1 to tot do
  for j:=1 to tot do
   if fa[num[i]]=num[j]then
    begin
     new(p);
     p^.data:=i;
     p^.next:=son[num[j]];
     son[num[j]]:=p;
    end;
//
{ for i:=1 to tot do
  if son[num[i]]<>nil then
   begin
    write(names[i],'    ');
    p:=son[num[i]];
     while p<>nil do
      begin
       write(names[p^.data],' ');
       p:=p^.next;
      end;
    writeln;
  end; }

 for i:=1 to tot do
  if fa[num[i]]=0 then dfs(i,0);
//
close(input); close(output);
end.
