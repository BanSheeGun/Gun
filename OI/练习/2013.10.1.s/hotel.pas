var size,room,num,price:array[1..50] of longint;
    name:array[1..50] of string;
    a:array[1..50] of char;
    c,cha:char;
    x,y,n,m,i,z,ch,ans,r:longint;
    ok:boolean;

function fh(i:longint):boolean;
begin
 if c<>a[i] then exit(false);
 if num[i]<y then exit(false);
 if room[i]<r then exit(false);
 exit(true);
end;

function f(i:longint):boolean;
begin
 if price[i]*r>ans then exit(false);
 if price[i]*r<ans then exit(true);
 if size[i]>size[ch] then exit(true);
 if size[i]<size[ch] then exit(false);
 if i<ch then exit(true);
 exit(false);
end;

begin
 assign(input,'hotel.in');reset(input);
 assign(output,'hotel.out');rewrite(output);
 read(n,m);
 for i:=1 to n do begin
  read(size[i],num[i],room[i],price[i]);
  if (20<=size[i])and(size[i]<=35) then a[i]:='A';
  if (36<=size[i])and(size[i]<=48) then a[i]:='B';
  if (49<=size[i])and(size[i]<=62) then a[i]:='C';
  read(cha);
  readln(name[i]);
 end;

 for z:=1 to m do begin
  read(c);
  read(cha);
  readln(x,y);
  r:=x div y;
  if x mod y<>0 then r:=r+1;
  ok:=false;
  for i:=1 to n do
   if fh(i) then
    if ok=false then begin
     ok:=true;
     ch:=i;
     ans:=r*price[i];
    end
   else if f(i) then begin
    ch:=i;
    ans:=r*price[i];
   end;
  if ok then writeln(ans,' ',name[ch])
        else writeln('no-hotel');
 end;
 close(input);close(output);
end.
