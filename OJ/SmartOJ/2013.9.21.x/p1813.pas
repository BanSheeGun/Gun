var hero:array[1..15,1..3] of longint;
    sorce:array[1..5,1..15] of longint;
    data:array[1..5,1..6] of longint;
    ch:array[1..5] of longint;
    i,j,m,n,win,u:longint;
    ans:array[1..5] of longint;
    use:array[1..5,1..15] of longint;
procedure www;
var s,mo:array[1..5] of longint;
    mvp:longint;
begin
 for i:=1 to 5 do begin
  s[i]:=0;
  s[i]:=s[i]+hero[ch[i]][1]*data[i][1];
  s[i]:=s[i]+hero[ch[i]][2]*data[i][2];
  s[i]:=s[i]+hero[ch[i]][3]*data[i][3];
 end;

 for i:=1 to 5 do begin
  mo[i]:=0;
  mo[i]:=mo[i]+data[i][1]*250;
  mo[i]:=mo[i]-data[i][2]*100;
  mo[i]:=mo[i]+data[i][5]*40;
  mo[i]:=mo[i]+data[i][4]*450;
 end;

 mvp:=1;
 for i:=2 to 5 do if s[i]>s[mvp] then mvp:=i;
 s[mvp]:=s[mvp]+20;

 mvp:=1;
 for i:=2 to 5 do if mo[i]>mo[mvp] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 mvp:=1;
 for i:=2 to 5 do if data[i][4]>data[mvp][4] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 mvp:=1;
 for i:=2 to 5 do if data[i][3]>data[mvp][3] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 mvp:=1;
 for i:=2 to 5 do if data[i][6]>data[mvp][6] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 for i:=1 to 5 do sorce[i][ch[i]]:=sorce[i][ch[i]]+s[i];
end;

procedure lll;
var s,mo:array[1..5] of longint;
    mvp:longint;
begin
 for i:=1 to 5 do begin
  s[i]:=0;
  s[i]:=s[i]+hero[ch[i]][1]*data[i][1];
  s[i]:=s[i]+hero[ch[i]][2]*data[i][2];
  s[i]:=s[i]+hero[ch[i]][3]*data[i][3];
 end;

 for i:=1 to 5 do begin
  mo[i]:=0;
  mo[i]:=mo[i]+data[i][1]*250;
  mo[i]:=mo[i]-data[i][2]*100;
  mo[i]:=mo[i]+data[i][5]*40;
  mo[i]:=mo[i]+data[i][4]*450;
 end;

 mvp:=1;
 for i:=2 to 5 do if s[i]>s[mvp] then mvp:=i;
 s[mvp]:=s[mvp]+200;

 mvp:=1;
 for i:=2 to 5 do if mo[i]>mo[mvp] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 mvp:=1;
 for i:=2 to 5 do if data[i][4]>data[mvp][4] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 mvp:=1;
 for i:=2 to 5 do if data[i][3]>data[mvp][3] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 mvp:=1;
 for i:=2 to 5 do if data[i][6]>data[mvp][6] then mvp:=i;
 s[mvp]:=s[mvp]+10;

 for i:=1 to 5 do sorce[i][ch[i]]:=sorce[i][ch[i]]+s[i]-200;
end;

begin
 fillchar(use,sizeof(use),0);

 read(n);
 for i:=1 to n do
  for j:=1 to  3 do
   read(hero[i][j]);

 for i:=1 to 5 do
  for j:=1 to n do sorce[i][j]:=1200;

 read(m);
 for u:=1 to m do begin
  for i:=1 to 5 do begin
   read(ch[i]);
   inc(use[i][ch[i]]);
   for j:=1 to 6 do
    read(data[i][j]);
   end;
   read(win);

  case win of
   1:www;
   0:lll;
  end;
 end;

 fillchar(ans,sizeof(ans),0);
 for i:=1 to 5 do begin
  for j:=1 to n do
   ans[i]:=ans[i]+sorce[i][j]*use[i][j];
  ans[i]:=ans[i] div m;
 end;

 for i:=1 to 5 do
  writeln(ans[i]);
end.
