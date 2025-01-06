#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
const int LEN = 10;
string books[LEN] = {"The Great Adventure", "The Silent Forest","Echoes of Tomorrow", "The Lost Kingdom","Shadows of Eternity","The Timekeeper's Secret","Wings of the Phoenix","Wings of the Phoenix"};
string authors[LEN] = {"Ava Harrison", "Ethan Carter"," Liam Blake","Sophie Rivers","Lucas Walker","Isabella Gray","Olivia Knight","James Morgan"," Chloe Bennett","Dylan CrossAuthor"};
long int library_id = 81;
int total_books = LEN;
string borrowed_books[LEN];

bool authentication(){
    int lib_id;

    system("cls");
    cout << "Please Enter Your Library ID: ";
    cin >> lib_id;

    if(lib_id == library_id){
        return true;
    } else {
        return false;
    }
}

void get_a_membership(){
    int id_input;

    system("cls");
    cout << "Please Choose Your Library ID [Only Numbers]: ";
    cin >> id_input;

    library_id = id_input;
}

void borrow_a_book(){
    int book_index;

    system("cls");
    cout << "Books List\n\n";

    for(int i = 0; i < LEN; ++i){
        bool book_taken = false;
        for(int j = 0; j < LEN; ++j){
            if(books[i] == borrowed_books[j]){
                book_taken = true;
                break;
            }
        }
        if(!book_taken){
            cout << i + 1 << ". " << books[i] << " by " << authors[i] << endl;
        }
    }

    cout << "\nWhich Book You Want to Borrow: ";
    cin >> book_index;

    total_books -= 1;
    borrowed_books[LEN - total_books - 1] = books[book_index - 1];

    system("cls");
    cout << "You Have Successfully Borrowed " << books[book_index - 1] << " written by " << authors[book_index - 1] << endl;
    cout << "Please Return it within a Week. " << endl;
}

void return_a_book(){
    int return_book_index;
    system("cls");
    cout << "List of Books you have Borrowed:\n\n";
    for(int i = 0; i < LEN - total_books; ++i){
        cout << i + 1 << ". " << borrowed_books[i] << endl;
    }

    cout << "\n\nWhich Book You Want to Return: ";
    cin >> return_book_index;

    borrowed_books[return_book_index - 1] = "";
    total_books += 1;
}

int main(){
    bool control = true, extra_input;

    while(control){
        system("cls");
        cout << "Welcome to Library Management System" << endl << endl;
        
        cout << "Do You Have A Membership? [1. Yes | 0. No]: ";
        cin >> extra_input;

        if(extra_input){
            if(authentication()){
                system("cls");
                cout << "What do you want to do? [1. Borrow a Book | 0. Return A Book]: ";
                cin >> extra_input;
                if(extra_input){
                    borrow_a_book();
                    cout << "1. Go Back To Menu | 0. Exit: ";
                    cin >> extra_input;
                    if(extra_input){
                        control = true;
                    } else {
                        control = false;
                    }
                } else {
                    if(total_books != LEN){
                        return_a_book();
                        system("cls");
                        cout << "1. Go Back To Menu | 0. Exit: ";
                        cin >> extra_input;
                        if(extra_input){
                            control = true;
                        } else {
                            control = false;
                        }
                    }
                }
            }
        } else {
            get_a_membership();
        }
    }
}
