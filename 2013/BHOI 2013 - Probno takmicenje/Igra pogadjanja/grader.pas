Program stub;

uses
    igra, igralib;

var
    a, b: LongInt;
    fifoin, fifoout: Text;

begin
    assign(fifoin, argv[2]);
    assign(fifoout, argv[1]);
    reset(fifoin);
    rewrite(fifoout);
    Inicijalizacija(fifoin, fifoout);
    readln(fifoin, a, b);
    ZapocniIgru(a,b);
    close(fifoin);
    close(fifoout);
    Halt(0);
end.
