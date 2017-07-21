 ///
 /// @file    book.cc
 /// @author  Cyclohexane(orekiyuki2me@gmail.com)
 /// @date    2017-07-21 06:09:59
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Book{
	public:
		void print();
		void setName(const char *BookName);
		void setPrice(float fprice);
	private:
		char _BookName[20];
		float _fprice;
};

void Book::print(){
	cout<<"[BookName]:"<<_BookName<<endl;
	cout<<"[Price]:"<<_fprice<<endl;
}

void Book::setName(const char *BookName){
	strcpy(_BookName,BookName);
}

void Book::setPrice(float fprice){
	_fprice=fprice;
}

int main(){
	Book Duma_Key;
	Duma_Key.setName("Duma_Key");
	Duma_Key.setPrice(39.50);
	Duma_Key.print();

	return 0;
}
