Program grader;
uses ciscenje;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  N, i : LongInt;
  T : Array of LongInt;
  inbuf : array [1..inbuf_len] of Byte;
  outbuf : array [1..outbuf_len] of Byte;
begin
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);
  readln(N);
  SetLength(T, N);
  for i := 0 to N - 1 do
    read(T[i]);
  writeln(Raspodjela(N, T));
end.
