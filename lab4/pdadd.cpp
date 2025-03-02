#include "diary.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void add_entry(vector<Diary>& my_diary, const string& date, const vector<string>& text) {
    // Check if an entry with the same date exists
    bool found = false;
    for (auto& entry : my_diary) {
        if (entry.readDate() == date) {
            entry.Reset(); // Reset the existing entry
            entry.SetDate(date);
            for (const auto& line : text) {
                entry.AddLine(line); // Update the existing entry
            }
            found = true;
            break;
        }
    }
    // If not found, add a new entry
    if (!found) {
        Diary new_entry;
        new_entry.SetDate(date);
        for (const auto& line : text) {
            new_entry.AddLine(line);
        }
        my_diary.push_back(new_entry);
    }
}

int main() {
    string filename = "diary.txt"; // Change this to the actual diary file path

    vector<Diary> my_diary;
    read_to_memory(filename, my_diary);

    string date;
    cout << "Enter date for the diary entry (e.g., 2024-05-07): ";
    getline(cin, date);

    cout << "Enter lines for the diary entry. Type a single '.' or press Ctrl+D/Ctrl+Z to finish:" << endl;

    vector<string> text;
    string line;
    while (getline(cin, line)) {
        if (line == ".") {
            break;
        }
        text.push_back(line);
    }

    add_entry(my_diary, date, text);
    write_to_file(filename, my_diary);

    cout << "Diary entry added/updated successfully." << endl;
    return 0;
}
