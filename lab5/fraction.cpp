#include<iostream>
#include<cstdio>
#include<sstream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include"fraction.h"
using namespace std;



Fraction::~Fraction() {}
//This function computes the greatest common divisor (GCD) of two integers using the Euclidean algorithm. It is used to simplify fractions to their lowest terms. Here, it iteratively replaces the larger number by its remainder when divided by the smaller number until one of the numbers becomes zero. The last non-zero remainder is the GCD.
int Fraction::gcd(int a, int b) {
    if (b == 0) return 1;
    int c=a%b;
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
//This function converts a decimal string input by the user into a fraction. It first extracts the integer and fractional parts of the decimal, converts them into a numerator and a denominator, and then simplifies the fraction using the gcd function. It handles the input string directly and assumes the decimal is in a correct format.
void Fraction::double_to_fraction(){
    string a;
    cout<<"Enter the decimal number,you must input like 0.0:";
    cin>>a;
    int m,n;
    m=0;
    n=1;
    int i;
    for(i=0;;i++){
        if(a[i]!='.'){
            m=m*10+(a[i]-'0');
        }
        else break;
    }
    i++;
    while(a[i]>='0'&&a[i]<='9'){
        m=m*10+(a[i]-'0');
        n*=10;
        i++;
    }
    if(m==0){
        cout<<"0"<<endl;
        return;
    }
    int gcd_mn=gcd(m,n);
    m=m/gcd_mn;
    n=n/gcd_mn;
    Fraction f(m,n);
    cout<<f.num<<"/"<<f.deno<<endl;

}
//Converts a user-input fraction (expressed as "numerator/denominator") into a decimal. It prompts the user to enter the fraction, checks for a zero denominator to prevent division errors, and then performs the division to convert the fraction to a floating-point number (double).
void Fraction::fraction_to_decimal(){
    double ans;
    cout<<"Enter the fraction number:";
    int m,n;
    scanf("%d/%d",&m,&n);
    if(n==0) cout<<"Error! Denominator cannot be zero!"<<endl;
    else{
        ans=(double)m/n;
        cout<<ans<<endl;
    }
    
}
//Prompts the user to input two fractions and adds them. If the denominators are the same, it simply adds the numerators. If the denominators differ, it finds a common denominator by multiplying the two denominators and adjusts the numerators accordingly before adding. The result is then simplified using the gcd function.
void Fraction::add_two_fractions(){
    int m1,n1,m2,n2,m3,n3;
    cout<<"Enter the first fraction number:";
    scanf("%d/%d",&m1,&n1);
    cout<<"Enter the second fraction number:";
    scanf("%d/%d",&m2,&n2);
    if(n1==0||n2==0){
        cout<<"Error! Denominator cannot be zero!"<<endl;
        return;
    }
    if(n1==n2){
        m3=m1+m2;
        n3=n1;
    }
    else{
        m3=(m1*n2+m2*n1);
        n3=n1*n2;
    }
    int gcd_mn=gcd(m3,n3);
    m3=m3/gcd_mn;
    n3=n3/gcd_mn;
    Fraction f(m3,n3);
    cout<<f.num<<"/"<<f.deno<<endl;
}
//Works similarly to add_two_fractions but subtracts the second fraction from the first. If the resulting numerator is negative, it prints the result with a negative sign. The fraction is also simplified using gcd
void Fraction::subtract_two_fractions(){
    int m1,n1,m2,n2,m3,n3;
    int flag=1;
    cout<<"Enter the first fraction number:";
    scanf("%d/%d",&m1,&n1);
    cout<<"Enter the second fraction number:";
    scanf("%d/%d",&m2,&n2);
    if(n1==0||n2==0){
        cout<<"Error! Denominator cannot be zero!"<<endl;
        return;
    }
    if(n1==n2){
        m3=m1-m2;
        n3=n1;
    }
    else{
        m3=(m1*n2-m2*n1);
        n3=n1*n2;
    }
    if(m3<0){
        flag=0;
        m3=-m3;
    }
    if(m3==0){
        cout<<"0"<<endl;
        return;
    }else{
        int gcd_mn=gcd(m3,n3);
        m3=m3/gcd_mn;
        n3=n3/gcd_mn;
        Fraction f(m3,n3);
        if(flag==0){
            cout<<"-";
        }
        cout<<f.num<<"/"<<f.deno<<endl;
    }
}
//Multiplies two user-input fractions. It multiplies the numerators together and the denominators together, then simplifies the resulting fraction using the gcd function.
void Fraction::multiply_two_fractions(){
    int m1,n1,m2,n2,m3,n3;
    cout<<"Enter the first fraction number:";
    scanf("%d/%d",&m1,&n1);
    cout<<"Enter the second fraction number:";
    scanf("%d/%d",&m2,&n2);
    if(n1==0||n2==0||m2==0){
        cout<<"Error! Denominator cannot be zero!"<<endl;
        return;
    }
    m3=m1*m2;
    n3=n1*n2;
    int gcd_mn=gcd(m3,n3);
    m3=m3/gcd_mn;
    n3=n3/gcd_mn;
    if(m3==0){
        cout<<"0"<<endl;
        return;
    }else{
        Fraction f(m3,n3);
        cout<<f.num<<"/"<<f.deno<<endl;
    }
 
}
//Divides the first user-input fraction by the second. It multiplies the numerator of the first by the denominator of the second and the denominator of the first by the numerator of the second (essentially multiplying by the reciprocal of the second fraction), and then simplifies the result using gcd
void Fraction::divide_two_fractions(){
    int m1,n1,m2,n2,m3,n3;
    cout<<"Enter the first fraction number:";
    scanf("%d/%d",&m1,&n1);
    cout<<"Enter the second fraction number:";
    scanf("%d/%d",&m2,&n2);
    if(n1==0||n2==0||m2==0){
        cout<<"Error! Denominator cannot be zero!"<<endl;
        return;
    }
    m3=m1*n2;
    n3=n1*m2;
    int gcd_mn=gcd(m3,n3);
    m3=m3/gcd_mn;
    n3=n3/gcd_mn;
    if(m3==0){
        cout<<"0"<<endl;
        return;
    }else{
        Fraction f(m3,n3);
        cout<<f.num<<"/"<<f.deno<<endl;
    }
}
//Compares two fractions entered by the user. It cross-multiplies to compare them without converting to decimals, which preserves accuracy. Depending on the comparison of these cross products, it prints whether the first fraction is greater than, less than, or equal to the second fraction. The code for inequalities seems to contain some errors or redundant outputs (like "!=", ">=", "<=" which appear to be mixed up or misplaced).
void Fraction::compare_two_fractions(){
    int m1,n1,m2,n2,m3,n3;
    cout<<"Enter the first fraction number:";
    scanf("%d/%d",&m1,&n1);
    cout<<"Enter the second fraction number:";
    scanf("%d/%d",&m2,&n2);
    if(n1==0||n2==0){
        cout<<"Error! Denominator cannot be zero!"<<endl;
        return;
    }
    m3=m1*n2;
    n3=n1*m2;
    if(m3!=n3){
        if(m3>n3){
            cout<<m1<<'/'<<n1<<">"<<m2<<'/'<<n2<<endl;
            cout<<m1<<'/'<<n1<<">"<<"="<<m2<<'/'<<n2<<endl;
            cout<<m1<<'/'<<n1<<"!"<<"="<<m2<<'/'<<n2<<endl;
        }
        else if(m3<n3){
            cout<<m1<<'/'<<n1<<"<"<<m2<<'/'<<n2<<endl;
            cout<<m1<<'/'<<n1<<"<"<<"="<<m2<<'/'<<n2<<endl;
            cout<<m1<<'/'<<n1<<"!"<<"="<<m2<<'/'<<n2<<endl;
        }
    }else{
        cout<<m1<<'/'<<n1<<">"<<"="<<m2<<'/'<<n2<<endl;
        cout<<m1<<'/'<<n1<<"="<<"="<<m2<<'/'<<n2<<endl;
        cout<<m1<<'/'<<n1<<"<"<<"="<<m2<<'/'<<n2<<endl;
    }
}

