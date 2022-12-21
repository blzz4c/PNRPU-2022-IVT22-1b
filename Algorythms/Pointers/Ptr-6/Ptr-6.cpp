#include<iostream>
#include<string>

int main()
{
    setlocale(LC_ALL, "RUS");
    int countC, countV;
    countC = countV = 0;

    std::string s;
    std::cin >> s;

    const char* sptr = s.c_str();
    for (int i = 0; i < s.length(); i++)
    {
        switch (*sptr)
        {
        case 'А':
        case 'У':
        case 'О':
        case 'Е':
        case 'И':
        case 'Я':
        case 'Ю':
        case 'Э':
        case 'Ы':
        case 'а':
        case 'у':
        case 'о':
        case 'е':
        case 'и':
        case 'я':
        case 'ю':
        case 'э':
        case 'ы':
            countV++;
            break;
        default:
            countC++;
            break;
        }

        *sptr++;

    }

    std::cout << "Количество гласных = " << countV << std::endl;
    std::cout << "Количество согласных = " << countC << std::endl;

    return 0;
}