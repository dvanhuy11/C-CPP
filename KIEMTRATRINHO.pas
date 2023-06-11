var f1,f2:Text;
n,m,t,sum,i,j:longint;
a,b:array[1..100000] of longint;
begin
  assign(F1,'KIEMTRA.INP');reset(F1);
  assign(f2,'KIEMTRA.OUT');rewrite(f2);
  read(f1,n,t,m);
  for i:=1 to n do
    read(f1,a[i]);
  b[1]:=a[t];
  i:=1;
  j:=t;
  while i<=m do
  begin
    inc(i);
    inc(j);
    if j>n then j:=1;
    b[i]:=a[j];
  end;
  for i:=1 to m do
    sum:=sum+b[i];
  write(F2,sum);
close(F1);
close(f2);
end.