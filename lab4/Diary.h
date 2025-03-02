#pragma once
#ifndef DIARY_H
#define DIARY_H
#include <SDKDDKVer.h>

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<string>::size_type VStringSize;
class Diary {
private:
    string date;
    vector<string> text;
public:
    void Reset();
    void SetText();
    void SetDate(string);
    void AddLine(string);
    string readText(VStringSize) const;  // Marked as const
    string readDate() const;             // Marked as const
    VStringSize Size() const;            // Marked as const
};

void read_to_memory(string filename, vector<Diary>& my_diary);
void write_to_file(string filename, vector<Diary>& my_diary);
bool date_sort(const Diary &a1, const Diary &a2);
#endif // !DIARY_H