#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        int k;
        for (int i = 1; av[i]; i++)
        {
            k = 0;
            do
            {
                std::cout << (char)toupper(av[i][k]);
                k++;
            } while (av[i][k]);
            if (av[i + 1])
                std::cout << " ";
        }
    }
    return (0);
}