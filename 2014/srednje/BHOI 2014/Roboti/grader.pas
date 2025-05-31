Program grader;
uses roboti;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  r, p, q, v, e, i : LongInt;
  energije : Array of LongInt;
  inbuf : array [1..inbuf_len] of Byte;
  outbuf : array [1..outbuf_len] of Byte;
begin
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);
  readln(r, p, q, v, e);
  SetLength(energije, e * 3);
  for i := 0 to (e * 3) - 1 do
    read(energije[i]);
  writeln(BrojMinimalnihPotrosnji(r, p, q, v, e, energije));
end.
