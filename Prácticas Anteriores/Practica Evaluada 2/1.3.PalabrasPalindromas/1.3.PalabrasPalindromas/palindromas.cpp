#include <iostream>
#include <cstring>
using namespace std;

bool palindroma(const char* palabra);
char* pideFrase();

int main()
{
    char* frase = pideFrase();

    size_t len = strlen(frase);
    size_t inicio = 0;

  
    for (size_t i = 0; i <= len; i++)
    {
        if (frase[i] == ' ' || frase[i] == '\0')
        {
            size_t size_palabra = i - inicio;

            if (size_palabra > 0)  
            {
                char* palabra = new char[size_palabra + 1];

               
                for (size_t j = 0; j < size_palabra; j++)
                {
                    palabra[j] = frase[inicio + j];
                }
                palabra[size_palabra] = '\0';  

                if (palindroma(palabra))
                {
                    cout << palabra << " es palindroma\n";
                }

                delete[] palabra;
            }

            inicio = i + 1;
        }
    }

    delete[] frase;
    return 0;
}

char* pideFrase()
{
    char buff[100];
    cout << "Inserte frase: ";
    cin.getline(buff, 100);

    size_t size = strlen(buff);
    char* frase = new char[size + 1];
    strcpy_s(frase, size + 1, buff);

    return frase;
}

bool palindroma(const char* palabra)
{
    size_t length = strlen(palabra);

    for (size_t i = 0; i < length / 2; i++)
    {
        if (palabra[i] != palabra[length - 1 - i])
            return false;
    }
    return true;
}
