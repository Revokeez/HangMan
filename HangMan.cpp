#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <cctype>
using namespace std;

#define hand HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE)
#define color SetConsoleTextAttribute

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
    hand;
    color(hConsole, 7);
    gallows[0] = "_____ \n"
        "| |   \n"
        "|     \n"
        "|     \n"
        "|     \n"
        "|______ \n";
    hand;
    color(hConsole, 2);
    gallows[1] = "_____ \n"
        "| |   \n"
        "| O   \n"
        "|     \n"
        "|     \n"
        "|______ \n";
    hand;
    color(hConsole, 6);
    gallows[2] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "| |  \n"
        "|    \n"
        "|______ \n";
    hand;
    color(hConsole, 3);
    gallows[3] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "|/|  \n"
        "|    \n"
        "|______ \n";
    hand;
    color(hConsole, 1);
    gallows[4] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "|/|\\ \n"
        "|    \n"
        "|______ \n";
    hand;
    color(hConsole, 4);
    gallows[5] = "_____  \n"
        "| |  \n"
        "| O  \n"
        "|/|\\ \n"
        "|/   \n"
        "|______ \n";
    hand;
    color(hConsole, 5);
    gallows[6] = "_____  \n"
        "|  |  \n";
        "|  O  \n";
        "| /|\\  \n";
        "| / \\  \n";
        "|______";

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


