#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void DatavaseLogo()
{
    cout << R"(
    -----------------
    |               |
    |    Database   |
    |               |
    |_______________|)" << endl;
}

int main()
{
    string usersUsernames[100];
    string usersPasswords[100];
    string usernamesText,passwordsText;
    int num = 1;
    while (num != 0)
    {    
        int e = 0;
        int limit = 0;

        system("CLS");
        ifstream readUserUsernamesData("Users_Usernames.txt");

        while (getline(readUserUsernamesData, usernamesText))
        {

        }
        stringstream seperateUsernames(usernamesText);
        //Usernames
    
        while (getline(seperateUsernames, usernamesText, '/'))
        {
            usersUsernames[e] = usernamesText;
            e++;
        }
        readUserUsernamesData.close();
        ////////////////////////////////

        ifstream readreadUserPasswordsDataData("Users_Passwords.txt");

        while (getline(readreadUserPasswordsDataData, passwordsText))
        {
        
        }
        stringstream seperatePasswords(passwordsText);
        //Usernames
        e = 0;
        while (getline(seperatePasswords, passwordsText, '/'))
        {
            usersPasswords[e] = passwordsText;
            e++;
            limit++;
        }
        readreadUserPasswordsDataData.close();
    
        DatavaseLogo();
            for(int i = 0; i < limit; i++)
            {   
                cout << endl;
                cout << R"(Usernames :)"<< usersUsernames[i]<< R"( | )";
                cout << R"(Passwords :)"<< usersPasswords[i]<<endl;
            }
            cout << "Press 1 to refresh the dataBase, Press 0 to quit\n";
            cin >> num;

    }




}

