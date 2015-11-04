var st:string;
    sum:array['a'..'z']of longint;
    mi,ma,i:longint;
    ch:char;
    t:array['a'..'z']of boolean;
function check(x:longint):boolean;
begin
 for i:=2 to trunc(sqrt(x)) do
  if x mod i=0 then exit(false);
 exit(true);
end;
begin
 assign(input,'lucky.in');reset(input);
 assign(output,'lucky.out');rewrite(output);
 readln(st);
 fillchar(sum,sizeof(sum),0);
 fillchar(t,sizeof(t),false);
 for i:=1 to length(st) do begin
  t[st[i]]:=true;
  inc(sum[st[i]]);
 end;

 mi:=maxlongint;
 ma:=0;
 for ch:='a' to 'z' do
  if t[ch] then  begin
   if sum[ch]>ma then ma:=sum[ch];
   if sum[ch]<mi then mi:=sum[ch];
  end;

 ma:=ma-mi;
 if check(ma) then begin
  writeln('Lucky Word');
  writeln(ma);
 end
 else begin
  writeln('No Answer');
  writeln(0);
 end;
 close(input);close(output);
end.