Program grader;
uses rudnici;
var
	n : LongInt;
	rudnik : String;
begin
	readln(n);
	setlength(rudnik, n);
	readln(rudnik);
	writeln(MaksimalnaZarada(n, rudnik));
end.
