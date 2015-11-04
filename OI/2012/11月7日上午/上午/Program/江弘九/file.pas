var count,i,j,len,n,no,p,total:longint;
    now:string;
    deep,depth:array[0..10000] of longint;
    fold,folder,path:array[0..10000] of string;

procedure sort(l,r:longint);

var i,j,temper:longint;
    m,temp:string;

begin
     i:=l;
     j:=r;
     m:=fold[(i+j) div 2];
     repeat
           while fold[i]<m do
                 i:=i+1;
           while fold[j]>m do
                 j:=j-1;
           if not(i>j) then begin
                                 temp:=fold[i];
                                 fold[i]:=fold[j];
                                 fold[j]:=temp;
                                 temper:=deep[i];
                                 deep[i]:=deep[j];
                                 deep[j]:=temper;
                                 i:=i+1;
                                 j:=j-1;
                            end;
     until i>j;
     if l<j then sort(l,j);
     if i<r then sort(i,r);
end;

begin
     assign(input,'file.in');
     reset(input);
     assign(output,'file.out');
     rewrite(output);
     readln(n);
     for i:=1 to n do
         readln(path[i]);
     total:=0;
     for i:=1 to n do
     begin
          count:=1;
          p:=1;
          while p<=length(path[i]) do
          begin
               now:='';
               while (path[i][p]<>'/') and (p<=length(path[i])) do
               begin
                    now:=now+path[i][p];
                    p:=p+1;
               end;
               total:=total+1;
               if count=1 then fold[total]:=now else fold[total]:=fold[total-1]+'/'+now;
               deep[total]:=count;
               count:=count+1;
               p:=p+1;
          end;
     end;
     sort(1,total);
     len:=1;
     folder[1]:=fold[1];
     depth[1]:=deep[1];
     for i:=2 to total do
         if fold[i]<>folder[len] then begin
                                           len:=len+1;
                                           folder[len]:=fold[i];
                                           depth[len]:=deep[i];
                                      end;
     for i:=1 to len do
     begin
          for j:=1 to depth[i]-2 do
              write('|    ');
          if depth[i]>=2 then write('|----');
          no:=0;
          for j:=1 to length(folder[i]) do
          begin
               if folder[i][j]='/' then begin
                                             no:=no+1;
                                             continue;
                                        end;
               if no>=depth[i]-1 then write(folder[i][j]);
          end;
          writeln;
     end;
     close(input);
     close(output);
end.
