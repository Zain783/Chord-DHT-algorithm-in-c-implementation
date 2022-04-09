using namespace std;
#include<iostream>
#include<math.h>
struct node{
	string  data;
	//I take time in milli seconds
	long timelimit;
	int id;
	node* next;
	node* prev;
	node* linkfirst;
	node* linksecond;
	node* linkthird;
	node* linkfourth;
};
int global_id=0;


class chord_list{
	
	public:
		node* head;
		node* tail;
		
	chord_list(){
		head=NULL;
		tail=NULL;
	}
	void add(int id_count)
	{
		node* temp=new node();
		cout<<"Enter data to store in node:";
		cin>>temp->data;
		temp->id=id_count;
		temp->linkfirst=NULL;
		temp->linksecond=NULL;
		temp->linkthird=NULL;
		temp->linkfourth=NULL;
		temp->timelimit=1000;
		if(head==NULL){
		head=temp;
		tail=temp;	
		tail->next=head;
		head->prev=tail;	
		}else{
		
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		tail->next=head;
		}
	}
	void displayclockwise(){
		node* itr=head;
		do{
			cout<<"|"<<itr->id<<"|"<<itr->data<<"|->";
			
			itr=itr->next;
		}while(itr!=head);
		
	}
	
	void joinnode(int join_id){
		int pow_limit=0;		
		node* itr=head;
		int x;
		do{
			if(itr->id==join_id){
			while(pow_limit<=3){
				if(pow_limit==0){
					x=pow(2, pow_limit);
					
				}else{
					x=pow(2, pow_limit);
		
				}
				 int joinNodenumber=join_id*x;
				node* itr2=head;
				if(joinNodenumber<=global_id){
						do{
					
					if(itr2->id==joinNodenumber){
						if(pow_limit==0){
						itr->linkfirst=itr2;	
						
						}else if(pow_limit==1){
						itr->linksecond=itr2;	
							
							
						}else if(pow_limit==2){
							itr->linkthird=itr2;
							
							
							
						}else if(pow_limit==3){
							itr->linkfourth=itr2;
						
						}			
					}
				
					itr2=itr2->next;
				}while(itr2!=head);
					
					
				}
				
				pow_limit++;					
				}
				break;		
			}			
			itr=itr->next;
		}while(itr!=head);
		
		
	}
	
	void checklink(){
		int idno;
		cout<<"Enter node id ::";
		cin>>idno;
		node* itr=head;
		do{
			if(idno==itr->id){
				cout<<"Node detail: |"<<itr->data<<"|"<<itr->id<<"|"<<endl;
				if(itr->linkfirst!=NULL){
					cout<<"link first detail:"<<itr->linkfirst<<endl;
					cout<<"link first data:"<<itr->linkfirst->data<<endl;
				}
				 if(itr->linksecond!=NULL){
					cout<<"link second detail:"<<itr->linksecond<<endl;
				   cout<<"link second data:"<<itr->linksecond->data<<endl;
					
					
				}
				if(itr->linkthird!=NULL){
					cout<<"link third detail:"<<itr->linkthird<<endl;
				cout<<"link third data:"<<itr->linkthird->data<<endl;
					
					
				}
				 if(itr->linkfourth!=NULL){
					
				cout<<"link fourth detail:"<<itr->linkfourth<<endl;
				cout<<"link fourth data:"<<itr->linkfourth->data<<endl<<endl;		
				}					
				break;
			}
			
			itr=itr->next;
		}while(itr!=head);
		
		
		
	}};
int main(){
	chord_list c1;
	int choice;
while(true){
cout<<endl;	
cout<<"Enter 1 for insertion()"<<endl;	
cout<<"Enter 2 for displayClockWise()"<<endl;	
cout<<"Enter 3 for search"<<endl;
cout<<"Enter 4 for search"<<endl;
cin>>choice;
switch(choice){
	case 1:
     if(choice==1){	
			int limit,i=0,j=0;;
		cout<<"Enter how many no of nodes you want enter 2^n:";
		cin>>limit;
		while(i<=limit){
		    c1.add(global_id);	
			i++;
			global_id++;
		}		
		while(j<=limit){
		c1.joinnode(j);	
			j++;
		}}		
		break;
	case 2:
		c1.displayclockwise();
		break;		
	case 3:
		c1.checklink();
		break;		
	default:
		goto jump;
		cout<<"wrong choice...";
}	
}	jump:
	c1.displayclockwise();
}



