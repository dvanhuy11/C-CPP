v
      if a>b then h:=h(a-b,b)
        else h:=h(a,b-a);
end;ar f1,f2:text;
function ucnn(a,b:longint):longint;
begin
   if a=b then h:=a
    else
begin
      assign(f1,'wifipass.inp');reset(f1);
      assign(f1,'wifipass.out');rewrite(F2);
      readln(f1,q);
      readln(f1,n);
      if (n*n) mod 2 <> then 
      begin
         x:=1;
         y:=(n*n) div 2; 
      end 
       else 
       begin
          y:= (n*n) div 2;
          x:=h(y,n);
        end;
   write(f2,x,y);
close(F1);
close(f2);
end;