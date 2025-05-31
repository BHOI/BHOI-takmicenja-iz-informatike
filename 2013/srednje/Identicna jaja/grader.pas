Program stub;

uses
    jaje, jajelib;

var
    n, k, rezultat: LongInt;
    fifoin, fifoout: Text;

begin
    assign(fifoin, argv[2]);
    assign(fifoout, argv[1]);
    reset(fifoin);
    rewrite(fifoout);
    readln(fifoin, n, k);
    Inicijalizacija(fifoin, fifoout);

    rezultat := PronadjiSprat(n,k);
    writeln(fifoout,'1 ',rezultat);
    flush(fifoout);
    close(fifoin);
    close(fifoout);
    Halt(0);
end.
