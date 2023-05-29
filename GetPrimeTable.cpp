#include <cmath>

class GetPrimeTable
{
private:
    bool* prime;
public:
    GetPrimeTable(int size);
    bool* GetTable();
    ~GetPrimeTable();
};

GetPrimeTable::GetPrimeTable(int size)
{
    prime = new bool[size + 1];
    for (int i = 2; i <= size; i++)
    {
        for (int j = 2; j <= (int)sqrt(i) + 1; j++)
        {
            if (j > (int)sqrt(i))
            {
                prime[i] = true;
                break;
            }
            if (i % j == 0)
                break;
        }
    }
}

bool* GetPrimeTable::GetTable()
{
    return prime;
}

GetPrimeTable::~GetPrimeTable()
{
    free(prime);
}
