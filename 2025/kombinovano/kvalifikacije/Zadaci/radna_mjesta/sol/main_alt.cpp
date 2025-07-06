#include <iostream>
#include <string>

long long findPow2(long long x){
	// Najmanja binarna jedinica u x
	// Ako je x = b1101101000 = 872 funkcija će vratiti b0000001000 = 8  
	return x & -x;
}

int main(){

    long long N, T;
    std::cin >> N >> T;

    std::string cells;
    std::cin >> cells;

    while (T > 0){

        std::string next = "";
        long long pow2 = findPow2(T);

        for (int i = 0; i < N; i++){

            long long leftIndex = (i - pow2) % N;
            long long rightIndex = (i + pow2) % N;

            if (leftIndex < 0){
                leftIndex += N;
            }

            int Xor = 0;
            Xor += '0' - cells[leftIndex] + 1;
            Xor += '0' - cells[rightIndex] + 1;

            if (Xor == 1){
                next += '1';
            }

            else{
                next += '0';
            }

        }

        cells = next;
        T -= pow2;

    }

    std::cout << cells << '\n';

    return 0;

}