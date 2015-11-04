var n,i,j,sum,h,g,k:longint;
    c:char;
    pd,ps:boolean;
    s:string;
    s1:array[0..6,0..51]of string;
    s2:array[0..51]of string;
    t:array[0..51]of integer;
    f,m:array[0..6,0..51]of integer;
procedure work(a,b:longint);
var i,j,te:longint;ss:string;
begin
for i:=1 to b-1 do
    for j:=i+1 to b do
        if s1[a,i]+s1[a,j]>s1[a,j]+s1[a,i] then begin
              te:=f[a,i];f[a,i]:=f[a,j];f[a,j]:=te;
                                                ss:=s1[a,i];s1[a,i]:=s1[a,j];s1[a,j]:=ss;
                                                te:=m[a,i];m[a,i]:=m[a,j];m[a,j]:=te;
                                                end;
end;
procedure work2(d,z:longint);
var i,j:longint;
begin
if sum=0 then exit
         else for i:=1 to t[d] do
                  begin
                    if f[d,i]=z then begin for j:=1 to d-2 do
                                               write('|    ');
                                           write('|----');
                                           writeln(s1[d,i]);
                                           dec(sum);
                                           work2(d+1,i);
                                     end;
                  end;
end;
begin
assign(input,'file.in');
assign(output,'file.out');
reset(input);
rewrite(output);
readln(n);
pd:=false;
g:=0;
for i:=1 to n do
  begin
  h:=1;
  while not eoln do
    begin
      read(c);
      if (eoln)and(h<>1) then begin s:=s+c;ps:=true;for j:=1 to t[h] do if s1[h,j]=s then begin ps:=false;break;end;
                                    if not ps then begin s2[h]:=s;s:='';continue;end;
                                    inc(t[h]);s1[h,t[h]]:=s;
                                    for j:=1 to t[h-1] do
                                    if s1[h-1,j]=s2[h-1] then begin f[h,t[h]]:=j;break;end;
                                    if h=2 then f[2,t[h]]:=1;
                                    s:='';continue;
                              end;
      if (h=1) and (not pd) then begin s:='';while c<>'/'do
                                             begin
                                             s:=s+c;
                                             read(c);
                                             end;
                             pd:=true;
                             s1[1,1]:=s;
                             s:='';
                             s2[h]:=s;
                             t[1]:=1;
                             inc(h);
                        end
                        else if h=1 then begin while c<>'/'do read(c);inc(h);s:='';end
                                    else begin if c<>'/'then s:=s+c
                                                        else begin
                                                             if h=2 then begin ps:=true;for j:=1 to t[h] do
                                                              if s1[h,j]=s then begin ps:=false;break;end;
                                                              if not ps then begin s2[h]:=s;s:='';inc(h);continue;end;
                                                                               inc(t[2]);s1[2,t[2]]:=s;
                                                                               f[2,t[2]]:=1;
                                                                               s2[h]:=s;
                                                                               inc(h);
                                                                               s:='';
                                                                         end
                                                                    else begin ps:=true;
                                           for j:=1 to t[h] do if s1[h,j]=s then begin ps:=false;break;end;
                                                     if not ps then begin s2[h]:=s;s:='';inc(h);continue;end;
                                                                         inc(t[h]);s1[h,t[h]]:=s;
                                                                         s2[h]:=s;
                                                                         for j:=1 to t[h-1] do
                                                                             if s1[h-1,j]=s2[h-1] then begin f[h,t[h]]:=j;break;end;
                                                                         inc(h);
                                                                         s:='';
                                                                         end;
                                                             end;
                                         end;
    end;
  if h>g then g:=h;
  readln;
  end;
for i:=1 to g do
    for j:=1 to t[i] do
        m[i,j]:=j;
for i:=g downto 2 do work(i,t[i]);
for i:=2 to g do
    for j:=1 to t[i] do
        for k:=1 to t[i-1] do
            begin
            if f[i,j]=m[i-1,k] then begin f[i,j]:=k;break;end;
            end;
sum:=1;
for i:=2 to g do sum:=sum+t[i];
writeln(s1[1,1]);
dec(sum);
work2(2,1);
close(input);
close(output);
end.
