program file_(input,output);
type filetype=record
       name:string[20];
       key:longint;
     end;
var n,i,j,k,p,index:longint;
    str:array[0..55] of ansistring;
    filei:array[0..100000] of filetype;
    parent:array[0..1000,0..1000] of longint;
    temp:string;
    check:boolean;

procedure filein;
begin
  assign(input,'file.in');
  assign(output,'file.out');
  reset(input);
  rewrite(output);
end;

procedure fileout;
begin
  close(input);
  close(output);
end;

procedure sort(l,r:longint);
var i,j:longint;
    x,y:ansistring;
begin
  i:=l;
  j:=r;
  x:=str[(l+r) div 2];
  repeat
    while str[i]<x do
    inc(i);
    while x<str[j] do
    dec(j);
    if not(i>j) then
      begin
        y:=str[i];
        str[i]:=str[j];
        str[j]:=y;
        inc(i);
        dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

procedure print(k,step:longint);
var i:longint;
begin
  if k=0 then exit;
  for i:=1 to step-2 do write('|    ');
  if step>1 then write('|----');
  writeln(filei[k].name);
  for i:=1 to parent[k][0] do print(parent[k][i],step+1);
end;

begin
  filein;

  readln(n);
  for i:=1 to n do readln(str[i]);
  sort(1,n);
  k:=0;
  for i:=1 to n do
    begin
      p:=1;
      while length(str[i])>0 do
        begin
          check:=true;
          index:=pos('/',str[i]);
          if index=0 then index:=length(str[i])+1;
          temp:=copy(str[i],1,index-1);
          delete(str[i],1,index);
          for j:=1 to k do
            if filei[j].name=temp then
              begin
                check:=false;
                break;
              end;
          if check then
            begin
              inc(k);
              filei[k].name:=temp;
              filei[k].key:=k;
              index:=filei[k].key;
            end;
          if not check then index:=filei[j].key;
          if index=1 then continue;
          j:=parent[p][0];
          while (j>0)and(parent[p][j]<>index) do dec(j);
          //if index=parent[p][parent[p][0]] then continue;
          if j>0 then
            begin
              p:=index;
              continue;
            end;
          inc(parent[p][0]);
          parent[p][parent[p][0]]:=index;
          p:=index;
        end;
    end;
  print(1,1);

  fileout;
end.

