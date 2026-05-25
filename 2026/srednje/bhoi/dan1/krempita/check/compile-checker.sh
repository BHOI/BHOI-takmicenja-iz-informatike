if ! g++ checker.cpp -o checker -static -O2 -std=c++17 2>/tmp/krempita-static-checker.log; then
    g++ checker.cpp -o checker -O2 -std=c++17
fi
