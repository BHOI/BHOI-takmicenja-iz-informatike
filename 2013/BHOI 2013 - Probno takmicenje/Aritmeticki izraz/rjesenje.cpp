#include <stack>
#include <queue>
#include <cctype>  //zbog funkcija isspace, isdigit
#define NDEBUG     //zbog efikasnosti assert je iskljucen
#include <cassert> //zbog funkcije assert

#include <iostream>

using namespace std;

struct Element {
  //Svaki element izraza moze biti broj, neki od dopustenih operator ili zagrada
  enum {Broj, Plus, Minus, Puta, Podijeljeno, Zagrada} tip;
  //Polje vrijednost ima znacenje samo kada je tip == Broj
  int vrijednost;
};

int izracunaj(const char *izraz) {
	/* Algoritam za izracunavanje baziran je na "Shunting-yard" algoritmu. Red rpn odgovara "output"
	   redu iz opisa algoritma, dok stek op odgovara "operator" steku iz opisa algoritma. Ovaj
	   algoritam prvo izraz u tzv. "in-fix" notaciji prevede u izraz u "reverse polish" notaciju. */
  queue<Element> rpn; //rpn = reverse polish notation
  stack<Element> op;
  //Za svaki karakter iz izraza
  const char* karakter = izraz;
  while (*karakter != '\0') {
    //Karakter je cifra
    if (isdigit(*karakter)) {
      int broj = *karakter - '0';                  //koja je pocetak broja
      while (isdigit(*(karakter+1)))               //kojeg rekonstruisemo
        broj = broj*10 + *(++karakter) - '0';
      rpn.push(Element({Element::Broj, broj}));    //kojeg dodajeno u rpn red
    }
    //Karakter je operator niskog prioriteta o1
    else if (*karakter == '+' || *karakter == '-') {
      /* Uslov "sve dok je u steku op neki drugi operator o2 za koji vrijedi da je
         prioritet(o1) <= prioritet(o2) i o1 je asocijativan sa lijeve strane" se u prevodi u uslov
         "sve dok je u steku op neki operator" jer su za + i - koji su asocijativni sa lijeve strane
         svi operatori koje mi koristimo veceg ili jednakog prioriteta */
      while (op.empty() == false && (op.top().tip == Element::Plus || op.top().tip == Element::Minus
             || op.top().tip == Element::Puta || op.top().tip == Element::Podijeljeno)) {
        //Prebacujemo operator o2 iz steka op u red rpn
        rpn.push(op.top());
        op.pop();
      }
      //Dodajemo operator o1 u stek op
      if (*karakter == '+')
        op.push(Element({Element::Plus, 0})); //vrijednost broja nije bitna
      else
        op.push(Element({Element::Minus, 0}));
    }
    //Karakter je operator visokog prioriteta o1
    else if (*karakter == '*' || *karakter == '/') {
      /* Uslov "sve dok je u steku op neki drugi operator o2 za koji vrijedi da je
         prioritet(o1) <= prioritet(o2) i o1 je asocijativan sa lijeve strane" se u prevodi u uslov
         "sve dok je u steku op operator * ili /" jer su za * i / koji su asocijativni sa lijeve
         samo operatori * i / od operatora koje mi koristim, operatori veceg ili jednakog prior. */
      while (op.empty() == false &&
             (op.top().tip == Element::Puta || op.top().tip == Element::Podijeljeno)) {
        //Prebacujemo operator o2 iz steka op u red rpn
        rpn.push(op.top());
        op.pop();
      }
      //Dodajemo operator o1 u stek op
      if (*karakter == '*')
        op.push(Element({Element::Puta, 0}));
      else
        op.push(Element({Element::Podijeljeno, 0}));
    }
    //Karakter je otvorena zagrada
    else if (*karakter == '(')
      //Dodajemo je na stek op
      op.push(Element({Element::Zagrada, 0})); //vrijednost broja nije bitna
    //Karakter je zatvorena zagrada
    else if (*karakter == ')') {
      //Sve dok u steku op ne pronadjemo otvorenu zagradu
      assert(op.empty() == false); //Ako nismo nasli zagradu, izraz nije bio ispravan
      while (op.top().tip != Element::Zagrada) {
        //Prebacujemo operatore u red rpn
        rpn.push(op.top());
        op.pop();
        assert(op.empty() == false);
      }
      //Skidamo otvorenu zagradu sa steka op
      op.pop();
    }
    else
    /* Osim navedenih i obradjenih karaktera, smije se pojaviti jos samo prazno mjesto, inace izraz
       nije ispravan! */
      assert(isspace(*karakter));
    karakter++;
  }
  //Prebaci preostale operatoru iz steka op u red rpn
  while (op.empty() == false) {
    assert(op.top().tip != Element::Zagrada); //Ne smije se pojaviti zagrada, inace izraz nije OK
    rpn.push(op.top());
    op.pop();
  }

  /* Izraz zapisan u obliku "reverse polish" notacije je jednostavno izrazunati. Potreban name je
     jedan stek u kojem se cuvaju vrijednosti. */
  stack<int> rpn_pomocni;
  while (rpn.empty() == false) {
    //Svi brojevi se odmah stavljaju na stek
    if (rpn.front().tip == Element::Broj)
      rpn_pomocni.push(rpn.front().vrijednost);
    /* Za sve operatore skidaju se dvije vrijednosti sa steka u kojem cuvamo vrijednosti, izvrsi se
       odgovarajuca operacija i ta vrijednost se vrati nazad u stek vrijednosti. */
    else if (rpn.front().tip == Element::Plus) {
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int a = rpn_pomocni.top();
      rpn_pomocni.pop();
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int b = rpn_pomocni.top();
      rpn_pomocni.pop();
      rpn_pomocni.push(b+a);
    }
    else if (rpn.front().tip == Element::Minus) {
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int a = rpn_pomocni.top();
      rpn_pomocni.pop();
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int b = rpn_pomocni.top();
      rpn_pomocni.pop();
      rpn_pomocni.push(b-a);
    }
    else if (rpn.front().tip == Element::Puta) {
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int a = rpn_pomocni.top();
      rpn_pomocni.pop();
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int b = rpn_pomocni.top();
      rpn_pomocni.pop();
      rpn_pomocni.push(b*a);
    }
    else if (rpn.front().tip == Element::Podijeljeno) {
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int a = rpn_pomocni.top();
      rpn_pomocni.pop();
      assert(rpn_pomocni.empty() == false); //Stek vrijednosti ne smije biti prazan ako je sve OK
      int b = rpn_pomocni.top();
      rpn_pomocni.pop();
      rpn_pomocni.push(b/a);
    }
    else
      assert(false); //Zagrada se ne smije naci u rpn redu
    rpn.pop(); //Predji na sljedeci element izraza
  }
  assert(rpn_pomocni.size() == 1); //Ako je sve OK na kraju ima samo jedan broj u steku vrijednosti
  return rpn_pomocni.top(); //I on predstavlja rezultat izracunavanja izraza
}
