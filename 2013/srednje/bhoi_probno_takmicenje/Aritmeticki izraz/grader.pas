Program grader;
uses izraz;
const
	max_n  = 1000000;
var
	izr : String;
begin
	setlength(izr, 1000000);
	readln(izr);
	writeln(izracunaj(izr));
end.
