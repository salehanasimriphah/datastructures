#include <iostream>
using namespace std;

int main() {
    int arr[6]; 
for (int i = 0; i < 6; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "\nNumbers entered by the user:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Number " << i + 1 << ": " << arr[i] << endl;
    }

    return 0;
}
