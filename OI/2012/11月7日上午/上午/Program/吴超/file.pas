var c,c2:array[1..10000]of longint;
    a:array[1..10000]of string;
    s:array[1..100]of ansistring;
    h:array[1..1000,1..100]of longint;
    i,j,k,mi,tem,n,r,lx:longint;
    temp,temp2,x:string;
procedure print(n:longint);
var i:longint;
begin
     for i:=1 to n-1 do
         write('|    ');
     write('|');
end;
procedure work(dep,x:longint);
var i:longint;
begin
     for i:=1 to c[x] do
         begin
              print(dep);
              write('----');
              write(a[h[x,i]]);
              writeln;
              work(dep+1,h[x,i]);
         end;
end;

function pd(x:string):boolean;
var i:longint;
begin
     for i:=1 to r do
         if a[i]=x then exit(false);
     pd:=true;
end;
procedure search(x:string);
var i:longint;
begin
     for i:=1 to  r-1 do
         if a[i]=x then begin
            inc(c[i]);h[i,c[i]]:=r;
            inc(c2[r]);
            exit;
            end;
end;

begin
     assign(input,'file.in');
     reset(input);
     assign(output,'file.out');
     rewrite(output);
     readln(n);
     for i:=1 to n do
         readln(s[i]);
     for i:=1 to n do
         begin
         x:=s[i];lx:=length(x);
         temp:='';temp2:='';
         for j:=1 to lx do
           begin
                if x[j]='/' then begin
                if pd(temp) then begin
                inc(r);
                search(temp2);
                a[r]:=temp;
                end;
                temp2:=temp;
                temp:='';
                end
                else temp:=temp+x[j];
           end;
           if pd(temp) then begin
                inc(r);
                search(temp2);
                a[r]:=temp;
                end;
            end;

     for k:=1 to n do
         begin
              for i:=1 to c[k]-1 do
                  for j:=1 to c[k]-i do
                      if a[h[k,j]]>a[h[k,j+1]] then begin
                         tem:=h[k,j];h[k,j]:=h[k,j+1];h[k,j+1]:=tem;
                         end;
         end;

     for i:=1 to n do
         if c2[i]=0 then begin
          mi:=i;break;end;
     writeln(a[mi]);
     work(1,mi);
     close(input);
     close(output);
end.