Program grader;
uses igra;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  M, N, i : LongInt;
  P : Array of LongInt;
  inbuf : array [1..inbuf_len] of Byte;
  outbuf : array [1..outbuf_len] of Byte;
begin
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);
  readln(M, N);
  SetLength(P, M);
  for i := 0 to M - 1 do
    read(P[i]);
  writeln(IgraFaktorizacije(M, P, N));
end.
