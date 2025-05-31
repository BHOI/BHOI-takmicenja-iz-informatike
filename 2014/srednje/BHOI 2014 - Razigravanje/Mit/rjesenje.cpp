#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string Multiplication (string number)
{
    string multiplicationResult, additionResult, finalResult;
    int multiplication, sum, carryMultiplication, carrySum;
    for (int i = 0; i < number.size(); i++)
    {
        carryMultiplication = 0;
        multiplicationResult = "";
        for (int j = number.size() - 1; j >= 0; j--)
        {
            multiplication = (number[i] - 48) * (number[j] - 48) + carryMultiplication;
            carryMultiplication = multiplication / 10;
            multiplicationResult += multiplication % 10 + 48;
        }
        if (carryMultiplication != 0)
            multiplicationResult += carryMultiplication + 48;
        if(i == 0)
            finalResult = multiplicationResult;
        else
        {
            additionResult = multiplicationResult[0];
            carrySum = 0;
            for (int k = 0; k < finalResult.size(); k++)
            {
                if(k + 1 >= multiplicationResult.size())
                    sum = finalResult[k] - 48 + carrySum;
                else
                    sum = finalResult[k] + multiplicationResult[k + 1] + carrySum - 96;
                additionResult += sum % 10 + 48;
                carrySum = sum / 10;
            }
            if (carrySum != 0)
                additionResult += carrySum + 48;
            finalResult = additionResult;
        }
    }
    return finalResult;
}

int LCS (string reverseNumber)
{
    string number;
    for (int i = reverseNumber.size() - 1; i >= 0; i--)
        number.push_back(reverseNumber[i]);
    vector<vector<int> > matrix(number.size() + 1, vector<int>(number.size() + 1));
    for (int i = 0; i < number.size() + 1; i++)
        for (int j = 0; j < number.size() + 1; j++)
        {
            if(i == 0 || j == 0)
                continue;
            else if(number[i - 1] == reverseNumber[j - 1] && !(number[i - 1] == '0' && matrix[i - 1][j - 1] == 0))
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = max(matrix[i - 1][j],matrix[i][j - 1]);
        }
    return matrix[number.size()][number.size()];
}

int AlfaKoeficijent(int W, char *C) {
     string number;
     for (int i = 0; i < W; i++)
        number.push_back(C[i]);
     return LCS(Multiplication(number));
}
