#include<iostream>
#include<string>

int main()
{
	std::string userName;
	std::cout<<"tell me your name\n";
	getline(std::cin, userName);
	std::cout<<"hello "<<userName<<"\n";
	return 0;
}
