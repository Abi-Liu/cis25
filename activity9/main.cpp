#include <iostream>
#include <ostream>
using namespace std;

struct Date {
    short releaseYear;
    short releaseMonth;
    short releaseDay;
};

struct Movie {
    string name;
    Date date;
    string genre;
};

ostream& operator<<(ostream& os, const Date& date) {
    os << date.releaseMonth << "/" << date.releaseDay << "/" << date.releaseYear << endl;
    return os;
}

ostream& operator<<(ostream& os, const Movie& movie) {
    os << "name: " << movie.name << " genre: " << movie.genre << " date: " << movie.date << endl;
}

int main() {
    Movie movie;
    cout << "Please enter the name of the movie: " << endl;
    cin >> movie.name;
    cout << "Please enter the movie genre" << endl;
    cin >> movie.genre;
    cout << "Please enter the movie year" << endl;
    while (true) {
        cin >> movie.date.releaseYear;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid year" << endl;
        } else {
            break;
        }
    }

    cout << "Please enter the movie month" << endl;
    while (true) {
        cin >> movie.date.releaseMonth;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid month: e.g. 12" << endl;
        } else {
            break;
        }
    }

    cout << "Please enter the movie day" << endl;
    while (true) {
        cin >> movie.date.releaseDay;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid day" << endl;
        } else {
            break;
        }
    }

    cout << movie << endl;
}