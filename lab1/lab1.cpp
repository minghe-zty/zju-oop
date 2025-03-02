#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct student {
    std::string name;
    int score1;
    int score2;
    int score3;
    float average;
};//定义student类
int main() {
    int num=10;
    int score1_min=5;
    int score2_min=5;
    int score3_min=5;
    int score1_max=1;
    int score2_max=1;
    int score3_max=1;
    int score1_all=0;
    int score2_all=0;
    int score3_all=0;
    float score1_average;
    float score2_average;
    float score3_average;
    std::cout<<std::left<<std::setw(8)<<"no"<<std::setw(8) << "name" << std::setw(8) << "score1" << std::setw(8) << "score2" << std::setw(8) << "score3" << std::setw(8) << "average" << std::endl;
    student s[10];
	ifstream in1;
	in1.open( "student name.txt" );                   //从文件"student name"读入学生姓名 
	if( !in1 ){
		cout << "学生姓名读入失败" << endl;
	}
	for(int i=0;i<10;i++ ){
		in1>>s[i].name;
	}
	ifstream in2;
	in2.open( "score1.txt" );                         //从文件"score1"读入学生第1门成绩 
	if(!in2)
		cout << "score1读入失败" << endl;
	for(int i=0;i<10;i++){
		in2>>s[i].score1;
	}
	ifstream in3;
	in3.open( "score2.txt" );                         //从文件"score1"读入学生第1门成绩 
	if(!in3)
		cout << "score2读入失败" << endl;
	for(int i=0;i<10;i++){
		in3>>s[i].score2;
	}
	ifstream in4;
	in4.open( "score3.txt" );                         //从文件"score1"读入学生第1门成绩 
	if(!in4)
		cout << "score3读入失败" << endl;
	for(int i=0;i<10;i++){
		in4>>s[i].score3;
	}
    for (int i = 0; i < num; i++) {
        //std::cin >> s[i].name >> s[i].score1 >> s[i].score2 >> s[i].score3;
        s[i].average = (s[i].score1 + s[i].score2 + s[i].score3)/3.0;
		if(s[i].score1<score1_min){
			score1_min=s[i].score1;
		}
		if(s[i].score2<score2_min){
			score2_min=s[i].score2;
		}
		if(s[i].score3<score3_min){
			score3_min=s[i].score3;
		}
		if(s[i].score1>score1_max){
			score1_max=s[i].score1;
		}
		if(s[i].score2>score2_max){
			score2_max=s[i].score2;
		}
		if(s[i].score3>score3_max){
			score3_max=s[i].score3;
		}
		score1_all+=s[i].score1;
		score2_all+=s[i].score2;
		score3_all+=s[i].score3;
        std::cout<<std::left<<std::setw(8)<<i+1<<std::setw(8) << s[i].name << std::setw(8) << s[i].score1 << std::setw(8) << s[i].score2 << std::setw(8) << s[i].score3 << std::setw(8) << s[i].average << std::endl;
    }
    score1_average=score1_all/10.0;
    score2_average=score2_all/10.0;
	score3_average=score3_all/10.0;
    std::cout<<std::left<<std::setw(8)<<" "<<std::setw(8) << "average"<< std::setw(8) << score1_average << std::setw(8) << score2_average << std::setw(8) << score3_average << std::endl;
    std::cout<<std::left<<std::setw(8)<<" "<<std::setw(8) << "min"<< std::setw(8) << score1_min << std::setw(8) << score2_min << std::setw(8) << score3_min << std::endl;
    std::cout<<std::left<<std::setw(8)<<" "<<std::setw(8) << "max"<< std::setw(8) << score1_max << std::setw(8) << score2_max << std::setw(8) << score3_max << std::endl;
	in1.close();
	in2.close();
	in3.close();
	in4.close();
}
/*
测试输入
K.Weng 5 5 5
zy 4 3 2
zu 3 4 5
ks 4 3 4
ll 3 4 3
al 4 2 5
kl 4 2 1
la 4 4 4
nd 2 3 4 
sk 5 4 3 
*/