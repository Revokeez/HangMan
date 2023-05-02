#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <fstream>
#define hand HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE)
#define color SetConsoleTextAttribute
using namespace std;

//#define color SetConsoleTextAttribute

const int OPPORTUNITIES = 6;

string selectedWord;
bool guessedLetters[7];
int guessCount = 0;
string gallows[7];
string words[20];
int wins = 0;

void Init() {
    srand(time(nullptr)); //random number generator
    int rIndex = rand() % 3; // Get random index
    selectedWord = words[rIndex]; // Select word
    guessCount = 0;
    for (int i = 0; i < 6; i++) {
        guessedLetters[i] = false;
    }
    gallows[0] = "_____ \n"
        "| |   \n"
        "|     \n"
        "|     \n"
        "|     \n"
        "|______ \n";
    gallows[1] = "_____ \n"
        "| |   \n"
        "| O   \n"
        "|     \n"
        "|     \n"
        "|______ \n";
    gallows[2] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "| |  \n"
        "|    \n"
        "|______ \n";
    gallows[3] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "|/|  \n"
        "|    \n"
        "|______ \n";
    gallows[4] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "|/|\\ \n"
        "|    \n"
        "|______ \n";
    gallows[5] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "|/|\\ \n"
        "|/   \n"
        "|______ \n";
    gallows[6] = "_____  \n"
        "|  |  \n"
        "|  O  \n"
        "| /|\\  \n"
        "| / \\  \n"
        "|______";

}
void ShowGameStartScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 2);
    cout << R"(
    ___     ___          ___        _____        __     ________
   |   |   |   |        / _ \       | |\ \      | |   / _______|
   |   |___|   |       / / \ \      | | \ \     | |  / /
   |           |      / /___\ \     | |  \ \    | | | |
   |    ___    |     / ______\ \    | |   \ \   | | | |    ______     
   |   |   |   |    / /       \ \   | |    \ \  | | | |    |___ |
   |   |   |   |   / /         \ \  | |     \ \ | |  \ \______| |    
   |___|   |___|  /_/           \_\ |_|      \_\|_|   \_________|
)";

    cout << R"( 
    ___        ___          ___        _____        __
   |   \      /   |        / _ \       | |\ \      | |
   |    \    /    |       / / \ \      | | \ \     | |
   |  |\ \  / /|  |      / /___\ \     | |  \ \    | |
   |  | \ \/ / |  |     / ______\ \    | |   \ \   | |
   |  |  \__/  |  |    / /       \ \   | |    \ \  | |
   |  |        |  |   / /         \ \  | |     \ \ | |
   |__|        |__|  /_/           \_\ |_|      \_\|_|
)";
    Sleep(4000);
}

