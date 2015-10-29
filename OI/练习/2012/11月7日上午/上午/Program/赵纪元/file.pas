var s,fn,ts,rot:string;
    i,j,deep,t,p,k,n,l:longint;
    dn:array[1..100]of longint;
    dnm:array[1..100,1..200]of string;
    dq:array[1..100,1..200]of longint;
procedure print(deep,x:longint);
var i:longint;
begin
  for i:=1 to deep-2 do
    write('|    ');
  if deep>1 then writeln('|----',dnm[deep,x]) else writeln(rot);
  for i:=1 to dn[deep+1] do
    if dq[deep+1,i]=x then print(deep+1,i);
end;
begin
  assign(input,'file.in');
  assign(output,'file.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    s:=s+'/';
    for j:=1 to length(s) do
      if s[j]='/' then break;
    if i=1 then rot:=copy(s,1,j-1);
    delete(s,1,j);
    deep:=1;
    p:=1;
    repeat
      inc(deep);
      for j:=1 to length(s) do
        if s[j]='/' then break;
      fn:=copy(s,1,j-1);
      delete(s,1,j);
      for j:=1 to dn[deep] do
        if (fn=dnm[deep,j])and(p=dq[deep,j]) then break;
      if (fn<>dnm[deep,j])or(p<>dq[deep,j]) then
      begin
        inc(dn[deep]);
        dnm[deep,dn[deep]]:=fn;
        if deep=2 then dq[deep,dn[deep]]:=1 else dq[deep,dn[deep]]:=p;
        p:=dn[deep];
      end else p:=j;
    until s='';
  end;
  for i:=2 to deep do
    for j:=1 to dn[i]-1 do
      for k:=j+1 to dn[i] do
        if dnm[i,j]>dnm[i,k] then
        begin
          for l:=1 to dn[i+1] do
            if dq[i+1,l]=j then dq[i+1,l]:=k else
              if dq[i+1,l]=k then dq[i+1,l]:=j;
          ts:=dnm[i,j];
          dnm[i,j]:=dnm[i,k];
          dnm[i,k]:=ts;
          t:=dq[i,j];
          dq[i,j]:=dq[i,k];
          dq[i,k]:=t;
        end;
  print(1,1);
  close(input);
  close(output);
end.