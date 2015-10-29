var x,n,i,j,k,qd:longint;
    len:array[0..100]of longint;
    data:array[1..100,1..100]of string;
    afile:array[1..100]of string;
    tmp:string;

function min(a,b:longint):longint;
begin
  if a<b then exit(a)
         else exit(b);
end;
begin
assign(input,'file.in');
assign(output,'file.out');
reset(input);
rewrite(output);
readln(n);
  for i:=1 to n do readln(afile[i]);
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if afile[i]>afile[j] then
          begin
            tmp:=afile[i];
	    afile[i]:=afile[j];
	    afile[j]:=tmp;
          end;
  for i:=1 to n do
    begin
      len[i]:=0;
       while pos('/',afile[i])<>0 do
         begin
           x:=pos('/',afile[i]);
           inc(len[i]);
           data[i,len[i]]:=copy(afile[i],1,x-1);
           delete(afile[i],1,x);
         end;
      inc(len[i]);
      data[i,len[i]]:=afile[i];
    end;
  for i:=1 to n do
    begin
      if i=1 then qd:=1
             else for j:=1 to min(len[i-1],len[i]) do
                    if data[i-1,j]<>data[i,j] then
		              begin
					    qd:=j;
						break;
					  end;
      for j:=qd to len[i] do
        if j=1 then writeln(data[i,1])
               else begin
		              for k:=1 to j-2 do
				        write('|    ');
		                write('|----');
                        writeln(data[i,j]);
	                end;
    end;
close(input);
close(output);
end.
