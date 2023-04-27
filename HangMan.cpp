#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#define hand HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE)
#define color SetConsoleTextAttribute
using namespace std;

const int OPPORTUNITIES = 6;

string selectedWord;
bool guessedLetters[7];
int guessCount = 0;
string gallows[7];
string words[20];
int length = 0;

void title() {
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
    system("cls");
}
void Initialising() {
    srand(time(nullptr)); //random number generator
    int rIndex = rand() % length; // Get random index
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
        "|  |  \n"
        "|  O  \n"
        "| /|\\  \n"
        "| / \\  \n"
        "|______";

}
void ShowGameStartScreen() {
    cout << "Welcome to Hangman" << endl;
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
    Initialising();
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
    fstream readFile("words.txt");
    string text;
    while (getline(readFile, text))
    {
        text = text;
    }
    stringstream seperate(text);
    while (getline(seperate, text, '/'))
    {

        words[length] = text;

     
        length++;
    }
    readFile.close();
}

int main()
{
    PassingWords();
    title();

    Start();

    return 0;
}


