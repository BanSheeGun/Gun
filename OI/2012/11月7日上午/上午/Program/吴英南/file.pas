var n,i,j,c,step,p,k:longint;
    f:boolean;
    a:array[0..100]of string;

    procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:string;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
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
        {writeln;}
        for i:=1 to n do
                readln(a[i]);
        sort(1,n);
        for i:=1 to n do
                begin
                        j:=1;
                        c:=0;
                        step:=0;
                        f:=true;
                        while j<=length(a[i]) do
                                begin
                                        if (j>length(a[i-1]))or(a[i-1,j]<>a[i,j]) then f:=false;
                                        if a[i,j]='/' then inc(c);
                                        if f and (a[i,j]='/') then inc(step);
                                        inc(j);
                                end;
                        for j:=0 to c-step do
                                begin
                                        for k:=1 to step+j-1 do
                                            write('|    ');
                                        if step+j>0 then write('|----');
                                        p:=0;
                                        k:=0;
                                        while p<step+j do
                                                begin
                                                        inc(k);
                                                        if a[i,k]='/' then inc(p);
                                                end;
                                        inc(k);
                                        while (k<=length(a[i]))and(a[i,k]<>'/') do
                                                begin
                                                        write(a[i,k]);
                                                        inc(k);
                                                end;
                                        writeln;
                                end;
                end;
        close(input);
        close(output);
end.
