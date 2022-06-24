#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string correctChar(string guess, string answer)
{
    string result = "";
    for (int i = 0; i < 5; i++)
    {
        if (guess[i] == answer[i])
            result = toupper(guess[i]);
        
    }
    return result;
}

int main()
{
    string ANSWER;
    cout << "Enter the answer to the Wordle. " << endl;
    cin >> ANSWER;

    cout << "You have 6 attempts to guess the Wordle. " << endl;
    cout << "Correct characters will be capitalized, incorrect characters will remain lowercase.\nCorrect characters in the wrong location will be noted.\n" << endl;

    //THERE ARE SIX GUESSES
    //THERE ARE FIVE LETTERS

    //array to keep all the guesses, 0-5
    string guess[6];
    
    //loops throught 1-6 guesses
    for(int i = 1; i <= 6; i++)
    {
        //array for each guess word
        char chars[5];
        //array for each correct char, 0 in wrong places
        char correctChars[5];

        cout << "*GUESS " << i << "*\n" << endl;
        //user input guess
        cin >> guess[i];

        cout << endl;
        
        //if correct guess
        if(guess[i] == ANSWER)
        {
            cout << "Congrats! You used " << i << "/6 tries!" << endl;
            break;
        }
        string updatedGuess = correctChar(guess[i], ANSWER);
        cout << updatedGuess << endl;
        for(int j = 0; j < 5; j++)
        {
            if(islower(updatedGuess.at(j)))
            {
                if(updatedGuess.at(j)== ANSWER.at(0) || updatedGuess.at(j)== ANSWER.at(1) || updatedGuess.at(j)== ANSWER.at(2) || updatedGuess.at(j)== ANSWER.at(3) || updatedGuess.at(j)== ANSWER.at(4))
                {
                    cout << "The letter " << updatedGuess.at(j) << " appears somewhere else in the answer." << endl;
                }
            }
        }
        

        
    }
}

