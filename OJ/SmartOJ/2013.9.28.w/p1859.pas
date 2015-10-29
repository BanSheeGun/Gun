var g,ans:array[1..10000] of longint;
    s:array[1..100000,1..2] of longint;

function find(x:longint;):longint;
begin
 if g[x]=x then exit(x);
 g[x]:=find(g[x]);
 exit(g[x]);
end;

begin
 read(n,m);
 for i:=1 to n do begin
  read(x,y);
  g[i]:=i;
  ans[i]:=0;
 end;

 for i:=1 to m do 
  read(s[i][1],s[i][2]);

 for i:=m downto 1 do begin
  
 end; 
end.

{
program tyvj1700;

var

 n,m,i,x,y,lx,ly,k:longint;

 father,dist:array[1..10000] of longint;

 save:array[1..100000,1..2] of longint;


function search(x:longint):longint;

var

 temp:longint;

begin

 if x=father[x] then

  exit(x);

 temp:=father[x];

 father[x]:=search(father[x]);

 dist[x]:=dist[x]+dist[temp];

 exit(father[x]);

end;


begin

 readln(n);

 readln(m);

 for i:=1 to n do

  father[i]:=i;

 for i:=1 to m do

  readln(save[i,1],save[i,2]);

 for i:=1 to m do

  readln(save[i,1],save[i,2]);


 for i:=m downto 1 do

  begin

   x:=save[i,1];

   y:=save[i,2];

   lx:=search(x);

   ly:=search(y);

   if lx<>ly then

    begin

     if lx>ly then

      begin

       k:=lx;

       lx:=ly;

       ly:=k;

      end;

     if lx=1 then

      dist[ly]:=i;

     father[ly]:=lx;

    end;

  end;

 for i:=1 to n do

  search(i);

 for i:=2 to n do

  writeln(dist[i]);

end.
}