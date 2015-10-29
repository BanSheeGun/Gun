var amount,ans1,ans2,flag,i,j,n,x,y:longint;
    stat,visit:array[1..100] of longint;
    map:array[1..100,1..100] of longint;

procedure dfs(r,v:longint);

var i:longint;

begin
     if (r<>v) and (map[r,v]=0) then begin
                                          ans1:=r;
                                          ans2:=v;
                                          flag:=1;
                                          exit;
                                     end;
     for i:=1 to n do
         if (visit[i]=0) and (map[v,i]=1) then begin
                                                    visit[i]:=1;
                                                    dfs(r,i);
                                                    if flag=1 then exit;
                                               end;
end;

begin
     assign(input,'tournament.in');
     reset(input);
     assign(output,'tournament.out');
     rewrite(output);
     readln(n);
     amount:=n*(n-1) div 2;
     fillchar(stat,sizeof(stat),0);
     for i:=1 to amount-1 do
     begin
          readln(x,y);
          map[x,y]:=1;
          stat[x]:=stat[x]+1;
          stat[y]:=stat[y]+1;
     end;
     flag:=0;
     for i:=1 to n do
     begin
          fillchar(visit,sizeof(visit),0);
          visit[i]:=1;
          dfs(i,i);
     end;
     if (ans1<>0) and (ans2<>0) then writeln(ans1,' ',ans2) else begin
                                                                      for i:=1 to n do
                                                                          if stat[i]<>n-1 then begin
                                                                                                    ans1:=i;
                                                                                                    break;
                                                                                               end;
                                                                      for j:=i+1 to n do
                                                                          if stat[j]<>n-1 then begin
                                                                                                    ans2:=j;
                                                                                                    break;
                                                                                               end;
                                                                      writeln(ans1,' ',ans2);
                                                                 end;
     close(input);
     close(output);
end.
