Program grader;
uses transformacija;

var
  seed : LongInt;
  
function myrand() : LongInt;
begin
	seed := (214013 * seed + 2531011);
	myrand := (seed shr 16) and $7FFF;
end;

function IzracunajMaxDeltu(n, k : LongInt) : LongInt;
var
	delta : LongInt;
begin
	delta := round(n / k);
	delta := delta or (delta shr 1);
	delta := delta or (delta shr 2);
	delta := delta or (delta shr 4);
	delta := delta or (delta shr 8);
	delta := delta or (delta shr 16);
	if (delta = 0) then delta := 1;
	IzracunajMaxDeltu := delta;
end;

function GenerisiSortiranNiz(var arr : Array of LongInt; n, k : LongInt) : LongInt;
var
	max_delta, i : LongInt;
begin
	max_delta := IzracunajMaxDeltu(n, k);
	arr[0] := ((myrand() and max_delta) mod (n - 1)) + 1;
	for i := 1 to k-1 do
		begin
		arr[i] := arr[i - 1] + (myrand() and max_delta);
		if (arr[i] >= n) then
			begin
			Exit(i);
			end;
		end;
	Exit(k);
end;

var
  n, m, l, r, i, j, k : LongInt;
  krajnji, pocetni, rezultat : Array of LongInt;

begin
  read(seed, n, m, l);
  SetLength(krajnji, n);
  n := GenerisiSortiranNiz(krajnji, l, n);
  SetLength(pocetni, m);
  m := GenerisiSortiranNiz(pocetni, l, m);
  SetLength(rezultat, m + n);
  r := TransformisiNiz(n, Copy(krajnji, 0, n), m, Copy(pocetni, 0, m), rezultat);
  i := 0; j:= 0;
	for k := 0 to r - 1 do
		begin
		if rezultat[k] = -1 then
			j := j + 1
		else if rezultat[k] = 0 then
			begin
			if (i >= n) or (j >= m) or (krajnji[i] <> pocetni[j]) then
				begin
				writeln('Neispravna transformacija');
				Exit;
				end;
			i := i + 1;
			j := j + 1;
			end
		else
			begin
			if (i >= n) or (krajnji[i] <> rezultat[k]) then
				begin
				writeln('Neispravna transformacija.');
				Exit;
				end;
			i := i + 1;
			end;
	end;
	if (i <> n) or (j <> m) then
		writeln('Neispravna transformacija.')
	else
		writeln('Ispravna transformacija u ', r ,' koraka.');
end.
