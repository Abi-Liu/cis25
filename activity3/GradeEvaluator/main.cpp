#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;

    if (score < 60) {
        cout << "Fail";
    } else if (score < 70) {
        cout << "Pass";
    } else if (score < 90) {
        cout << "Good";
    } else if (score < 100) {
        cout << "Excellent";
    }
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.