#include <iostream>
#include <memory>
using namespace std;

void move(unique_ptr<string>&from, unique_ptr<string>&to) {
    if (!from) {
        cout << "No car in this spot" << endl;
        return;
    }

    if (to) {
        cout << "Parking spot already occupied" << endl;
        return;
    }

    to = move(from);
}

void removeCar(unique_ptr<string> &spot) {
    if (!spot) {
        cout << "No car in this spot" << endl;
        return;
    }
    cout << "Car removed from parking" << endl;
    spot->clear();
}

int main() {
    unique_ptr<string> spot1(new string("ABC-123"));
    unique_ptr<string> spot2(new string("BCD-321"));

    move(spot1, spot2);
    removeCar(spot1);
}