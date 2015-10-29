var n,m,i,sum,j,max:longint;
    x,a,b,c:array[0..1000]of longint;
    f:array[0..1000,0..2000]of longint;
begin
        assign(input,'pack.in');
        reset(input);
        {assign(output,'pack.out');
        rewrite(output);}
	read(n,m);
	for i:=1 to n do
		begin
			read(x[i]);
			read(a[i],b[i]);
			if x[i]=2 then read(c[i]);
		end;
	sum:=n;
	for i:=1 to n do
		if x[i]=2 then begin
					for j:=1 to c[i] do
						begin
							inc(sum);
							a[sum]:=a[i];
							b[sum]:=b[i];
						end;
			       end
		   else if x[i]=3 then begin
				   	
					for j:=1 to m div b[i] do
						begin
							inc(sum);
							a[sum]:=a[i];
							b[sum]:=b[i];
				         	end;
				       end;
	for i:=1 to sum do
		begin
			if x[i]=1 then begin f[i]:=f[i-1];continue;end;
			for j:=1 to n do
				begin
				if f[i-1][j]>f[i,j] then f[i,j]:=f[i-1][j];
                                if j-b[i]<=0 then continue;
				if f[i-1][j-b[i]]+a[i]>f[i,j] then f[i,j]:=f[i-1][j-b[i]]+a[i];
				end;
		end;
        for i:=1 to m do
                if f[sum,i]>max then max:=f[sum,i];
	writeln(max);
end.
