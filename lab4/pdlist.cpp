#include "diary.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void list_entries(const vector<Diary>& my_diary, const string& start_date, const string& end_date) {
    for (const auto& diary : my_diary) {
        string date = diary.readDate();
        // Check if the diary date is within the range
        if ((start_date.empty() || date >= start_date) &&
            (end_date.empty() || date <= end_date)) {
            cout << "#" << date << endl;
            for (VStringSize i = 0; i < diary.Size(); ++i) {
                cout << diary.readText(i) << endl;
            }
            cout << endl; // Separate entries
        }
    }
}

int main(int argc, char* argv[]) {
    string filename = "diary.txt"; // Change this to the actual diary file path
    vector<Diary> my_diary;
    read_to_memory(filename, my_diary);

    // Sort entries by date
    sort(my_diary.begin(), my_diary.end(), date_sort);

    string start_date, end_date;
    if (argc >= 2) {
        start_date = argv[1];
    }
    if (argc >= 3) {
        end_date = argv[2];
    }

    list_entries(my_diary, start_date, end_date);

    return 0;
}
