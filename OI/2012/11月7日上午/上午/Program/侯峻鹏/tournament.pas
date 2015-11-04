const maxn=51;
//
var inp,outp,r:array[0..maxn] of longint;
    i,j,k,n:longint;
    eg:array[0..maxn,0..maxn] of boolean;
    ok:boolean;
//
function check:boolean;
var tmp,stack:array[0..maxn] of longint;
    now,i,top:longint;
begin
 tmp:=inp;
 top:=0;
 for i:=1 to n do
  if tmp[i]=0 then
   begin
    inc(top);
    stack[top]:=i;
    tmp[i]:=-1;
   end;
 while top<>0 do
  begin
   now:=stack[top];
   dec(top);
   for i:=1 to n do
    if (eg[now,i])and(tmp[i]>0) then
     begin
      dec(tmp[i]);
      if tmp[i]=0 then
       begin
        inc(top);
        stack[top]:=i;
        tmp[i]:=-1;
       end;
     end;
   end;
 for i:=1 to n do
  if tmp[i]<>-1 then exit(false);
 exit(true);
end;
//
begin
assign(input,'tournament.in'); reset(input);
assign(output,'tournament.out'); rewrite(output);
//
 read(n);
 fillchar(eg,sizeof(eg),false);
 fillchar(inp,sizeof(inp),0);
 fillchar(outp,sizeof(outp),0);
 for i:=1 to n*(n-1) shr 1-1 do
  begin
   read(r[1],r[2]);
   eg[r[1],r[2]]:=true;
   inc(inp[r[2]]);
   inc(outp[r[1]]);
  end;
 r[0]:=0;
 for i:=1 to n do
  if inp[i]+outp[i]<>n-1 then
   begin
    inc(r[0]);
    r[r[0]]:=i;
   end;
//
 ok:=false;
 for i:=1 to r[0] do
  begin
   if ok then break;
   for j:=1 to r[0] do
    if (i<>j) then
     begin
      inc(inp[r[j]]);
      eg[r[i],r[j]]:=true;
      if check then
       begin
        ok:=true;
        writeln(r[i],' ',r[j]);
        break;
       end;
      dec(inp[r[j]]);
      eg[r[i],r[j]]:=false;
     end;
  end;
//
close(input); close(output);
end.
