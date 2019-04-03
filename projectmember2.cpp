#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctype.h>
using namespace std;

	class Book
	{
                public : 

	char *author, *publisher, *title;
	char *stockposition;
	int price;
			      	
			
			void set_id(char *a)
			{ 
				author = a; 
			}
			char *get_id()
			{ 
				return author; 
			}
			void set_name(char *b)
			{ 
				title = b; 
			}
			char *get_name()
			{ 
				return title; 
			}
			void set_condition(char *c)
			{ 
				publisher = c; 
			}
			char *get_condition()
			{ 
				return publisher; 
			}
			void set_category(int d)
			{ 
				price = d; 
			}
			int get_category()
			{ 
				return price; 
			}
			void set_company(char *e)
			{ 
				stockposition = e; 
			}
			char *get_company()
			{ 
				return stockposition; 
			}
				};
int main()
{  
	int i,j,f,l;
	char r[10],w[10],u[10],ja[10],da[10],ma[10];
	char t[10],*m;
	char *o,*n;
	Book obj[25];
	
	for(i=0;i<1;i++)
	{
		cout<<"Enter author's name ";
		cin>>r;
		/*for(j=0;j<=sizeof(r);j++)
		{
			if((r[j]>=65 && r[j]<=90) || (r[j]>=97 && r[j]<=122))
			{
			}
			else
			{
				cout<<"Enter valid name"<<endl;
				return 0;
			}
		}*/
		obj[i].set_id(r);
	
		cout<<"Enter title of the book ";
		cin>>u;
		/*for(j=0;j<=sizeof(u);j++)
		{
			if((u[j]>=48 && u[j]<=57) || (u[j]>=65 && u[j]<=90) || (u[j]>=97 && u[j]<=122))
			{
			}
			else
			{
				cout<<endl<<"Enter valid name"<<endl<<endl;
				return 0;
			}
		}*/
		obj[i].set_name(u);
	
		cout<<"enter publisher's name ";
		cin>>w;
		/*for(j=0;j<=sizeof(w);j++)
		{if(((w[j]>=48 && w[j]<=57) || (w[j]>=65 && w[j]<=90) || (w[j]>=97 && w[j]<=122)))
		{
		}
		else
		{
			cout<<"Enter valid name"<<endl<<endl;
			return 0;
		}*/
		obj[i].set_condition(w);
	
		cout<<"Enter price";
		cin>>f;
		/*if(f[j]>=48 && f[j]<=57)
		{
		}
		else
		{
			cout<<"Enter valid price "<<endl<<endl;
			return 0;
		}*/
		obj[i].set_category(f);
		cout<<"Enter stock position (4-digits)";
		cin>>t;
		for(j=0;j<=3;j++)
		{
			if(t[j]>=48 && t[j]<=57)
			{
			}
			else
			{
		cout<<endl<<"Enter valid stock position"<<endl<<endl;
				return 0;
			}
		}
		obj[i].set_company(t);
		
	ofstream ob("Project.txt",ios::out|ios::binary);
	ob<<endl<<"Details"<<endl<<endl;
		for(i=0;i<1;i++)
		{
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Author Name is "<<std::internal<<obj[i].get_id();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Title Name is "<<std::internal<<obj[i].get_name();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Publisher Name is "<<std::internal<<obj[i].get_condition();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Price is "<<std::internal<<obj[i].get_category();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Stock Position is "<<std::internal<<obj[i].get_company();
		}
		cout<<"enter letter S to find books accordingly";
		cin>>da;
		ob<<endl<<endl<<endl<<endl<<"Books are ";

		for(i=0;i<1;i++)
		{	n = obj[i].get_name();
			if(strcmp(n,"S"))
			{
			ob.width(60); ob.fill('-'); ob<<endl<<endl<<std::left<<"Author Name is "<<std::internal<<obj[i].get_id();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Title Name is "<<std::internal<<obj[i].get_name();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Publisher Name is "<<std::internal<<obj[i].get_condition();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Price is "<<std::internal<<obj[i].get_category();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Stock Position is "<<std::internal<<obj[i].get_company();
			
			}
			else
			{
				ob<<endl<<endl<<"No books found";
			}
		}

		   
	cout<<endl<<endl<<"enter publisher's name";
	cin>>ja;  
		ob<<endl<<endl<<endl<<"Publisher's Name ";
				
		for(i=0;i<1;i++)
		{
			o = obj[i].get_condition();
			if(strcmp(ja,o)==0)
			{ob.width(60);ob.fill('-');ob<<endl<<endl<<std::left<<"Author Name is "<<std::internal<<obj[i].get_id();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Title Name is "<<std::internal<<obj[i].get_name();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Publisher Name is "<<std::internal<<obj[i].get_condition();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Price is "<<std::internal<<obj[i].get_category();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Stock Position is "<<std::internal<<obj[i].get_company();
			
				}
			else
			{
				ob<<endl<<endl<<"No books found";
			}
		}
		   
	cout<<"enter price";
	cin>>ma;
		ob<<endl<<endl<<endl<<"Prices are ";		
		for(i=0;i<1;i++)
		{
			l = obj[i].get_category();
			if(l>=100 && l<=500)
			{
			ob.width(60);ob.fill('-');ob<<endl<<endl<<std::left<<"Author Name is "<<std::internal<<obj[i].get_id();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Title Name is "<<std::internal<<obj[i].get_name();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Publisher Name is "<<std::internal<<obj[i].get_condition();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Price is "<<std::internal<<obj[i].get_category();
			ob.width(60); ob.fill('-'); ob<<endl<<std::left<<"Stock Position is "<<std::internal<<obj[i].get_company();
			
			}
			else
			{
				ob<<endl<<endl<<"books not found "<<endl<<endl;
			}
		}
	char ch;
	ob.close();
	ifstream ob2("Project.txt",ios::in|ios::binary);
	ob2.seekg(1,ios::beg);
	while (ob2.get(ch))
	{
		cout<<ch;
	}
	return 0;
}
}
	
