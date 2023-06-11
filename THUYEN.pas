var f1,f2:Text;
a,b:longint;
k:Real;
function ucnn(a,b:longint):longint;
var t:longint;
begin
   while b>0 do
      begin
        t:=a mod b;
        a:=b;
        b:=t;
      end;
   ucnn:=a;
end;
begin
   assign(F1,'THUYEN.inp');reset(F1);
   assign(f2,'THUYEN.out');rewrite(f2);
   readln(F1,a,b);
   k:=(a*b) div ucnn(a,b);
   write(F2,k:0:0);
close(F1);
close(f2);
end.