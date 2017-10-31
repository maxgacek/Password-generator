#include<iostream>
#include <fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

static const char alphnum[]="0123456789" "!@#$%^&*" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int strLen=sizeof(alphnum)-1;

char GetRand()
{
    return alphnum[rand()%strLen];
}

int saveFile(string pass)
{
    ofstream myfile;
    myfile.open ("password.txt");
    myfile << pass << "\n";

    cout << "Password saved...";

    myfile.close();
}

int main()
{
    int n,c=0,s=0;
    srand(time(0));

    cout<<"Password length: ";

    cin>>n;

    cout<<"Generated password:   ";
    N:

    char C;
    string P;

    for(int z=0; z < n; z++)
    {
        C=GetRand();
        P+=C;

        if(isdigit(C))
        {
            c++;
        }

        if(C == '!' || C == '@' || C == '$' || C == '%' ||  C == '^' || C == '&'|| C == '*'|| C == '#')
        {
            s++;
        }
    }

    if(n > 2 && (s == 0 || c == 0))
    {
        goto N;
    }

    cout << P << "\n";

    string z;

    cout << "Do you want to save your password? \n";
    cout << "y or n? \n";
    cin >> z;

    if (z == "y" || z == "Y")
    {
        saveFile(P);
    }

    return 0;
}
