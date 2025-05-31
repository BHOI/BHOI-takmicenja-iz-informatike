Program grader;
uses mars;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  N, M, i : LongInt;
  T : Array of LongInt;
  inbuf : array [1..inbuf_len] of Byte;
  outbuf : array [1..outbuf_len] of Byte;
begin
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);
  readln(N);
  readln(M);
  SetLength(T, N * M);
  for i := 0 to N * M - 1 do
    read(T[i]);
  writeln(MaksimalnaVrijednost(N, M, T));
end.