void ShowBoard() {
    system("CLS");
    cout << gallows[guessCount] << endl;

    for (int i = 0; i < selectedWord.length(); i++) {
        if (guessedLetters[i] == true) {
            cout << selectedWord[i] << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void ShowInputOptions() {
    cout << "You have " << OPPORTUNITIES - guessCount << " tries left." << endl;
    cout << "Enter any letter" << endl;
}

string GetInput() {
    string input;
    cin >> input;
    return input;
}

bool IsValidInput(string input) {
    if (input.length() == 1 && input != " " && isalpha(input[0])) {//isalpha means is it a letter
        return true;
    }
    else {
        cout << "Invalid input. Please enter a single letter." << endl;
        return false;
    }
}

void ProcessInput(string input)
{
    int counter = 0;

    for (int i = 0; i < selectedWord.length(); i++)
    {
        if (input[0] == selectedWord[i])
        {
            guessedLetters[i] = true;
            counter++;
        }

    }
    if (counter == 0)
    {
        guessCount++;

    }
}


bool CheckWin()
{

    for (int i = 0; i < selectedWord.length(); i++)
    {
        if (guessedLetters[i] == false)
        {
            return false;
        }
    }
    return true;
}

bool CheckLoss()
{
    if (guessCount >= OPPORTUNITIES)//if guessCount is greater or equal then OPERTUNITIES that means the player lost
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsGameOver()
{
    return (CheckWin() || CheckLoss());
}
void ShowGameOverScreen()
{
    ShowBoard();
    cout << endl;
    cout << "Game Over!\n";
    if (CheckWin())
    {
        cout << "You Won!" << endl;
        cout << "You have " << guessCount << " incorrect guesses" << endl;
    }
    else
    {
        cout << "You Lost! The word was: " << selectedWord;
    }
}

void Start() {
    string input;
    Init();
    ShowGameStartScreen();
    do {
        ShowBoard();
        do {
            ShowInputOptions();
            input = GetInput();
        } while (!IsValidInput(input));
        ProcessInput(input);
    } while (!IsGameOver());
    ShowGameOverScreen();
}

void PassingWords() {
    ifstream readFile("words.txt");
    string text;
    int i = 0;
    while (getline(readFile, text))
    {
        text = text;
    }
    stringstream seperate(text);
    while (getline(seperate, text, '/'))
    {

        words[i] = text;

        i++;
    }
    readFile.close();
}


void CreateAccount()
{

    ifstream readFile("Usernames.txt");
    string text, text2;
    string username;
    string password;
    string loginusernames[10];
    int i = 0;
    int limit = 0;
    while (getline(readFile, text))
    {
        text = text;
    }
    stringstream seperate(text);
    //Usernames
    while (getline(seperate, text, '/'))
    {

        loginusernames[i] = text;
        i++;
        limit++;
    }
    readFile.close();
    ///////////////////////////////////

    ifstream readFile2("passwords.txt");
    string textp, textp2;
    string usernamep;
    string passwordp;
    string loginpasswords[10];
    i = 0;
    limit = 0;
    while (getline(readFile2, textp))
    {
        textp = textp;
    }
    stringstream seperate2(textp);
    //Usernames
    while (getline(seperate2, textp, '/'))
    {

        loginpasswords[i] = textp;
        i++;
        limit++;
    }
    readFile2.close();

    string usernameinput, passwordinput;
    cout << R"(
            _____________________
            |                   |
            |   Create Account  |
            |                   |
            ---------------------
            )" << endl;

    cout << "Enter your account name\n";
    cin >> usernameinput;
    cout << "Enter your password\n";
    cin >> passwordinput;

    for (int i = 0; i < limit; i++)
    {
        if (loginusernames[i] == usernameinput)
        {
            cout << "This username already exist\n";
            cout << "Enter your account name\n";
            cin >> usernameinput;
            cout << "Enter your password\n";
            cin >> passwordinput;
            i = 0;
        }
        else if (usernameinput.length() < 8 && passwordinput.length() < 8)
        {
            cout << "Please enter a valid length for your username or password\n";
            cout << "Enter your account name\n";
            cin >> usernameinput;
            cout << "Enter your password\n";
            cin >> passwordinput;
            i = 0;
        }
        system("CLS");
    }
    cout << "Account succesfuly created";
    system("pause");
    ofstream NewUsername("Usernames.txt", ofstream::app);

    NewUsername << usernameinput << "/";

    NewUsername.close();

    ofstream NewPassword("passwords.txt", ofstream::app);

    NewPassword << passwordinput << "/";

    NewPassword.close();

    ofstream SignalPort("SignalPort.txt");

    SignalPort << "SendInformation";

    SignalPort.close();

}
void Login()
{
    ifstream readFile("Usernames.txt");
    string text, text2;
    string loginusernames[10];
    int i = 0;
    int limit = 0;
    while (getline(readFile, text))
    {

    }
    stringstream seperate(text);
    //Usernames
    while (getline(seperate, text, '/'))
    {
        loginusernames[i] = text;
        i++;
        limit++;
    }
    readFile.close();
    ///////////////////////////////////

    ifstream readFile2("passwords.txt");
    string textp, textp2;
    string loginpasswords[10];
    i = 0;
    while (getline(readFile2, textp))
    {

    }
    stringstream seperate2(textp);
    //Usernames
    while (getline(seperate2, textp, '/'))
    {
        loginpasswords[i] = textp;
        i++;
    }
    readFile2.close();

    cout << R"(
            _____________________
            |                   |
            |      Login:       |
            |                   |
            ---------------------
            )" << endl;
    string usernameinput, passwordinput;
    cout << "Enter your account name\n";
    cin >> usernameinput;
    cout << "Enter your password\n";
    cin >> passwordinput;
    int checkUserLimit = 0;
    for (int j = 0; j < limit; j++)
    {
        cout << j << endl;
        system("pause");
        if (usernameinput == loginusernames[j] && passwordinput == loginpasswords[j])
        {
            cout << "Welcome: " << usernameinput << endl;
            system("pause");
            system("CLS");
            break;
        }
        else if (checkUserLimit == limit - 1)
        {
            system("CLS");
            cout << "Username or password dosent match\n";
            cout << "Enter your account name\n";
            cin >> usernameinput;
            cout << "Enter your password\n";
            cin >> passwordinput;
            j -= j + 1;
            checkUserLimit = 0;
        }
        checkUserLimit += 1;
    }

    ofstream SignalPort("SignalPort.txt");

    SignalPort << "SendInformation";

    SignalPort.close();
}

void ServerActive()
{
    ofstream Activating("IsServerActive.txt");

    Activating << "ActiveServer";

    Activating.close();


}
void ServerShutDown()
{
    ofstream Shutingdown("IsServerActive.txt");

    Shutingdown << "NA";

    Shutingdown.close();
}

int main()
{
    PassingWords();
    string answer = "";
    do
    {
        system("CLS");
        ServerActive();
        cout << "Press [1] Login to your account or Press [2] Create account: ";
        cin >> answer;
        while (answer != "1" && answer != "2")
        {
            system("CLS");
            cout << "Please enter a valid opcion\n";
            cout << "Press [1] Login to your account or Press [2] Create account";
            cin >> answer;

        }
        if (answer == "1")
        {
            Login();

        }
        else if (answer == "2")
        {
            CreateAccount();
            system("CLS");
            Login();
        }
        Start();
        cout << "Want to play again press [0] if not press any number\n";
        cin >> answer;
    } while (answer == "0");

    ServerShutDown();

    return 0;
}