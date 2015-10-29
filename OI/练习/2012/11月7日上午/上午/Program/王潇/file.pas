Var i,j,n,x,dep:longint;
    s,s1,s2:string;
    a:array[0..55]of string;

Procedure print(s:string;dep:longint);
var i,x:longint;
    ss:string;
begin
  x:=0;
  for i:=1 to dep do delete(s,1,pos('/',s));
  for i:=1 to length(s) do if s[i]='/' then inc(x);
  for i:=1 to x do
    begin
      for j:=1 to dep-1 do write('|    ');
      if dep>0 then write('|----');
      ss:=copy(s,1,pos('/',s)-1);
      writeln(ss);
      delete(s,1,pos('/',s));
      inc(dep);
    end;
end;

Begin
  assign(input,'file.in'); reset(input);
  assign(output,'file.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      readln(a[i]);
      a[i]:=a[i]+'/';
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
         begin s:=a[i];a[i]:=a[j];a[j]:=s;end;

  print(a[1],0);
  for i:=2 to n do
    begin
      s1:=a[i-1];
      s2:=a[i];
      dep:=0; x:=1;
      repeat
        if s1[x]='/' then inc(dep);
	inc(x);
      until (x>length(s1))or(x>length(s2))or(s1[x]<>s2[x]);
      print(s2,dep);
    end;
  close(input); close(output);
End.
