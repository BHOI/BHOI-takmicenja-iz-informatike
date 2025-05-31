Program grader;
uses projektili;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  n, i : LongInt;
  staze : Array of LongInt;
  inbuf : array [1..inbuf_len] of Byte;
  outbuf : array [1..outbuf_len] of Byte;
begin
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);
  readln(n);
  SetLength(staze, n * 5);
  for i := 0 to (n * 5) - 1 do
    read(staze[i]);
  writeln(BrojSudara(n, staze));
end.
