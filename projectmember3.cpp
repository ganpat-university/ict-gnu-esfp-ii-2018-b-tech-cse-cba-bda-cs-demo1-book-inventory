#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<ctype.h>
#include<cstdlib>
#define MAX_BOOKS 50
using namespace std;
class Book{
 friend class BookShop;
   string author;
   string title;
   string publisher;
   string letter;
   string character;
   int stockPosition;
   float price;
 public:
   Book(){
     author = "";
     title = "";
     publisher = "";
     stockPosition = 0;
     price = 0;
   }

   float getPrice(int numOrder){
     return price * numOrder;
   }
   bool isAvailable(int numOrder){
     return numOrder <= stockPosition;
   }

   void printDetails(){
     cout << endl << "--- Book details ---";
     cout << endl << "Title: " << title;
     cout << endl << "Author: " << author;
     cout << endl << "Publisher: " << publisher;
     cout << endl << "StockPosition: " << stockPosition;
     cout << endl << "Price: Rs." << price;
   }
   void get(){
     cout << endl << "Enter new book details: ";
     cout << endl << "Title: ";
     cin >> title;
     cout << endl << "Author: ";
     cin >> author;
     cout << endl << "Publisher: ";
     cin >> publisher;
     cout << endl << "Price: ";
     cin >> price;
     cout << endl << "Stock Position: ";
     cin >> stockPosition;
   }
	

   void placeOrder(){
     int numOrder;
     cout << endl << "Enter number of copies: ";
     cin >> numOrder;
     if(isAvailable(numOrder)){
       cout << endl << "Required copies are available in stock. Total price: Rs." << getPrice(numOrder);
     }else{
       cout << endl << "Required copies not in stock.";
     }
   }
};
 


