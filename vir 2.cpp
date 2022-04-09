using namespace std;
#include<iostream>
#include<math.h>
struct node{
	string  data;
	//I take time in milli seconds
	long timelimit;
	int id;
	bool isvirtural;
	int virtual_id;
	node* next;
	node* prev;
	node* linkfirst;
	node* linksecond;
	node* linkthird;
	node* linkfourth;
};
int global_id=0,virtual_id=0;


class chord_list{
	
	public:
		node* head;
		node* tail;
		
	chord_list(){
		head=NULL;
		tail=NULL;
	}
	void add()
	{
		string  temp_data,temp_data_v;
		node* new_node=new node();
		node* virtaul_node=new node();
		cout<<"Enter data to store in node:";
		cin>>temp_data;
		cout<<"Enter data to store in virtaul node node:";
		cin>>temp_data_v;
		new_node->data=temp_data;
		new_node->id=global_id++;
		new_node->timelimit=1000;
		new_node->isvirtural=false;
		new_node->virtual_id=virtual_id;
		virtaul_node->data=temp_data_v;
		virtaul_node->id=global_id++;
		virtaul_node->timelimit=1000;
		virtaul_node->isvirtural=true;
		virtaul_node->virtual_id=virtual_id;
		virtual_id++;
		
		if(head==NULL){
		head=new_node;
		tail=new_node;	
		tail->next=virtaul_node;
		virtaul_node->prev=tail;
		tail=virtaul_node;
		tail->next=head;
		head->prev=tail;
		}else{
		tail->next=new_node;
		new_node->prev=tail;
		tail=new_node;
		tail->next=virtaul_node;
		virtaul_node->prev=tail;
		tail=virtaul_node;
		tail->next=head;
		head->prev=tail;
		}
	}
		void displayclockwise(){
		node* itr=head;
		int count=0;
		string s1="node";
		string s212="virtual node";
		do{
			if(count%2==0){
				cout<<"|"<<s1<<" :|"<<itr->id<<"|"<<itr->data<<"|-";
			}else
			 if(count%2==1){
			cout<<"|"<<s212<<" :|"<<itr->id<<"|"<<itr->data<<"|->";	
			}
			
			count++;
			itr=itr->next;
		}while(itr!=head);
		
	    }

	void joinnode(int join_id){
		int pow_limit=0;		
		node* itr=head;
		int x;
		if(join_id%2==1){
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
	}
	
	void searchNode(){
		node* itr=head;
		int time_counter=0;
		int id_search;
		cout<<"Enter node to search :";
		cin>>id_search;
        bool flag=true;
		do{
			if(itr->virtual_id==itr->next->virtual_id){
//			time_counter=time_counter+itr->timelimit/2;	
			}else{
				
				time_counter=time_counter+itr->timelimit;	
			}
			
			if(itr->id==id_search){
				
				cout<<"Node founded :"<<"|"<<itr->data<<"|"<<itr->id<<"|->"<<endl;
				cout<<"Total time of search is ::"<<time_counter<<endl;
				break;
				
			}else  if( itr->linkfirst!=NULL &&itr->linkfirst->id==id_search ){
			
				cout<<"Node founded :"<<"|"<<itr->data<<"|"<<itr->id<<"|->"<<endl;
				cout<<"Total time of search is ::"<<time_counter<<endl;
				break;
				
			}else if(itr->linksecond!=NULL &&   itr->linksecond->id==id_search){
				cout<<"Node founded :"<<"|"<<itr->data<<"|"<<itr->id<<"|->"<<endl;
				cout<<"Total time of search is ::"<<time_counter<<endl;
				break;
				
				
			}else if(itr->linkthird!=NULL &&   itr->linkthird->id==id_search){
				cout<<"Node founded :"<<"|"<<itr->data<<"|"<<itr->id<<"|->"<<endl;
				cout<<"Total time of search is ::"<<time_counter<<endl;
				break;
				
			
			}else if(itr->id%2==0){
				
				if( itr->linkthird!=NULL &&itr->linkthird->id<id_search && flag==true){
					if(itr->id==itr->next->id){
//			    time_counter=time_counter+itr->timelimit/2;	
			}else{
				
				time_counter=time_counter+itr->timelimit;	
			}
				itr=itr->linkthird;
				
				flag=false;
			}else if(itr->linksecond!=NULL &&   itr->linksecond->id<id_search && flag==true){
					if(itr->virtual_id==itr->next->virtual_id){
//			time_counter=time_counter+itr->timelimit/2;	
			}else{
				
				time_counter=time_counter+itr->timelimit;	
			}
				itr=itr->linksecond;
				flag=false;
				
			}else if(itr->linkfirst!=NULL &&   itr->linkfirst->id<id_search && flag==true){
					if(itr->virtual_id==itr->next->virtual_id){
//			time_counter=time_counter+itr->timelimit/2;	
			}else{
				
				time_counter=time_counter+itr->timelimit;	
			}
			
				itr=itr->linkfirst;
				flag==false;
		
			}
			}
			
			
			
			itr=itr->next;
		}while(itr!=head);
			
	}
	
	
	};
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
		    c1.add();	
			i++;
			
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
//		c1.checklink();
		break;
		
	case 4:
	c1.searchNode();
	break;
	default:
		goto jump;
		cout<<"wrong choice...";
}	
}	jump:
	c1.displayclockwise();
}



