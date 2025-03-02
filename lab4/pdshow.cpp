#include "diary.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void show_entry(const vector<Diary>& my_diary, const string& date) {
    for (const auto& diary : my_diary) {
        if (diary.readDate() == date) {
            cout << "#" << date << endl;
            for (VStringSize i = 0; i < diary.Size(); ++i) {
                cout << diary.readText(i) << endl;
            }
            return; // Exit after showing the matched entry
        }
    }
    // If no matching entry is found
    cout << "No entry found for the date: " << date << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <date>" << endl;
        return 1;
    }

    string date = argv[1];
    string filename = "diary.txt"; // Change this to the actual diary file path
    vector<Diary> my_diary;
    read_to_memory(filename, my_diary);

    show_entry(my_diary, date);

    return 0;
}
