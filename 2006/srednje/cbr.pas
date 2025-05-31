type a = record a, b : integer; end;
type b = array[0..10000] of integer;
var int : array[1..10000] of a;
    lit : array[1..10000] of boolean;
    x, treba : ^b;
    i, j, n, lst, prvi, drugi, prvitaj, drugitaj, total : integer;
    f : text;

procedure solve;
begin
  i:=1;

  while i<=n do
    begin
    while not lit[i] do inc (i);

    if treba^[i]<2 then
       begin
       prvi:=0; drugi:=0;

       for j:=int[i].a to int[i].b do
           begin
           if prvi<=x^[j] then begin drugi:=prvi; drugitaj:=prvitaj;
                                    prvi:=x^[j]; prvitaj:=j; end
                         else
                        if drugi<x^[j] then
                           begin
                           drugi:=x^[j]; drugitaj:=j;
                           end;
           dec (x^[j]);
           end;

       if treba^[i]=0 then
          begin
          inc (total); x^[drugitaj]:=0;
          j:=i+1;
          while (int[j].a<=drugitaj) and (int[j].b>=drugitaj) or (not lit[j]) do
            begin inc (treba^[j]); inc (j); end;
          end;

       inc (total); x^[prvitaj]:=0;
       j:=i+1;
       while (int[j].a<=prvitaj) and (int[j].b>=prvitaj) or (not lit[j]) do
         begin inc (treba^[j]); inc (j); end;
       end;

    inc (i);
    end;
end;

procedure shellsort;
var h : integer;
    tmp : a;
label out;
begin
  h:=1; repeat; h:=3*h+1; until h>n;

  repeat;
    h:=h div 3;
    for i:=h+1 to n do
        begin
        tmp:=int[i]; j:=i;
        while (int[j-h].a>tmp.a) or
              (int[j-h].a=tmp.a) and (int[j-h].b<tmp.b) do
              begin
              int[j]:=int[j-h]; j:=j-h;
              if j<=h then goto out;
              end;
        out:
        int[j]:=tmp;
        end;
  until h=1;
end;

begin
  assign (f, 'cbr.in'); reset (f);
  read (f, n); fillchar (lit, n+1, True);
  new (x); fillchar (x^, 20000, 0);
  new (treba); fillchar (treba^, 20000, 0);

  for i:=1 to n do
      read (f, int[i].a, int[i].b);

  shellsort; lst:=n; for i:=int[n].a to int[n].b do inc (x^[i]);

  for i:=n-1 downto 1 do
      if int[lst].b <= int[i].b then lit[i]:=False
                                else begin
                                     lst:=i;
                                     for j:=int[i].a to int[i].b do
                                         inc (x^[j]);
                                     end;

  int[n+1].a:=32767; int[n+1].b:=32767;
  solve;

  assign (f, 'cbr.out'); rewrite (f);
  writeln (f, total);
  close (f);
end.