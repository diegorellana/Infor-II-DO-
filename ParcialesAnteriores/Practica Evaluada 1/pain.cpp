#include <iostream>
using namespace std;
#include <cmath>

bool amigo(int x, int y);

int main()
{
	int na{}, nb{};
	while (true)
	{
		cout << "Dar A, B?: "; cin >> na >> nb;

		if (na == 2 && nb == 2)
		{
			break;
		}

		else
		{
			for (int i = na; i < nb; i++)
			{
				int sumadiv = 0;
				int newnum = i;
				for (int j = 1; j < i; j++)
				{
					if (newnum % j == 0)
					{
						sumadiv = sumadiv + j;
					}
				}
				
                if (sumadiv <= nb && sumadiv >= na)
                {
                    for (int k = na; k < nb; k++)
                    {
                        if (amigo(sumadiv, k))
                        {
                            cout << i << " y " << k << " son amigos. " << endl;
                            break;
                        }
                    }
                }
			}
		}
	}

}

bool amigo(int x, int y)
{
    if (x == y)
    {
        return true;
    }

    else
    {
        return false;
    }
}