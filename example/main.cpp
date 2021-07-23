#include <iostream>
#include "../property.hpp"

class mainClass{
public:
	int test = 0;
	property<int> myInt = {//inside a class
		([&]() -> int {
		 std::cout<<"getter in function"<<std::endl;
		 test++;//normal lambda captures apply, allowing you to access class members
		 return(test);
		 }),
		([&](const int& i){
		 std::cout<<"setter in function set to "<<i<<std::endl;
		 })
	};
	void run(){
		std::cout<<"Hello world"<<std::endl;
		myInt = 5;
		for(int i=0;i<5;i++){
			std::cout<<"myInt = "<<myInt<<std::endl;
		}
	}
};

int main(){
	mainClass* m = new mainClass();
	m->run();

	//doesn't have to be inside a function
	property<int> myInt = {//inside a function
		([&]() -> int {
		 std::cout<<"getter in main"<<std::endl;
		 return(0);
		 }),
		([&](const int& i){//can be i or some other variable name.  this is just a lambda
		 std::cout<<"setter in main"<<std::endl;
		 })
	};
	return(myInt);
}