class BookShop{
   Book * books[MAX_BOOKS];
   int index;
 public:
   BookShop(){
     index = 0;
   }
   void add(){
     books[index] = new Book();
     books[index]->get();
     index++;
   }
   void request(){
     int choice = 0, search = -1;
     cout << endl << "Search for book by: ";
     cout << endl << "1) Search a book by Title";
     cout << endl << "2) Search a book by Author name";
	 cout << endl << "3) Display all the books along with their author, title, price and publisher sorted according to price lowest to 					highest";
	cout << endl << "4)  Display all the books whose copies are not available in the stock";
	cout << endl << "5) Search a book by letters";
	cout << endl << "6) Search a book by its publisher";
	cout<< endl << "7) Display all the books whose price is between 100 to 500.";
	cout << endl << "8) Display all the books whose title is between 10-20 characters";
	cout << endl << "9)  Display all the books which are currently not available in the stock.";	
     cout << endl << "Enter choice: ";
     cin >> choice;
     switch(choice){
       case 1 : search = searchTitle(); break;
       case 2 : search = searchAuthor(); break;
	case 5 : search = searchname(); break;
	case 6 : search = searchpublisher(); break;
	case 7: search = searchprice(); break;
	case 8: search = searchcharacters(); break;
	case 9: search = searchstock(); break;
       default: cout << endl << "Invalid choice!"; break;
     }
     if(search == -1){
       cout << endl << "No results found!";
     }else{
       cout << endl << "Book found: ";
       books[search]->printDetails();
       books[search]->placeOrder();
     }
   }
   int searchTitle(){
     string title;
     cout << endl << "Enter book title to search: ";
     cin >> title;
     for(int i = 0; i < index; i++){
       if(title.compare(books[i]->title) == 0){
         return i;
       }
     }
     return -1;
   }
   int searchAuthor(){
     string author;
     cout << endl << "Enter author name to search: ";
     cin >> author;
     for(int i = 0; i < index; i++){
       if(author.compare(books[i]->author) == 0){
         return i;
       }
     }
     return -1;
   }
	int searchname(){
	string letter;
	cout<<endl<<"enter letter to search by";
	cin>>letter;
	for(int i=0;i<index;i++){
	if(letter.find(books[i]->letter)==0)
	{
	return i;
	}
	}
	return -1;
	}
	int searchpublisher(){
	string publisher;
	cout << endl << "Enter publisher's name";
	cin>>publisher;
	for(int i=0;i<index;i++){
	if(publisher.compare(books[i]->publisher) == 0){
	return i;
	}	
	}
	return -1;
	}
	int searchprice(){
	float price;
	for(int i=0;i<index;i++){
	if(price > 100 && price < 500){return i;}
}
return -1;
}
int searchcharacters()
{string character;
	cout<<endl<<"enter a title with 10-20 characters";
	cin>>character;
	for(int i=0;i<index;i++){
	if(character.compare(books[i]->character)>=10 && character.compare(books[i]->character)<=20){return i;}
}
return -1; 
}
int searchstock()
{int stock;
cout<<endl<<"enter 0 to see unavailable books";
cin>>stock;
for(int i=0;i<index;i++){
	if(stock==0)
	{
	return i;
	}
	}
	return -1;
	}
fstream fp;
 Book ob;

int write()
{
	fp.open("BOOKS.txt",ios::out|ios::in);
	ob.get();
	fp.write((char*)&ob,sizeof(Book));
	fp.close();
}	
int display()
{
char data[100];
char filename[40];
cout<<"Enter Filename";
cin>>filename;
ifstream is;
is.open(filename);
while(is.eof()==0)
{
is.getline(data,100);
cout<<"data"<<endl;
}
is.close();
}
int scrapo()
{
int k=0;
    string line;
    string find;
 string author;
   string title;
   string publisher;
   string letter;
   int stockPosition;
   float price;
    ofstream myfile;
    myfile.open("BOOKS.txt");

    while(k!=3){

        cout<<"press 1 for adding data"<<endl;
        cout<<"press 2 for update "<<endl;

        cin>>k;

        if(k==1)
        { 
            
		cout << endl << "Enter new book details: ";
     cout << endl << "Title: ";
     cin >> title;
     cout << endl << "Author: ";
     cin >> author;
     cout << endl << "Publisher: ";
     cin >> publisher;
     cout << endl << "Price: ";
     cin >> price;
     cout << endl << "Stock Position: ";
     cin >> stockPosition;

            myfile<<title<<endl;
            myfile<<author<<endl;
            myfile<<publisher<<endl;
		myfile<<price<<endl;
		myfile<<stockPosition<<endl;
        }

        if(k==2)
        {

            cout<<"name u want to update "<<endl;
            cin>>find; 
            ifstream file;

            file.open("BOOKS.txt");
            while (!file.eof() && line!=find)
            {

                getline(file,line);
            }
		cout << endl << "Title: ";
     cin >> title;
     cout << endl << "Author: ";
     cin >> author;
     cout << endl << "Publisher: ";
     cin >> publisher;
     cout << endl << "Price: ";
     cin >> price;
     cout << endl << "Stock Position: ";
     cin >> stockPosition;

            myfile<<title<<endl;
            myfile<<author<<endl;
            myfile<<publisher<<endl;
		myfile<<price<<endl;
		myfile<<stockPosition<<endl;
            
        }
        if(k==3){
            myfile.close();
        }
    }
    return 0;
}
};


int main(){
 int choice;
 BookShop * bs = new BookShop();
 do{
   cout << endl << "-- Book Shop --";
   cout << endl << "1. Add book";
   cout << endl << "2. Request book";
   cout << endl << "3. Add in a file";
   cout << endl << "4. details in a file";
   cout << endl << "5. Delete a record";   
cout << endl << "6. Exit";
   cout << endl << "Your choice: ";
   cin >> choice;
   switch(choice){
     case 1 : bs->add(); break;
     case 2 : bs->request(); break;
	case 3 : bs->write();break;
	case 4 : bs->display();break;
	case 5 : bs->scrapo();break;
   }
 }while(choice != 6);
 delete bs;
 return 0;
}
