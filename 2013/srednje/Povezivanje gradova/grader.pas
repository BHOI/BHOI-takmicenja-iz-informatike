Program grader;
uses gradovi;
const
   inbuf_len  = 1 shl 23;
   outbuf_len = 1 shl 10;
var
  n, i, j, x, y : LongInt;
  m : Array of LongInt;
  inbuf      : array [1..inbuf_len] of Byte;
  outbuf     : array [1..outbuf_len] of Byte;
begin
  { Set input and output buffering }
  settextbuf(input, inbuf);
  settextbuf(output, outbuf);

  readln(n);
  SetLength(m, n);
  for i := 0 to n-2 do
    read(m[i]);
  readln(m[n-1]);
  Inicijalizacija(n, m);
  for i := 0 to n-1 do
    for j := 0 to m[i]-1 do
    begin
      readln(x, y);
      PostaviKucu(i, x, y);
    end;
  writeln(Povezi());
end.
