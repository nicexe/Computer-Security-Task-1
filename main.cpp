#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void showMenu();

int menuSelection();

string userInput();

bool isNumeric(string);

char rotateChar(int, bool, char);

string encrypt(int, string);

string decrypt(int, string);

void bruteforce(string, int);

int main()
{
    int option = -1, key;
    string clearText = "", cipherText = "";
    int substringLength = -1;

    while (option != 0)
    {
        option = menuSelection();

        if (option == 1)
        {
            cout << "\nEnter clear-text to be encrypted:\n";
            clearText = userInput();
            key = -1;

            while ((key < 0) || (key > 25))
            {
                cout << "Enter encryption key (0-25): ";
                string temp = userInput();

                if (temp == "")
                {
                    cout << "Key must not be empty\n";
                }
                else
                {
                    if (isNumeric(temp))
                    {
                        key = stoi(temp);
                    }
                }

                if (!((key >= 0) && (key <= 25)))
                {
                    cout << "Key must be numeric and between 0 and 25\n";
                }
            }

            cipherText = encrypt(key, clearText);

            cout << "\nClear-text: " << clearText << "\nKey:        " << key << "\nOutput:     " << cipherText << "\n\n";

        }
        else if (option == 2)
        {
            cout << "\nEnter cipher-text to be decrypted:\n";
            cipherText = userInput();
            key = -1;

            while ((key < 0) || (key > 25))
            {
                cout << "Enter decryption key (0-25): ";
                string temp = userInput();

                if (temp == "")
                {
                    cout << "Key must not be empty\n";
                }
                else
                {
                    if (isNumeric(temp))
                    {
                        key = stoi(temp);
                    }
                }

                if (!((key >= 0) && (key <= 25)))
                {
                    cout << "Key must be numeric and between 0 and 25\n";
                }
            }

            clearText = decrypt(key, cipherText);

            cout << "\nCipher-text: " << cipherText << "\nKey:         " << key << "\nOutput:      " << clearText << "\n\n";

        }
        else if (option == 3)
        {
            substringLength = -1;
            string temp;

            cout << "\nEnter cipher-text to be bruteforced:\n";
            cipherText = userInput();

            while ((substringLength < 0) || (substringLength > cipherText.length()))
            {
                try
                {
                    cout << "\nEnter the length of the substring to be used in bruteforce\n(0-" << cipherText.length() << ") (0 selects the whole string):\n";

                    temp = userInput();
                    if (temp != "")
                    {
                        substringLength = stoi(temp);
                    }
                } catch (int e)
                {
                    cout << "\nException " << e << " caught";
                }

                if ((substringLength < 0) || (substringLength > cipherText.length()))
                {
                    cout << "\nInvalid input. Substring must be numeric and between 0 and " << cipherText.length();
                }
            }

            if (substringLength == 0)
            {
                substringLength = cipherText.length();
            }

            bruteforce(cipherText, substringLength);
        }
    }

    return 0;
}

void showMenu()
{
    //printing the menu
    cout << "Select an option from below:\n\n" <<

            "    1: Encrypt a string\n" <<
            "    2: Decrypt a string\n" <<
            "    3: Bruteforce a cipher-text\n" <<
            "    --\n" <<
            "    0: Exit\n\n" <<

            "Option: ";
}

int menuSelection()
{
    string option = "";

    // printing the menu until a valid input is parsed
    while ((option != "0") && (option != "1") && (option != "2") && (option != "3"))
    {
        showMenu();

        option = userInput();

        if ((option != "0") && (option != "1") && (option != "2") && (option != "3"))
        {
            cout << "Error: Invalid input\n\n";
        }
    }

    return (stoi(option)); // parsing option as integer
}

string userInput()
{
    string input;
    getline(cin, input);

    return (input);
}

bool isNumeric(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if ((str.at(i) < '0') || (str.at(i) > '9'))
        {
            return (false);
        }
    }

    return (true);
}

char rotateChar(int key, bool encryption, char c)
{
    if (!encryption) // if it is used for decryption the key must be negative
    {
        key = 26 - key % 26;
    }

    if ((c >= 65) && (c <= 90)) // character is capital
    {
        int min = 65, max = 90;
        c = (((c - min) + key) % ((max - min) + 1)) + min; // c-min makes the range of c from 65-90 to 0-25, c+min makes the range of c back to 65-90
    }
    else if ((c >= 97) && (c <= 122)) // character is not capital
    {
        int min = 97, max = 122;
        c = (((c - min) + key) % ((max - min) + 1)) + min; // c-min makes the range of c from 97-122 to 0-25, c+min makes the range of c back to 97-122
    }

    return (c);
}

string encrypt(int key, string clearText)
{
    string cipherText = "";

    for (int i = 0; i < clearText.length(); i++)
    {
        cipherText += rotateChar(key, true, clearText.at(i));
    }

    return cipherText;
}

string decrypt(int key, string cipherText)
{
    string clearText = "";

    for (int i = 0; i < cipherText.length(); i++)
    {
        clearText += rotateChar(key, false, cipherText.at(i));
    }

    return clearText;
}

void bruteforce(string cipherText, int substringLength)
{
    cout << "\nKey | ClearText\n____|____";

    for (int bKey = 0; bKey <= 25; bKey++)
    {
        string clearText = "";

        for (int i = 0; i < substringLength; i++)
        {
            clearText += rotateChar(bKey, false, cipherText.at(i));
        }

        cout << "\n" << setw(2) << bKey << "  | " << clearText;
    }

    cout << "\n\n\n";
}