#include <iostream>
#include <string>

using namespace std;

int* split(string S1, int num) {
    string delim = " ";
    int pos = 0, count = 0;
    string stringBeSpl;
    int* arr = new int[num];  // تخصيص مصفوفة ديناميكيًا

   
    while ((pos = S1.find(delim)) != string::npos && count < num) {
        stringBeSpl = S1.substr(0, pos);
        if (!stringBeSpl.empty()) {
            arr[count++] = stoi(stringBeSpl);
        }
        S1.erase(0, pos + delim.length());
    }

    // إدخال آخر عدد بعد آخر مسافة
    if (!S1.empty() && count < num) {
        arr[count++] = stoi(S1);
    }

    return arr;  // إرجاع مؤشر إلى المصفوفة
}

int main() {
    int num;
    string stringOfNumber;

    cin >> num;
    cin.ignore(); 
    getline(cin, stringOfNumber);

    int* arr = split(stringOfNumber, num); 

    long Sum = 0;
    for (int x = 0; x < num; x++) {
        Sum += arr[x];
    }
    cout << Sum << endl;

    delete[] arr;

    return 0 ;
}