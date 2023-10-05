#include<iostream>
#include<string.h>
using namespace std;


class node
{
    public:
    int data,coef,expo;
    node *next;
};

class poly
{
    public:
    node *head;
    
    poly()
	{
        head=NULL;
    }
    
    void sorted_create(node *temp);
    void add(poly p1,poly p2);
    void multiply(poly p1,poly p2);
    void display();

};


void poly :: sorted_create(node *temp)                               
{
	node *p;

    if(head==NULL)
	{
        head=temp;
	}
    else
	{
		if(temp->expo > head->expo)
		{
        	temp->next=head;
        	p=head;
        	
            while(p->next!=head)
			{
                p=p->next;
            }
            p->next=temp;
            head=temp;
        }
        
        else
        {
        	if(temp->expo == head->expo)
        	{
        		head->coef+=temp->coef;
			}
			else
			{
				p=head;
				int flag=0;
				
	            while(1)
				{
					if(p->expo == temp->expo)
	            	{
		        		p->coef+=temp->coef;
		        		flag=2;
		        		break;
					}
					
					if((p->expo > temp->expo && p->next->expo < temp->expo) || (p->next==head))
					{
						flag=1;
						break;	
					}
					p=p->next;
	            }
	            
	            if(flag==1)
	            {
	            	temp->next=p->next;
	            	p->next=temp;
				}
	    	}
		}
	}
}


void poly :: add(poly p1,poly p2)
{
	node *t1,*t2,*t3;
	t1=p1.head;
	t2=p2.head;
	
	if(t1==NULL && t2==NULL)
	{
		cout<<"\nSorry!!! Addition not possible";
		return;
		
	}
    
    do
    {
    	t3=new node;
	    t3->coef=t1->coef;
	    t3->expo=t1->expo;
	    t3->next=t3;
	    
	    sorted_create(t3);
	    t1=t1->next;
	    
    } while(t1!=p1.head);
	
	do
    {
    	t3=new node;
	    t3->coef=t2->coef;
	    t3->expo=t2->expo;
	    t3->next=t3;
	    
	    sorted_create(t3);
	    t2=t2->next;
	    
    } while(t2!=p2.head);
	
}


void poly :: multiply(poly p1,poly p2)
{
	node *t1,*t2,*t3;
	t1=p1.head;
	
	if(t1==NULL && t2==NULL)
	{
		cout<<"\nSorry!!! Multiplication is not possible";
		return;
		
	}
	
	do
	{
		
	   t2=p2.head;
	
	   do
	   {
		
		    t3=new node;
		    t3->coef=t1->coef*t2->coef;
		    t3->expo=t1->expo+t2->expo;
		    t3->next=t3;
		    sorted_create(t3);
		
		    t2=t2->next;
		
	   } while(t2!=p2.head);
	 
	t1=t1->next;
	 
    } while(t1!=p1.head);
    
}


void poly :: display()  
{
			                           
    node *p = head;

    while(p->next!=head)
	{
		cout<<p->coef<<"x^"<<p->expo<<"+";
        p=p->next;
    }
    cout<<p->coef<<"x^"<<p->expo;
  
}

int main()
{
	int start=1,choice;
	string city1,city2;
	
    poly p1,p2,p3,p4,p5,p6,p7;
    
    cout<<"\n--------------Welcome to Disease information System--------------\n";
    
    node *t;
	cout<<"\nEnter City name: ";
	cin>>city1;
	cout<<"Enter disease infection rate for month of june: ";
	
	
	char ch;
	do
	{
		t=new node;
		int val;
		cout<<"\nEnter coefficient = ";
		cin>>t->coef;
		cout<<"Enter exponent = ";
		cin>>t->expo;
		t->next=t;
		
		p1.sorted_create(t);
		
        cout<<"Would you like to add more data (y/n) : ";
        cin>>ch;

	} while(ch == 'y');
	


    cout<<"\nEnter City name: ";
	cin>>city2;
	cout<<"Enter disease infection rate for month of june: ";
	
	
	do
	{
		t=new node;
		int val;
		cout<<"\nEnter coefficient = ";
		cin>>t->coef;
		cout<<"Enter exponent = ";
		cin>>t->expo;
		t->next=t;
		
		p2.sorted_create(t);
		
        cout<<"Would you like to add more data (y/n) : ";
        cin>>ch;

	} while(ch == 'y');
	
	cout<<"\nEnter mutation A of disease for the city "<<city1;
	
	do
	{
		t=new node;
		int val;
		cout<<"\nEnter coefficient = ";
		cin>>t->coef;
		cout<<"Enter exponent = ";
		cin>>t->expo;
		t->next=t;
		
		p3.sorted_create(t);
		
        cout<<"Would you like to add more data (y/n) : ";
        cin>>ch;

	} while(ch == 'y');
	
	
	cout<<"\nEnter mutation A of disease for the city "<<city2;
	
	do
	{
		t=new node;
		int val;
		cout<<"\nEnter coefficient = ";
		cin>>t->coef;
		cout<<"Enter exponent = ";
		cin>>t->expo;
		t->next=t;
		
		p4.sorted_create(t);
		
        cout<<"Would you like to add more data (y/n) : ";
        cin>>ch;

	} while(ch == 'y');
	
	
	
	cout<<"\n-------------------------------------------------------------------------";
	
	cout<<"\n\nCity name\tDisease infection rate for month of june\tMutation A\n\n";
	cout<<city1<<"\t\t\t";
	p1.display();
	cout<<"\t\t\t\t";
	p3.display();
    cout<<"\n"<<city2<<"\t\t\t";
	p2.display();
	cout<<"\t\t\t";
	p4.display();
	
	cout<<"\n\n-------------------------------------------------------------------------";
	
	while(start==1)
	{
		cout<<"\n\n1)Total disease rate for month june for both cities (addition)\n2)Total disease growth for city "<<city1<<" in case mutation A occurred (multiplication)\n3)Total disease growth for city "<<city2<<" in case mutation A occurred (multiplication)";
		
		cout<<"\n\nEnter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				p5.add(p1,p2);
				cout<<"\nResult is as follows: ";
				p5.display();
				break;
			
			case 2:
				p6.multiply(p1,p3);
				cout<<"\nResult is as follows: ";
				p6.display();
				break;
			
			case 3:
				p7.multiply(p2,p4);
				cout<<"\nResult is as follows: ";
				p7.display();
				break;
			
			default:
				cout<<"\nInvalid choice !!!";
		}
		
		cout<<"\n\nEnter 1 to continue otherwise enter 2: ";
		cin>>start;
	}
	
    cout<<"\nStay Safe\tStay Healthy\n\n\tThankyou!!!";
	
	return 0;
}
