/*Header file for main.cpp
**Create a class called Cat.
**Create the following members:
**private members: name, breed, age
**public members: setName, setBreed,setAge
**getName, getBreed, getAge, printInfo*/
#include <iostream>
// #include <string>

using namespace std;

class Cat
{
public:
    void setName(string nameIn);
    void setBreed(string breedIn);
    void setAge(int ageIn);
    string getName();
    string getBreed();
    int getAge();
    void printInfo();
private:
    string name;
    string breed;
    int age;
};

void Cat::setName(string nameIn)
{
    name = nameIn;
}

void Cat::setBreed(string breedIn)
{
    breed = breedIn;
}

void Cat::setAge(int ageIn)
{
    age = ageIn;
}

string Cat::getName()
{
    return name;
}

string Cat::getBreed()
{
    return breed;
}

int Cat::getAge()
{
    return age;
}

void Cat::printInfo(){
    cout << name << " " << breed << " " << age;
}
