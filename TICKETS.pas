var f1,f2:Text;
n,k,p1,p2,sum,t1,t2,t3:longint;
function gt(x,y,z:longint):longint;
var min:longint;
begin
  if x>y then min:=y
    else min:=x;
  if min>z then min:=z
    else min:=min;
end;
begin
  assign(F1,'TICKETS.INP');reset(F1);
  assign(F2,'TICKETS.OUT');rewrite(f2);
  read(f1,n,k,p1,p2);
  T1:=N*P1;
  T2:=(N div k+1)*p2;
  t3:=(n div k)*p2+( n mod k)*p1;
  write(F2,gt(t1,t2,t3));
close(F1);
close(F2);
end.
