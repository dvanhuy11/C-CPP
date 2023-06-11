var f1,f2:text;
        st:ansistring;
        n:longint;

procedure InRa (x:longint);
begin
        if (x=n) then write(f2,st[n]) else begin
                InRa(x+1);
                write(f2,st[x]);
        end;
end;

begin
        assign(f1,'Daonguoc.INP'); reset(f1);
        assign(f2,'Daonguoc.OUT'); rewrite(f2);
        read(f1,st); n:=length(st);
        InRa(1);
        close(f1); close(f2);
end.