var n,i,j,x,y,a,b,t:longint;
    m:array[0..100,0..100]of longint;
    f:array[0..100]of boolean;
    r,s:array[0..10000]of longint;
begin
        assign(input,'tournament.in');
        reset(input);
        assign(output,'tournament.out');
        rewrite(output);
        read(n);
        for i:=1 to n*(n-1)div 2-1 do
                begin
                        read(a,b);
                        m[a,b]:=1;
                        inc(r[b]);
                end;
        for i:=1 to n-1 do
            begin
            for j:=i+1 to n do
                if (m[i,j]=0)and(m[j,i]=0) then break;
            if (m[i,j]=0)and(m[j,i]=0) then break;
            end;
        x:=i;
        y:=j;
        while t<n do
                begin
                        s[0]:=0;
                        for i:=1 to n do
                            if r[i]=0 then begin
                                                inc(s[0]);
                                                s[s[0]]:=i;
                                           end;
                        for i:=1 to s[0] do
                                begin
                                        inc(t);
                                        f[s[i]]:=true;
                                        for j:=1 to n do
                                            if m[s[i],j]=1 then dec(r[j]);
                                end;
                        if f[x] or f[y] then break;
                end;
        if f[x]and (not f[y]) then writeln(x,' ',y)
                              else writeln(y,' ',x);
        close(input);
        close(output);

end.
