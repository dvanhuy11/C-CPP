const maxN=10000000;
var f1,f2:Text;
i,n:word;
a,d:Array[0..maxN] of longint;
begin
  fillchar(D,sizeof(d),0);
  assign(f1,'NMIN.inp');reset(F1);
  assign(F2,'NMIN.out');rewrite(F2);
  readln(f1,n);
  for i:=1 to n do
    begin
     read(f1,a[i]);
     if a[i] <=n then
       d[a[i]]:=1;
    end;
  for i:=0 to n do
     if d[i]=0 then
       begin
          write(f2,i);
          close(F2);
          exit;
       end;
close(F1);
close(f2);
end.
