Program grader;
uses loto;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  N, M : LongInt;
  inbuf : array [1..inbuf_len] of Byte;
  outbuf : array [1..outbuf_len] of Byte;
begin
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);
  readln(N, M);
  writeln(SumaCifara(N, M));
end.
