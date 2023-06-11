var m,n,d,j,so:longint;
 a2:array[1..10000]of longint;
f1,f2:text;
function dao(a:longint):longint;
var s,s1:string;
    i,code,a1:longint;
begin
 str(a,s);
 s1:='';
 for i:=1 to length(s) do
  begin
   s1:=s[i]+s1;
  end;
 val(s1,a1,code);
 dao:=a1;
end;
begin
assign(f1,'somayman.inp');reset(f1);
assign(f2,'somayman.out');rewrite(f2);
read(f1,n,m);
for j:=1 to m-n do
 begin
 so:=n+dao(n);
 if frac(sqrt(so))=0 then
 begin
 write(f2,n,' ');
 inc(d);
 end;
 inc(n);
 end;
 if d=0 then write(f2,'khongco');
close(f1);
close(f2);
end.