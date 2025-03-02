#include "diary.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int remove_entry(vector<Diary>& my_diary, const string& date) {
    for (auto it = my_diary.begin(); it != my_diary.end(); ++it) {
        if (it->readDate() == date) {
            my_diary.erase(it);
            return 0; // Success
        }
    }
    return -1; // Failure
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <date>" << endl;
        return -1;
    }

    string date = argv[1];
    string filename = "diary.txt"; // Change this to the actual diary file path
    vector<Diary> my_diary;
    read_to_memory(filename, my_diary);

    int result = remove_entry(my_diary, date);

    if (result == 0) {
        write_to_file(filename, my_diary);
        cout << "0" << endl;
    } else {
        cerr << "-1" << endl;
    }

    return result;
}
