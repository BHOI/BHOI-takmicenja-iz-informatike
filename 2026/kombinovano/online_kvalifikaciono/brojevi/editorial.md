# Editorial: Brojevi

## Ključna ideja

Broj koji je istovremeno i potpuni kvadrat i potpuni kub mora biti **šesta potencija** nekog prirodnog broja, oblika i^6.

## Zašto šesta potencija?

Broj x je potpuni kvadrat akko su svi prosti eksponenti u faktorizovanju parni, a potpuni kub akko su djeljivi s 3. Da bi oba uslova bila ispunjena, svaki eksponent mora biti djeljiv s NZV(2, 3) = 6. Dakle x = i^6 za neki cijeli broj i >= 1.

## Rješenje

Iteriramo i = 1, 2, 3, ... sve dok i^6 <= B. Za svaki takav i, ako je i^6 >= A, uvećamo brojač.

Zbog ograničenja B <= 100,000,000, vrijedi i <= 21, pa petlja ima najviše 21 iteraciju.
