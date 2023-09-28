#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        int k;
        for (int i = 1; av[i]; i++)
        {
			while (av[i] && av[i + 1] && (strlen(av[i]) < 1))
				i++;
            k = 0;
            do
            {
				if ((strlen(av[i]) < 1))
					break;
                std::cout << (char)toupper(av[i][k]);
                k++;
            } while (av[i][k]);
            if (av[i + 1])
                std::cout << " ";
        }
    }
    return (0);
}