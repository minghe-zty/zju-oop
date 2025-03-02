#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include <numeric> 
#include <limits>
using namespace std;
class Student {
public:
    string name;
    map<string, int> courseScores;
    float average;
    Student() : average() {}
    void calculateAverage() {
        if (courseScores.empty()) {
            average = 0.0;
            return;
        }
        int totalScore = 0;
        for (const auto& score : courseScores) {
            totalScore += score.second;
        }
        average = static_cast<float>(totalScore) / courseScores.size();
    }
};//定义student类，包括姓名，成绩，平均分，用map存储

vector<Student> allStudents;
vector<string> courseTitles;
map<string, vector<int>> courseStats; // 存储每门课的成绩，用于计算最高分、最低分和平均分

void readData(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        Student student;
        ss >> student.name;

        string courseName;
        int score;
        while (ss >> courseName >> score) {
            student.courseScores[courseName] = score;
            courseStats[courseName].push_back(score); // 添加成绩到相应课程的统计信息中
            if (find(courseTitles.begin(), courseTitles.end(), courseName) == courseTitles.end()) {
                courseTitles.push_back(courseName);
            }
        }

        student.calculateAverage();
        allStudents.push_back(student);
    }
    infile.close();
}

void printHeader() {
    cout << left << setw(8) << "no" << setw(8) << "name";
    for (const auto& title : courseTitles) {
        cout << setw(8) << title;
    }
    cout << setw(8) << "average" << endl;
}

void printStudents() {
    int studentNo = 1;
    for (const auto& student : allStudents) {
        cout << left << setw(8) << studentNo++ << setw(8) << student.name;
        for (const auto& title : courseTitles) {
            if (student.courseScores.find(title) != student.courseScores.end()) {
                cout << setw(8) << student.courseScores.at(title);
            } else {
                cout << setw(8) << " ";
            }
        }
        cout << setw(8) << fixed << setprecision(2) << student.average << endl;
    }
}

void printCourseStats() {
    // print max , min , average
    cout << left << setw(8) << " ";
	cout << left << setw(8) << "max";
    for (const auto& course : courseTitles) {
        auto& scores = courseStats[course];
        int maxScore = *max_element(scores.begin(), scores.end());
        cout << setw(8) << maxScore;
    }
    cout << endl;

    cout << left << setw(8) <<" ";
    cout << left << setw(8) << "min";
    for (const auto& course : courseTitles) {
        auto& scores = courseStats[course];
        int minScore = *min_element(scores.begin(), scores.end());
        cout << setw(8) << minScore;
    }
    cout << endl;

    cout << left << setw(8) <<" ";
    cout << left << setw(8) << "average";
    for (const auto& course : courseTitles) {
        auto& scores = courseStats[course];
        int sum = accumulate(scores.begin(), scores.end(), 0);
        float average = static_cast<float>(sum) / scores.size();
        cout << setw(8) << fixed << setprecision(2) << average;
    }
    cout << endl;
}

int main() {
    readData("input.txt");
    sort(courseTitles.begin(), courseTitles.end());
    printHeader();
    printStudents();
    printCourseStats(); // 在最后打印课程统计信息
    return 0;
}
