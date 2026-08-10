#include <iostream>
#include<string>
using namespace std;
struct Author {
    string name;          
    string nationality;   
};
struct Book {
    string title;     
    string ISBN;      
    double price;
    int    pubYear;
    Author author;   
};
int main() {
    Book library[3];   
    for (int i = 0; i < 3; i++) {
        cout << " Enter details for Book " << i + 1 << " ---" << endl;
        cout << "Enter title      : ";
        cin  >> library[i].title;
        cout << "Enter ISBN       : ";
        cin  >> library[i].ISBN;
        cout << "Enter price      : ";
        cin  >> library[i].price;
        cout << "Enter publication year   : ";
        cin  >> library[i].pubYear;
        cout << "Enter author name        : ";
        cin  >> library[i].author.name;
        cout << "Enter author nationality : ";
        cin  >> library[i].author.nationality;
    }
    cout << "Books published after 2015:" << endl;
    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (library[i].pubYear > 2015) {
            found = true;
            cout << "Title       : " << library[i].title              << endl;
            cout << "ISBN        : " << library[i].ISBN               << endl;
            cout << "Price       : " << library[i].price              << endl;
            cout << "Pub. Year   : " << library[i].pubYear            << endl;
            cout << "Author      : " << library[i].author.name        << endl;
            cout << "Nationality : " << library[i].author.nationality  << endl;
        }
    }
    if (!found)
        cout << "No books found published after 2015"<<endl;
    return 0;
}
