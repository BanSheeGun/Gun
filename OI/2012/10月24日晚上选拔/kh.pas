var a:array[0..255] of char;
    top,y,z,sum,i:longint;
function ls(k:longint):boolean;
var s:longint;
begin
 s:=k;
 while a[s-1]=' ' do dec(s);
 if (a[s-1]='+')or(a[s-1]='(') then exit(true);
 exit(false);
end;

function lh(k:longint):boolean;
var s:longint;
begin
 s:=k;
 while a[s+1]=' ' do inc(s);
 if a[s+1]='(' then exit(false);
  inc(s);
 while a[s+1]=' ' do inc(s);
 if a[s+1]=')' then exit(true);
 exit(false);
end;
begin
 assign(input,'kh.in');reset(input);
 assign(output,'kh.out');rewrite(output);
 readln(z);
 for y:=1 to z do begin
  top:=0;
  while not eoln do begin
   inc(top);
   read(a[top]);
  end;
  readln;

  a[0]:='+';
  sum:=0;
  for i:=1 to top do
   case a[i] of
   '(':if ls(i) then begin a[i]:=' '; inc(sum); end;
   ')':if sum>0 then begin a[i]:=' '; dec(sum); end;
  end;
  a[0]:='+';
  sum:=0;
  for i:=1 to top do
   case a[i] of
   '(':if lh(i) then begin a[i]:=' '; inc(sum); end;
   ')':if sum>0 then begin a[i]:=' '; dec(sum); end;
  end;
  for i:=1 to top do
   if a[i]<>' 'then write(a[i]);
  writeln;
 end;
 close(input);close(output);
end.
