type tree=^node;
     node=record
      lchild,rchild:tree;
      left,right:longint;
      sum,de:longint;
     end;
var a:array[1..100000] of longint;
    head:tree;
    n,m,i,q,l,r,x,k,ans:longint;

function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

procedure creat(var root:tree;l,r:longint);
var mid:longint;
begin
 new(root);
 root^.left:=l;
 root^.right:=r;
 root^.de:=0;
 if l=r then begin
  root^.sum:=a[l];
  root^.lchild:=nil;
  root^.rchild:=nil;
 end
 else begin
  root^.sum:=0;
  mid:=(l+r) div 2;
  creat(root^.lchild,l,mid);
  creat(root^.rchild,mid+1,r);
 end;
end;

function find(var root:tree;l,r,d:longint):longint;
var mid,le,ans:longint;
begin
 ans:=0;
 mid:=(root^.left+root^.right) div 2;
 le:=root^.right-root^.left+1;
 if (l<=root^.left)and(root^.right<=r) then begin
  ans:=root^.sum+le*root^.de+d;
  exit(ans);
 end;
 if (l<=mid) then begin
  le:=min(r,mid)-l+1;
  ans:=ans+find(root^.lchild,l,r,d+root^.de*le);
 end;
 if (r>=mid+1) then begin
  le:=r-max(l,mid+1)+1;
  ans:=ans+find(root^.rchild,l,r,d+root^.de*le);
 end;
 exit(ans);
end;

procedure change(var root:tree;l,r,x:longint);
var mid,le:longint;
begin
 mid:=(root^.left+root^.right) div 2;
 le:=root^.right-root^.left+1;
 if (l<=root^.left)and(root^.right<=r) then begin
  root^.de:=root^.de+x;
  exit;
 end;
 if (l<=mid) then begin
  change(root^.lchild,l,r,x);
 end;
 if (r>=mid+1) then begin
  change(root^.rchild,l,r,x);
 end;
end;

begin
 read(n);
 for i:=1 to n do
  read(a[i]);

 creat(head,1,n);

 read(q);
 for i:=1 to q do begin
  read(k);
  case k of
   1:begin
    read(l,r,x);
    change(head,l,r,x);
   end;
   2:begin
    read(l);
    ans:=find(head,l,l,0);
    writeln(ans);
   end;
  end;
 end;
end.
