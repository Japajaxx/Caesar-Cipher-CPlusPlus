#include <iostream>
#include <string>
using namespace std;

string caesar_cipher(string statement, int shift){
    string result = "";
    char currentChar;
    char base;
    for(int i = 0; i < statement.length(); i++){
        currentChar = statement[i];
        if (isalpha(currentChar)) {
            base = islower(currentChar) ? 'a' : 'A';
            currentChar = (currentChar - base + shift + 26) % 26 + base;
        }
        result += currentChar;
    }
    return result;
}

int main(){

    string statement;
    bool is_encrypt = false;
    int choice = 1;

    cout<<"\nInput a statement: ";
    getline(cin, statement);

    while(choice != 3){
        switch(choice){
            case 1:
                if(is_encrypt){
                    cout<<"\nThis statement is already encrypted";
                }
                else {
                    statement = caesar_cipher(statement, 3);
                    is_encrypt = true;
                    cout<<"\nEncrypted Statement: "<<statement;
                }
                break;
            case 2:
                if(!is_encrypt){
                    cout<<"\nThis statement is already decrypted";
                }
                else {
                    statement = caesar_cipher(statement, -3);
                    is_encrypt = false;
                    cout<<"\nDecrypted Statement: "<<statement;
                }
                break;
            case 3:
                break;
            default:
                cout<<"\nThe number you have input is not in the range";
                break;
        }
        cout<<"\n\nTo encrypt this statment, type 1\nTo decrypt this statement, type 2\nTo quit, type 3\n:";
        cin >> choice;
    }
    cout<<"\nThank you";
}



