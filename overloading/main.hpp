#include<iostream>

//C++ allows us to 'overload' the same function name as long as
//the variable types in the function inputs are different.

class Compare
{
public:
    int findSmaller(int input1, int input2);
    float findSmaller(float input1, float input2);
    char findSmaller(char input1, char input2);
    int findSmaller(int input1, int input2, int inpu3);
    float findSmaller(float input1, float input2, float input3);
    char findSmaller(char input1, char input2, char input3);
    int findSmaller(int arrayInt[], int size);
    float findSmaller(float arrayInF[], int size);
    char findSmaller(char arrayInC[], int size);
};

int Compare::findSmaller(int input1, int input2)
{
    if(input1<input2)
        return input1;
    return input2;
}
float Compare::findSmaller(float input1, float input2)
{
    if(input1<input2)
        return input1;
    return input2;
}

char Compare::findSmaller(char input1, char input2)
{
    if(input1<input2)
        return input1;
    return input2;
}
int Compare::findSmaller(int input1, int input2, int input3)
{
    int sm1 = findSmaller(input1, input2);
    int sm2 = findSmaller(input2, input3);
    if(sm1 < sm2)
        return sm1;
    return sm2;
}

float Compare::findSmaller(float input1, float input2, float input3)
{
    float sm1 = findSmaller(input1, input2);
    float sm2 = findSmaller(input2, input3);
    if(sm1 < sm2)
        return sm1;
    return sm2;
}

char Compare::findSmaller(char input1, char input2, char input3)
{
    char sm1 = findSmaller(input1, input2);
    char sm2 = findSmaller(input2, input3);
    if(sm1 < sm2)
        return sm1;
    return sm2;
}

int Compare::findSmaller(int arrayInt[], int size)
{
    int res = arrayInt[0];
    for(int i = 1; i < size; i ++){
        res = findSmaller(res, arrayInt[i]);
    }
    return res;
}
float Compare::findSmaller(float arrayInF[], int size)
{
    float res = arrayInF[0];
    for(int i = 1; i < size; i ++){
        res = findSmaller(res, arrayInF[i]);
    }
    return res;
}

char Compare::findSmaller(char arrayInC[], int size)
{
    char res = arrayInC[0];
    for(int i = 1; i < size; i ++){
        res = findSmaller(res, arrayInC[i]);
    }
    return res;
}
