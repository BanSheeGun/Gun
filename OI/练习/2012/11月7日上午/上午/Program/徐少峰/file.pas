type node=record
      cou:integer;
      son:array[1..15]of string;
      num:array[1..15]of integer;
     end;

var _:array[1..500]of string;
    handicapped:array[1..500]of node;
    x,y,top,n,i,j:longint;
    tmp,st:string;

function check(st:string):longint;
 var i:integer;
 begin
  check:=0;
  for i:=1 to top do
   if _[i]=st then exit(i);
 end;

procedure print(xx,dep:longint);
 var i,j:integer;
 begin
  for i:=1 to dep-2 do write('|    ');
  if dep-1>0 then write('|----');
  writeln(_[xx]);

  for i:=1 to handicapped[xx].cou-1 do
   for j:=i+1 to handicapped[xx].cou do
    if handicapped[xx].son[i]>handicapped[xx].son[j] then
    begin
     tmp:=handicapped[xx].son[i];handicapped[xx].son[i]:=handicapped[xx].son[j];handicapped[xx].son[j]:=tmp;
     x:=handicapped[xx].num[i];handicapped[xx].num[i]:=handicapped[xx].num[j];handicapped[xx].num[j]:=x;
    end;

  for i:=1 to handicapped[xx].cou do
   print(handicapped[xx].num[i],dep+1);
 end;

begin
assign(input,'file.in');reset(input);
assign(output,'file.out');rewrite(output);
readln(n);
for i:=1 to n do
 begin
  readln(st);y:=0;
  while (pos('/',st)<>0)or(st<>'') do
   begin
    if pos('/',st)<>0 then
    begin
    x:=pos('/',st);
    tmp:=copy(st,1,x-1);
    delete(st,1,x);
    end else
    begin
     tmp:=st;
     delete(st,1,length(st));
    end;
    x:=check(tmp);
    if x=0 then
     begin
      inc(top);
      _[top]:=tmp;
      handicapped[top].cou:=0;
      fillchar(handicapped[top].num,sizeof(handicapped[top].num),0);
      x:=top;
      if y=0 then y:=x
             else begin
                   inc(handicapped[y].cou);
                   handicapped[y].son[handicapped[y].cou]:=tmp;
                   handicapped[y].num[handicapped[y].cou]:=x;
                   y:=x;
                  end
     end else y:=x;
   end;
 end;

print(1,1);
close(input);close(output);
end.
