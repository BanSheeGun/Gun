type cw=record
   x,y:string;
   xx,yy:longint;
end;

var num,n,i,j,s:longint;
    e,head,next,v:array[1..100]of longint;
    st:string;
    po:array[1..105] of lzy;
    st1:array[1..105] of string;

function max(a,b:longint):longint;
begin
  if a>b then exit(a);
   exit(b);
end;

function find(i:longint;fix:longint):longint;
var sum0,sum1,k:longint;
begin
  sum0:=0;sum1:=0;
  k:=head[i];
  while k<>0 do begin
    inc(sum0,find(e[k],0));
    k:=next[k];
  end;
  if fix=0 then begin
    sum1:=v[i];
    k:=head[i];
    while k<>0 do begin
      inc(sum1,find(e[k],1));
      k:=next[k];
    end;
  end;
  exit(max(sum0,sum1));
end;

begin
        assign(input,'party.in');
        assign(output,'party.out');
        reset(input);
        rewrite(output);
        readln(n);
        for i:=1 to n do readln(st1[i]);

        for i:=1 to n do
          begin
	    po[i].x:=copy(st1[i],1,pos(' ',st1[i])-1);
	    delete(st1[i],1,pos(' ',st1[i]));
          end;

        for i:=1 to n do
          begin
	    val(copy(st1[i],1,pos(' ',st1[i])-1),v[i]);
	    delete(st1[i],1,pos(' ',st1[i]));
          end;

        for i:=1 to n do po[i].y:=copy(st1[i],1,length(st1[i]));
        for i:=1 to n do po[i].xx:=i;

        for i:=1 to n do
         for j:=1 to n do
          if (i<>j) and (po[i].y=po[j].x) then begin
                                                po[i].yy:=j;
                                                break;
                                               end;
        for i:=1 to n do
          begin
                if po[i].yy=0 then begin s:=i; continue; end;
		inc(num);
		e[num]:=po[i].xx;
		next[num]:=head[po[i].yy];
		head[po[i].yy]:=num;
          end;
          writeln(find(s,0));
          close(input);close(output);
end.
