type arr=record
     op:real;
     v,va,c:longint;
    end;
var q,p1,p2,m,n,i,j,k,a,b,c,l,ans:longint;
    t:array[0..2001]of arr;
    f:array[0..2001]of longint;

procedure clo;
begin
close(input);close(outpuT);
end;

function min(a,b:longint):longint;
begin
if a>b then min:=b
       else min:=a;
end;

procedure sort(l,r:longint);
      var
         i,j: longint;
         x:real;
         y:arr;
      begin
         i:=l;
         j:=r;
         x:=t[(l+r) div 2].op;
         repeat
           while t[i].op>x do
            inc(i);
           while x>t[j].op do
            dec(j);
           if not(i>j) then
             begin
                y:=t[j];t[j]:=t[i];t[i]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
assign(input,'pack.in');reset(input);
assign(output,'pack.out');rewrite(output);
read(n,m);l:=0;
for i:=1 to n do begin
 read(q);read(a,b);
 case q of
  1:if 2*(b/(2*a))>m then begin inc(l);t[l].va:=a;t[l].v:=b;t[l].c:=-1;t[l].op:=a*m-b;end;
  2:begin
    inc(l);read(t[l].c);if t[l].c=0 then begin dec(l);continue;end;
    t[l].va:=a;t[l].v:=b;
    t[l].op:=a/b;
    end;
  3:begin
    inc(l);t[l].va:=a;t[l].v:=b;
    t[l].op:=a/b;
    end;
  end;
 end;
n:=l;
sort(1,l);
for i:=1 to l do
 if t[i].c=-1 then
   for j:=m downto trunc(b/(2*a)) do
      begin
      q:=a*j*j-b*j;
      for k:=0 to m-j do
        if f[k]+q>f[k+j] then f[k+j]:=f[k]+q;
      end
             else
 if t[i].c=0 then
   begin
   for j:=0 to m-t[i].v do
      if f[j]+t[i].va>f[j+t[i].v] then f[j+t[i].v]:=f[j]+t[i].va;
   end
             else
 for j:=m downto 0 do
  begin
  p1:=0;p2:=0;
  for k:=1 to min(t[i].c,j div t[i].v) do
   begin
   p1:=p1+t[i].va;p2:=p2+t[i].v;
   if f[j-p2]+p1>f[j] then f[j]:=f[j-p2]+p1;
   end;
  end;
writeln(f[m]);
 clo;
end.























