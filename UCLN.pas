var f1,f2:Text;
x,y:longint;
function h(m,n:longint):longint;
begin
   if m=n then h:=m
    else
      if m>n then h:=h(m-n,n)
        else h:=h(m,n-m);
end;
begin
  assign(F1,'UCLN.inp');reset(F1);
  assign(F2,'ULLN.out');rewrite(f2);
  read(f1,x,y);
  write(f2,h(x,y));
close(F1);
close(F2);
end.