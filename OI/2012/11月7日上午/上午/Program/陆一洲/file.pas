program ffile;
var n,i,j,k,p:longint;
    a,c:array[0..100] of string;
function cc(x,y:string):boolean;
  var i:longint;
  begin
    for i:=1 to length(x) do begin
      if i>length(y) then exit(false);
      if ord(x[i])<ord(y[i]) then exit(true);
      if ord(x[i])>ord(y[i]) then exit(false);
    end;
    if length(x)>=length(y) then exit(false);
  end;
procedure sort(l,r:longint);
  var i,j:longint;
      mid,temp:string;
  begin
    i:=l;j:=r;mid:=a[(i+j) div 2];
    while (i<=j) do begin
      while cc(a[i],mid) do inc(i);
      while cc(mid,a[j]) do dec(j);
      if i<=j then begin
        temp:=a[i];a[i]:=a[j];a[j]:=temp;
        inc(i);dec(j);
      end;
    end;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
  end;
procedure change;
  var i,k,p,u,ii,w,wf:longint;
      s:string;
  begin
    s:='';k:=0;p:=0;
    for i:=1 to n do begin
      if k=0 then begin
        for j:=1 to length(a[i]) do begin
          if a[i,j]='/' then begin
            inc(p);c[p]:=copy(a[i],1,j-1);inc(k);w:=j;
            if c[p]=c[p-1] then dec(p);
          end;
        end;
        inc(p);c[p]:=a[i];
        s:=copy(a[i],1,w);
        if c[p]=c[p-1] then dec(p);
      end else begin
        u:=0;wf:=0;w:=0;
        for j:=1 to length(s) do
          if s[j]='/' then begin
            inc(u);wf:=w;w:=j;
            if (j>length(a[i]))or(copy(s,1,j)<>copy(a[i],1,j)) then begin
              for ii:=wf+1 to length(a[i]) do
                if a[i,ii]='/' then begin
                  inc(p);c[p]:=copy(a[i],1,ii-1);inc(u);w:=ii;
                  if c[p]=c[p-1] then dec(p);
                end;
              inc(p);c[p]:=a[i];k:=u;
              s:=copy(a[i],1,w);
              if c[p]=c[p-1] then dec(p);
              break;
            end;
          end;
        u:=0;
        for j:=length(s)+1 to length(a[i]) do
          if a[i,j]='/' then begin
            inc(p);c[p]:=copy(a[i],1,j-1);
            if c[p]=c[p-1] then dec(p);
            inc(u);w:=j;
          end;
        inc(p);c[p]:=a[i];inc(k,u);
        if c[p]=c[p-1] then dec(p);
        s:=copy(a[i],1,w);
      end;
    end;
    n:=p;
  end;
procedure print;
  begin
    for i:=1 to n do begin
      k:=0;p:=0;
      for j:=1 to length(c[i]) do
        if c[i,j]='/' then begin inc(k);p:=j;end;
      for j:=1 to k-1 do write('|    ');
      if k>0 then write('|----');
      for j:=p+1 to length(c[i]) do write(c[i,j]);
      writeln;
    end;
  end;
begin
  assign(input,'file.in');reset(input);
  assign(output,'file.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  sort(1,n);
  change;
//  for i:=1 to n do writeln(c[i]);
  print;
  close(input);close(output);
end.
