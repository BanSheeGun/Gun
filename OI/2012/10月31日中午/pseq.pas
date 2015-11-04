var top,max,i,j:longint;
    s1,s2:string;
    a,b,c:array[1..400000] of longint;
begin
 assign(input,'pseq.in');reset(input);
 assign(output,'pseq.out');rewrite(output);
 readln(s1);
 s2:='';
 for i:=length(s1) downto 1 do
  s2:=s2+s1[i];
 fillchar(a,sizeof(a),0);
 top:=0;
 for i:=1 to length(s2) do
  for j:=length(s1) downto 1 do
   if s2[i]=s1[j] then
    begin
     inc(top);
     a[top]:=j;
    end;

 for i:=1 to top do
  begin
   max:=0;
   for j:=1 to i-1 do
    if (a[j]<a[i])and(max<b[j]) then
     begin
      max:=b[j];
      c[i]:=j;
     end;
   b[i]:=max+1;
  end;
  max:=1;
  for i:=2 to top do
   if b[i]>=b[max] then max:=i;
   writeln(b[max]);
 close(input);close(output);
end.