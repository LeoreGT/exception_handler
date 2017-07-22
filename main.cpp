#include <iostream>
#include "exception_handler.h"

int CheckGuess(int userGuess, int x);

/* ------------------------------------- */

int main()
{
  int x = rand()%10+1;
  int userGuess;

  cout << "Guess a number 1 - 10: " << endl;
  cin >> userGuess;
  // system ("clear");
  CheckGuess(userGuess, x);
  return 0;
}

/* ------------------------------------- */

int CheckGuess(int _userGuess, int _x)
{
  try
  {
    if (_userGuess == _x)
    {
      cout << "Correct! You win. You're amazing." << endl;
      return 0;
    }

    else
    {
      throw TException_t<int> (__FILE__, __LINE__, _userGuess, "You guessed wrong, silly.");
    }
  }
  catch(TException_t<int>& _t)
  {
    cout << "Your guess: "  << _t.GetObject()      << endl;
    cout << "File: "        << _t.GetFile()        << endl;
    cout << "Line: "        << _t.GetLine()        << endl;
    cout << "Description: " << _t.GetDescription() << endl;
    cout << "\nThe correct answer was: " << _x << endl;
    return 0;
  }
}

/* ------------------------------------- */
