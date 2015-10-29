Var i,point,top,tl,n,x,y,root,k:longint;
    G:array[0..20000] of Record key,next:longint; End;
    Llink:array[0..20000] of longint;
    fa:array[0..20000] of boolean;
    my:array[0..20000] of string;
    st,tst:string;
    
Function Find(st:string):longint;
Var i,j:longint;
Begin
     Find:=0;
     For i:=1 to tl do If my[i]=st then Find:=i;
     If Find=0
     then Begin
               Inc(tl);
               my[tl]:=st;
               Find:=tl;
          End;
End;

Procedure Print(x,dep:longint);
Var i,j,point,adj:longint;
Begin
     For i:=1 to dep-1 do Write('|    '); Writeln('|----',my[x]);
     point:=Llink[x];
     While point<>0 do
     Begin
          adj:=G[point].key;
          point:=G[point].next;
          Print(adj,dep+1);
     End;
End;

Begin
Assign(input,'file.in');
Reset(input);
Assign(output,'file.out');
Rewrite(output);

  Readln(n);
  top:=0;
  tl:=0;
  Fillchar(fa,sizeof(fa),false);
  For i:=1 to n do
  Begin
       x:=0;
       Readln(st);
       While st<>'' do
       Begin
            k:=1; While (st[k]<>'/') and (k<=length(st)) do Inc(k); Dec(k);
            If k<=length(st)
            then Begin
                      tst:=copy(st,1,k); If k<length(st) then Delete(st,1,k+1) else st:='';
                      y:=Find(tst);
                      point:=Llink[x];
                      While point>0 do
                      Begin
                           If G[point].key=y then point:=-1
                                             else point:=G[point].next;
                      End;
                      If point=0
                      then Begin
                      Inc(top);
                      G[top].key:=y;
                      If x<>0 then fa[y]:=true;
                      G[top].next:=Llink[x];
                      Llink[x]:=top;
                      End;
                      x:=y;
                 End;
       End;
  End;
  root:=1; While fa[root] do Inc(root);
  Writeln(my[root]);
  point:=Llink[root];
  While point<>0 do
  Begin
       Print(G[point].key,1);
       point:=G[point].next;
  End;

Close(input);
Close(output);
End.


