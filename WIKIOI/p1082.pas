type tree=^node;
     node=record
      lchild,rchild:tree;
      de,left,right:longint;
      sum:int64;
     end;
var a:array[1..100000] of longint;
    head:tree;
    n,m,i,q,l,r,x,k:longint;
    ans:int64;

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
  mid:=(l+r) div 2;
  creat(root^.lchild,l,mid);
  creat(root^.rchild,mid+1,r);
  root^.sum:=root^.rchild^.sum+root^.lchild^.sum;
 end;
end;

function find(var root:tree;l,r,d:longint):int64;
var mid,le:longint;
    ans:int64;
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

 root^.sum:=root^.lchild^.sum+root^.rchild^.sum;
 root^.sum:=root^.sum+root^.lchild^.de*(root^.lchild^.right-root^.lchild^.left+1);
 root^.sum:=root^.sum+root^.rchild^.de*(root^.rchild^.right-root^.rchild^.left+1);
end;

begin
 assign(output,'ask.out');rewrite(output);
 assign(input,'ask.in');reset(input);
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
    read(l,r);
    ans:=find(head,l,r,0);
    writeln(ans);
   end;
  end;
 end;
 close(output);
close(input);
end.
