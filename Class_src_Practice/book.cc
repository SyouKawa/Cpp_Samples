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
		Book(const char *BookName,float fprice);
		~Book();
		void print();
		void setName(const char *BookName);
		void setPrice(float fprice);
	private:
		char *_BookName;
		float _fprice;
};

Book::Book(const char *BookName,float fprice)
: _BookName(new (std::nothrow) char[strlen(BookName)+1]())
,_fprice(fprice)
{
	strcpy(_BookName,BookName);
}

Book::~Book(){
	delete [] _BookName;
	cout<<"~Book()"<<endl;
}

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
	Book Duma_Key("Duma_Key",39.50);
//	Duma_Key.setName("Duma_Key");
//	Duma_Key.setPrice(39.50);
	Duma_Key.print();

	return 0;
}
