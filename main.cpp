#include <iostream>
using namespace std;

#include "WordsStore.h"

int length = 0;
string word;
string letter;
string solution = "_";
string wrongLetters;
bool over = false;

void getWord()
{
    bool inputAccepted = false;
    while (inputAccepted == false)
    {
        cout << "Enter a length between 4 and 7 for the secret word: ";
        cin >> length;

        srand(time(0));
        int index = rand() % 10;

        if (length == 4)
        {
            word = FourLetters[index];
            inputAccepted = true;
        }
        else if (length == 5)
        {
            word = FiveLetters[index];
            inputAccepted = true;
        }
        else if (length == 6)
        {
            word = SixLetters[index];
            inputAccepted = true;
        }
        else if (length == 7)
        {
            word = SevenLetters[index];
            inputAccepted = true;
        }
        else
        {
            cout << "\nOpps! That input isn't quite right, lets try again.\n";
        }
    }
    for (int i = 0; i < length - 1; i++)
    {
        solution = solution + "_";
    }
}

void checkWord()
{
    int dash = solution.find("_");

    if (dash == string::npos)
    {
        cout << "YAY you win!!!\n";
        over = true;
    }
}

void correctGuess()
{
    for (int i = 0; i < length; i++)
    {
        if (word[i] == letter[0])
        {
            solution[i] = letter[0];
        }
    }
    checkWord();
}

void printHangman()
{
    if (wrongLetters.length() == 1)
    {
        cout << "-------" << endl;
        cout << "|/  :  " << endl;
        cout << "|      " << endl;
        cout << "|      " << endl;
        cout << "|      " << endl;
        cout << "|      " << endl;
        cout << "|------" << endl;
    }

    if (wrongLetters.length() == 2)
    {
        cout << "-------" << endl;
        cout << "|/  :  " << endl;
        cout << "|   O  " << endl;
        cout << "|      " << endl;
        cout << "|      " << endl;
        cout << "|      " << endl;
        cout << "|------" << endl;
    }

    else if (wrongLetters.length() == 3)
    {
        cout << "-------" << endl;
        cout << "|/  :  " << endl;
        cout << "|   O  " << endl;
        cout << "|   |  " << endl;
        cout << "|   |  " << endl;
        cout << "|      " << endl;
        cout << "|------" << endl;
    }

    else if (wrongLetters.length() == 4)
    {
        cout << "-------" << endl;
        cout << "|/  :  " << endl;
        cout << "|   O  " << endl;
        cout << "|  /|  " << endl;
        cout << "|   |  " << endl;
        cout << "|      " << endl;
        cout << "|------" << endl;
    }

    else if (wrongLetters.length() == 5)
    {
        cout << "-------" << endl;
        cout << "|/  :  " << endl;
        cout << "|   O  " << endl;
        cout << "|  /|\\" << endl;
        cout << "|   |  " << endl;
        cout << "|      " << endl;
        cout << "|------" << endl;
    }

    else if (wrongLetters.length() == 6)
    {
        cout << "-------" << endl;
        cout << "|/  :" << endl;
        cout << "|   O" << endl;
        cout << "|  /|\\" << endl;
        cout << "|   |" << endl;
        cout << "|  / " << endl;
        cout << "|------" << endl;
    }

    else if (wrongLetters.length() == 7)
    {
        cout << "-------" << endl;
        cout << "|/  :" << endl;
        cout << "|   O" << endl;
        cout << "|  /|\\" << endl;
        cout << "|   |" << endl;
        cout << "|  / \\" << endl;
        cout << "|------" << endl;
        cout << "OH no! game over! The word was " + word;
        over = true;
    }
}

void wrongGuess()
{
    cout << "\nOh no! theres no letter " + letter + " in this word.\n";
    wrongLetters = wrongLetters + letter[0];
    printHangman();
    cout << "\nWrong guesses: " + wrongLetters + "\n";
}

void checkLetter()
{

    cout << "\n\nEnter the letter you want to guess: ";
    cin >> letter;

    int location = word.find(letter);

    if (location != string::npos)
    {
        correctGuess();
    }
    else
    {
        wrongGuess();
    }
}

int main()
{
    cout << "Welcome to Hangman.\n";
    printHangman();
    getWord();
    cout << solution;

    while (over == false)
    {
        checkLetter();
        cout << "Your word: " + solution;
    }

    return 0;
}
