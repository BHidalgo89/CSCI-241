#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "BookStore.h"
using namespace std;
using std::cout;
using std::endl;


   int main()
	{
        BookStore bookOrders("bookdata");
	bookOrders.print();
	bookOrders.processOrders("orders.txt");
	bookOrders.print();
	return 0;
	}
