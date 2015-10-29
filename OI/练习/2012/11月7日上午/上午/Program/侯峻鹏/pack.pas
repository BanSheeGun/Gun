const maxn=111;
      maxv=2222;
      tot:array[1..3] of integer=(2,3,2);
//
var opt:array[0..maxv] of longint;
    i,j,k,n,m,now,ans:longint;
    pack:array[0..maxn,0..3] of longint;
    base,tmp:array[0..10] of longint;
//
function fmax2(a,b:longint):longint;
begin
 if a>b then exit(a)
        else exit(b);
end;
//
begin
assign(input,'pack.in'); reset(input);
assign(output,'pack.out'); rewrite(output);
//
 read(n,m);
 for i:=1 to n do
  begin
   read(pack[i,0]);
   for j:=1 to tot[pack[i,0]] do read(pack[i,j]);
  end;
 base[0]:=1;
 for i:=1 to 10 do base[i]:=base[i-1] shl 1;
//
 fillchar(opt,sizeof(opt),0);
 for i:=1 to n do
  begin
   if pack[i,0]=1 then
    for j:=m downto trunc(pack[i,2]/pack[i,1]) do
     begin
      now:=pack[i,1]*j*j-pack[i,2]*j;
      for k:=m downto j do
      opt[k]:=fmax2(opt[k],opt[k-j]+now);
     end;
   if pack[i,0]=2 then
    begin
     tmp[0]:=0;
     while (pack[i,3]>=base[tmp[0]]) do
      begin
       dec(pack[i,3],base[tmp[0]]);
       inc(tmp[0]);
       tmp[tmp[0]]:=base[tmp[0]-1];
      end;
     if pack[i,3]<>0 then
      begin
       inc(tmp[0]);
       tmp[tmp[0]]:=pack[i,3];
      end;
     for k:=1 to tmp[0] do
      for j:=m downto tmp[k]*pack[i,2] do opt[j]:=fmax2(opt[j],opt[j-pack[i,2]*tmp[k]]+tmp[k]*pack[i,1]);
     end;
   if pack[i,0]=3 then
    for j:=pack[i,2] to m do opt[j]:=fmax2(opt[j],opt[j-pack[i,2]]+pack[i,1]);
  end;
//
 ans:=0;
 for i:=0 to m do
  if opt[i]>ans then ans:=opt[i];
 writeln(ans);
//
close(input); close(output);
end.

