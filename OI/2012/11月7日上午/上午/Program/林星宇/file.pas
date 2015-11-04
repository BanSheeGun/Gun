const maxn=500;
var
	n,i,j,k,q,t,m:longint;
	s:array[1..maxn]of ansistring;
 	ss:ansistring;
procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:string;
      begin
         i:=l;
         j:=r;
         x:=s[(l+r) div 2];
         repeat
           while s[i]<x do
            inc(i);
           while x<s[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=s[i];
                s[i]:=s[j];
                s[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

procedure print(x:ansistring;d:longint);
 var i:longint;
begin
if d=1 then begin writeln(x);exit;end;
 for i:=1 to d-2 do write('|    ');
 write('|----');
 writeln(x);
end;

procedure work(l,r,dep:longint);
 var
	t,i:longint;
	st,ss:ansistring;
begin
if s[l]='' then exit;
 t:=pos('/',s[l]);
 st:=copy(s[l],1,t-1);
 print(st,dep);
 for i:=l to r do delete(s[i],1,t);
 i:=l;j:=l+1;
 t:=pos('/',s[i]);
 st:=copy(s[i],1,t-1);
 while j<=r do
   begin
     t:=pos('/',s[j]);
     ss:=copy(s[j],1,t-1);
     if ss=st then inc(j)
              else  begin
			work(i,j-1,dep+1);
			i:=j;
			st:=ss;
		     end;
   end;
 work(i,r,dep+1);
end;

begin
assign(input,'file.in');reset(input);
assign(output,'file.out');rewrite(output);
 readln(n);
 for i:=1 to n do
   begin
    readln(s[i]);
    s[i]:=s[i]+'/';
   end;
sort(1,n);
work(1,n,1);
close(input);
close(output);
end.
