
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

#define color SetConsoleTextAttribute

/*bool gameRunning = true;
string words[3] = { "house", "mirror", "floor" };
string selectedWord;
bool guessedLetters[10];
int guessCount = 0;

void hangman1() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    color(hConsole, 7);
    cout << R"(

                      ___  
                      |  
                      |  
                      |   
                      |   
                      |__  
    
)";
}
void hangman2() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 2);
    cout << R"(
                      ___  
                      |  |  
                      |  
                      |  
                      |  
                      |__  
    
)";
}
void hangman3() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 6);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      |  
                      |   
                      |__  
    
)";
}
void hangman4() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 3);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      |  |  
                      |   
                      |__  
    
)";
}
void hangman5() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 1);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      | /|\  
                      |   
                      |__  
    
)";
}
void hangman6() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 4);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      | /|\  
                      | / \  
                      |__  
    
)";

}
void ShowDrawings()
{
    int rIndex = rng.Next(words.Length);//This
    selectedWord = words[rIndex];//This will choose a word from the array word.
    guessedLetters = new bool[selectedWord.Length];

    string words[3] = { "house", "mirror", "floor" };

    srand(time(nullptr));
    int rIndex = rand() % 3;
    selectedWord = words[rIndex];
    guessCount = 0;

    switch (guessCount)
    {
    case 0:
        hangman1();
        break;
    case 1:
        hangman2();
        break;
    case 2:
        hangman3();
        break;
    case 3:
        hangman4();
        break;
    case 4:
        hangman5();
        break;
    case 5:
        hangman6();
        break;
    }

    //selectedWord = words[rIndex];
}
int main()
{

    int repetir = 0;
    string selectedword[5];//Por ahora
    string playerChoice;//La opcion que el jugador escogio
    

    do {
        hangman1();
        hangman2();
        hangman3();
        hangman4();
        hangman5();
        hangman6();
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        color(hConsole, 7);
        repetir++;
    } while (repetir < 2);
    hangman6();
    cout << "WELCOME TO HANGMAN\n";
    cout << "Wright the letter:";
    cin >> playerChoice;
}*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int OPPORTUNITIES = 6;
string words[3] = { "house", "mirror", "floor" };
string selectedWord;
bool guessedLetters[6];
int guessCount = 0;
string gallows[7];

void Init() {
    srand(time(nullptr)); // Seed random number generator
    int rIndex = rand() % 3; // Get random index
    selectedWord = words[rIndex]; // Select word
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
        "|  |  \n";
        "|  O  \n";
        "| /|\\  \n";
        "| / \\  \n";
        "|______"

}
void ShowGameStartScreen() {
    cout << "Welcome to Hangman" << endl;
}

void ShowBoard() {
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
    cout << "Game Over!";
    if (CheckWin())
    {
        cout << "You Won!" << endl;
        cout << "You have" << guessCount << "incorrect guesses" << endl;
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
int main()
{
    Start();

    return 0;
}


