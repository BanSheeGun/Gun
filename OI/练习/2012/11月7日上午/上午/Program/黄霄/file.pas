type arr=record
     s:string;
     lr,fa:longint;
     er:array[0..16]of longint;
    end;
var q,p1,p2,m,n,i,j,k,ans,dep,lg,hf:longint;
    t:array[0..6,0..50626]of arr;
    l:array[0..6]of longint;
    s,s1,root:string;
    f:boolean;

procedure clo;
begin
close(input);close(outpuT);
end;

procedure chu1;
begin
readln(s);m:=length(s);i:=1;
while (i<=m)and(s[i]<>'/') do
 begin
 root:=root+s[i];
 inc(i);
 end;
lg:=length(root)+2;dep:=1;s1:='';i:=lg;
while (i<=m) do
 begin
 if s[i]<>'/' then s1:=s1+s[i]
              else begin
	           inc(dep);l[dep]:=1;t[dep,1].s:=s1;
	           t[dep,1].fa:=1;t[dep-1,1].lr:=1;t[dep-1,1].er[1]:=1;s1:='';
		   end;
 inc(i);
 end;
 if s1<>'' then begin
	           inc(dep);l[dep]:=1;t[dep,1].s:=s1;
	           t[dep,1].fa:=1;t[dep-1,1].lr:=1;t[dep-1,1].er[1]:=1;s1:='';
		   end;
l[1]:=1;t[1,1].s:=root;
end;

procedure print(dep,i:longint);
var k,j,x:longint;
begin
for k:=1 to dep-2 do
 write('|    ');
if dep>1 then write('|----');
writeln(t[dep,i].s);
for k:=2 to t[dep,i].lr do
 begin
 j:=k-1;x:=t[dep,i].er[k];
 if  (j>0)and(t[dep+1,x].s<t[dep+1,t[dep,i].er[j]].s) then
  begin
  t[dep,i].er[j+1]:=t[dep,i].er[j];
  dec(j);
  end;
 t[dep,i].er[j+1]:=x;
 end;
for k:=1 to t[dep,i].lr do
 print(dep+1,t[dep,i].er[k]);
end;

procedure work;
begin
	            inc(dep);f:=true;
                    for k:=1 to l[dep] do
                      if s1=t[dep,k].s then begin f:=false;break;end;
                    if f then begin
		              inc(l[dep]);t[dep,l[dep]].s:=s1;
			      t[dep,l[dep]].fa:=hf;
                              inc(t[dep-1,hf].lr);q:=t[dep-1,hf].lr;
                              t[dep-1,hf].er[q]:=l[dep];
                              hf:=l[dep];
			      end
                         else hf:=k;
		    s1:='';

end;

begin
assign(input,'file.in');reset(input);
assign(output,'file.out');rewrite(output);
readln(n);
if n=0 then begin clo;exit;end;
chu1;
for j:=2 to n do
 begin
 readln(s);i:=lg;s1:='';hf:=1;dep:=1;m:=length(s);
 while (i<=m) do
  begin
  if s[i]<>'/' then s1:=s1+s[i]
               else work;
  inc(i);
  end;
 if s1<>'' then work;
 end;
print(1,1);
clo;
end.
