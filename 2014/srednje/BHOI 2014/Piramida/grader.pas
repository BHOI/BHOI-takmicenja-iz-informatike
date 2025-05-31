Program grader;
uses piramida;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  n, k, p, s, i : LongInt;
  poeni : Array of LongInt;
  inbuf : array [1..inbuf_len] of Byte;
  outbuf : array [1..outbuf_len] of Byte;
begin
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);
  readln(n, k, p, s);
  SetLength(poeni, n * k);
  for i := 0 to (n * k) - 1 do
    read(poeni[i]);
  writeln(MaxUcinak(n, k, p, s, poeni));
end.
