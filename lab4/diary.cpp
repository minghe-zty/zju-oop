#include "diary.h"

void Diary::Reset() {
    date.clear();
    text.clear();
}

void Diary::SetText() {
    cout << "Enter lines of text (type 'END' to finish):" << endl;
    string line;
    text.clear();
    while (getline(cin, line)) {
        if (line == "END") {
            break;
        }
        text.push_back(line);
    }
}

void Diary::SetDate(string new_date) {
    date = new_date;
}

void Diary::AddLine(string line) {
    text.push_back(line);
}

string Diary::readText(VStringSize index) const {  // Marked as const
    if (index < text.size()) {
        return text[index];
    }
    return "";
}

string Diary::readDate() const {  // Marked as const
    return date;
}

VStringSize Diary::Size() const {  // Marked as const
    return text.size();
}

void read_to_memory(string filename, vector<Diary>& my_diary) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    my_diary.clear();
    string line, date;
    while (getline(infile, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }
        if (line[0] == '#') {
            date = line.substr(1);
            Diary diary;
            diary.SetDate(date);
            my_diary.push_back(diary);
        } else {
            if (!my_diary.empty()) {
                my_diary.back().AddLine(line);
            }
        }
    }
    infile.close();
}

void write_to_file(string filename, vector<Diary>& my_diary) {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& diary : my_diary) {
        outfile << "#" << diary.readDate() << endl;
        for (VStringSize i = 0; i < diary.Size(); ++i) {
            outfile << diary.readText(i) << endl;
        }
        outfile << endl; // Add an empty line between entries
    }
    outfile.close();
}

bool date_sort(const Diary& a1, const Diary& a2) {
    return a1.readDate() < a2.readDate();
}
