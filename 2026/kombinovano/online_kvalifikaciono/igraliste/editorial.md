# Editorial: Igralište

## Ključna ideja

Dijete može saznati šta mu piše na čelu ako i samo ako ga **barem jedno drugo dijete može vidjeti**. Drugačije rečeno, dijete ne može saznati broj jedino ako se ne pojavljuje ni u jednom paru (a, b).

## Rješenje

Prolazimo kroz svih M parova i označavamo svako dijete koje se pojavi. Na kraju, odgovor je broj djece koja nisu označena, tj. broj djece koja se ni u jednom paru ne pojavljuju.

Složenost: O(N + M).
