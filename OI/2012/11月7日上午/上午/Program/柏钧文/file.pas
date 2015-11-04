var p,i,n,total,tot,j,t:longint;
        a:array[0..1000]of string;
        sa:array[0..5000]of string;
        aa:array[0..5000,0..20]of longint;
        s,ts,tss:string;
        ss:array[0..200]of string;

procedure doit;
  var i,pt,t,tip:longint;
  begin
  t:=1;
  if total=0 then
        begin
        inc(total);
        sa[total]:=a[t];
        pt:=total;
        inc(t);
        end;
  pt:=1;
  t:=2;
  while t<=tot do
        begin
        tip:=0;
        for i:=1 to aa[pt,0] do
                if a[t]=sa[aa[pt,i]] then
                begin
                tip:=aa[pt,i];
                break;
                end;
        if tip=0 then
                begin
                inc(total);
                sa[total]:=a[t];
                inc(aa[pt,0]);
                aa[pt,aa[pt,0]]:=total;
                tip:=total;
                end;
        pt:=tip;
        inc(t);
        end;
  end;

procedure print(pt,dep:longint);
  var i:longint;
  begin
  if dep>0 then write('|');
  for i:=1 to dep-1 do
        write('    |');
  if dep>0 then write('----');
  writeln(sa[pt]);
  for i:=1 to aa[pt,0] do
        print(aa[pt,i],dep+1);
  end;

begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
readln(n);
total:=0;
for i:=1 to n do
        readln(ss[i]);
for i:=1 to n-1 do
        for j:=i+1 to n do
        if ss[i]>ss[j] then
        begin
        tss:=ss[i];ss[i]:=ss[j];ss[j]:=tss;
        end;
for p:=1 to n do
        begin
        s:=ss[p];
        s:=s+'/';
        tot:=0;
        while length(s)<>0 do
                begin
                t:=pos('/',s);
                ts:=copy(s,1,t-1);
                inc(tot);
                a[tot]:=ts;
                delete(s,1,t);
                end;
        doit;
        end;
print(1,0);
close(input);close(output);
end.