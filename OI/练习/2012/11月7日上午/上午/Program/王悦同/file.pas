//Gobble Restaurant!!

var n,i,j,ls,start,k:longint;
    s:array[0..100] of string;
    a:array[0..100] of longint;
    b:array[0..100,0..100] of string;
    st,sc:string;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

procedure swap(var a,b:string);
  var r:string;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin

  assign(input,'file.in');
  assign(output,'file.out');
  reset(input);
  rewrite(output);

  readln(n);
  for i:=1 to n do
    readln(s[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if s[i]>s[j] then swap(s[i],s[j]);
  for i:=1 to n do
    begin
      a[i]:=0;
      st:=s[i]+'/';
      ls:=length(st);
      sc:='';
      for j:=1 to ls do
        if st[j]='/' then
          begin
            inc(a[i]);
            b[i,a[i]]:=sc;
            sc:='';
          end
        else
          sc:=sc+st[j];
    end;
  for i:=1 to n do
    begin
      if i=1 then
        start:=1
      else
        begin
          for j:=1 to min(a[i],a[i-1]) do
            if b[i-1,j]<>b[i,j] then
              begin
                start:=j;
                break;
              end;
        end;
      for j:=start to a[i] do
        begin
          if j>1 then
            begin
              write('|');
              for k:=1 to j-2 do write('    |');
              write('----');
              writeln(b[i,j]);
            end
          else
            writeln(b[i,1]);
        end;
    end;

  close(input);
  close(output);
end.
