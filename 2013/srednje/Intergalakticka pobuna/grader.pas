Program grader;
uses pobuna;
var
	n : LongInt;
	poruka : String;
begin
	readln(n);
	setlength(poruka, n);
	readln(poruka);
	writeln(Analiza(n, poruka));
end.
