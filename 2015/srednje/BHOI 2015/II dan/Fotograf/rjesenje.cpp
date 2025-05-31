#include <algorithm>
#include <vector>

std::vector<std::vector<std::pair<int, int> > > tree;

// Odredjuje log2 od stepena broja 2
int log2(int val) {
  int retval = 0;
  while (val >>= 1)
    ++retval;
  return retval;
}

int Vrh(int L, int D) {
  ++D;
  std::pair<int, int> retval = tree[0][L];
  while (L < D) {
    // Pronalazi najnizi stepen dvojke u broju, te to postaje korak
    int step = L & -L;
    // Ako je donja granica nula, uzimamo prevelik stepen broja 2.
    if (!L)
      step = 1 << tree.size();
    // Polovimo korak dok ne bude unutar granica
    while (L + step > D)
      step >>= 1;
    // Odredujemo sloj drveta u kojem se nalazi dati korak
    int layer = log2(step);
    // Poredimo trenutni max sa novom ponudom
    retval = std::max(retval, tree[layer][L >> layer]);
    // Pomjeramo donju granicu i ponavljamo dok se granice ne poklope
    L += step;
  }
  return retval.second;
}

void formirajDrvo() {
  // U svakoj iteraciji polovimo duzinu u odnosu na prijasnji sloj
  while (tree.back().size() > 1) {
    size_t row = tree.size() - 1;
    size_t l = tree[row].size();
    tree.emplace_back();
    for (size_t i = 1; i < l; i += 2)
      // Svaki element n+1-og sloja je max 2 elementa n-tog sloja
      tree.back().push_back(std::max(tree[row][i - 1], tree[row][i]));
  }
}

void Drvece(int N, int h[]) {
  tree.emplace_back();

  for (int i = 0; i < N; ++i)
    tree.back().emplace_back(h[i], i);

  formirajDrvo();
}
