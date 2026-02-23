#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

struct book{
    string title;
    string writer;
    int publicationYear;
};

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

void line(){
    cout << string(50,'=') << endl;
}

void showMenu(){
    line();
    cout << "SCHOOL LIBRARY SYSTEM" << endl;
    line();
    cout << "1. Add New Book" << endl;
    cout << "2. View Book List" << endl;
    cout << "3. Save The Book" << endl;
    cout << "4. Delete Book" << endl;
    cout << "5. Exit" << endl;
    line();
}

int main(){
    vector<book>libraryList;
    int choice;
    bool wrongInput;

    while (true){
        showMenu();
        do{
            cout << "Enter Option: ";
            cin >> choice;

            wrongInput = cin.fail();

            if(cin.fail()){
                cout << "Enter The Correct Input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while(wrongInput);
        cin.ignore();
        clearScreen();
        clearScreen();

        if(choice == 1){
            bool wrongYear;
            book newbook;
            line();
            cout << "ADD NEW BOOK" << endl;
            line();
            cout << "Enter The Book Title\t: ";
            getline(cin, newbook.title);
            cout << "Enter The Writer\t: ";
            getline(cin, newbook.writer);
            do{
                cout << "Enter Publication Year\t: ";
                cin >> newbook.publicationYear;

                wrongYear = cin.fail();

                if(cin.fail()){
                    cout << "Enter The Correct Input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(wrongYear);
            cin.ignore();
            line();
            libraryList.push_back(newbook);
            cout << "Book Added Succesfully" << endl;
            line();
        }else if(choice == 2){
            line();
            cout << "VIEW BOOK LIST" << endl;
            line();
            for(size_t i = 0; i < libraryList.size(); i++){
                cout << i+1 << " ." << libraryList[i].title << " - " << libraryList[i].writer << " - " << libraryList[i].publicationYear << endl;
            }
            line();
        }else if(choice == 3){
            line();
            cout << "SAVE THE BOOK" << endl;
            line();
            ofstream saveFile("book_list.txt");
            for(const auto& b : libraryList){
                saveFile << b.title << " - " << b.writer << " - " << b.publicationYear << endl; 
            }
            saveFile.close();
            cout << "Data Is Saved To book_list.txt" << endl;
        }else if(choice == 4){
            line();
            cout << "DELETE THE BOOK" << endl;
            line();
            if(libraryList.empty()){
                cout << "The Library Is Empty, Nothing Can Be Deleted" << endl;
                line();
            }else{
                for(size_t i = 0; i < libraryList.size(); i++){
                    cout << i+1 << " ." << libraryList[i].title << endl;
                }
                line();
                int deleteNumber;
                bool notNumber;
                do{
                    cout << "Enter Number: ";
                    cin >> deleteNumber;

                    notNumber = cin.fail();

                    if(cin.fail()){
                        cout << "Enter The Correct Input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while (notNumber);
                cin.ignore();

                size_t indeks = deleteNumber - 1;
                if(indeks >= 0 && indeks < libraryList.size()){
                    string titleDelete = libraryList[indeks].title;
                    libraryList.erase(libraryList.begin() + indeks);
                    cout << "Book " << titleDelete << " Delete Succesfully" << endl;
                line();
                }
            }
        }else if(choice == 5){
            break;
        }
    }
    clearScreen();
    return 0;
}