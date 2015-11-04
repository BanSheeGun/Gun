var n,m,i,j,k,l,o,x,y,z:longint;
a,b,c:array[1..100]of string;
procedure sort(l,r: longint);
      var
         i,j: longint;
	x,y:string;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]+x<x+a[i] do
            inc(i);
           while x+a[j]<a[j]+x do
            dec(j);
           if i<=j then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
end;
begin
  assign(input,'file.in');
  reset(input);
  assign(output,'file.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
      readln(a[i]);
  sort(1,n);
  j:=1;
  o:=0;
  for i:=1 to length(a[1]) do
      begin
        if a[1,i]='/' then begin
        		     inc(o);
		             b[o]:=copy(a[1],j,i-j);
			     break;
      			   end;
     end;
  writeln(b[1]);
  for i:=1 to n do
      begin
	x:=1;
	y:=1;
	o:=length(a[i]);
  for z:=1 to o do
      begin
        if a[i,z]='/' then begin
			     c[y]:=copy(a[i],x,z-x);
			     x:=z+1;
			     inc(y);
			   end;
      end;
  c[y]:=copy(a[i],x,o-x+1);
  j:=2;
  while j<y do
        begin
          j:=2;
          while c[j]=b[j] do
		begin
		  write('|    ');
		  inc(j);
		end;
	  writeln('|----',c[j]);
	  b[j]:=c[j];
	end;
  if y=2 then writeln('|----',c[y]);
  b[y]:=c[y];
  end;
  close(input);
  close(output);
end.
