using namespace std;
#include<iostream>
#include<math.h>
struct node{
	string  data;
	//I take time in milli seconds
	long timelimit;
	bool isvirtural;
	int virtual_id;
	int id;
	node* next;
	node* prev;
	};	
int global_id=0,virtual_id=0;
class virtural_ring{
	
	public:
		node* head;
		node* tail;
		
	virtural_ring(){
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
	
	
struct node* middle(node* start, node* last)
{
    if (start == NULL)
        return NULL;
 
    struct node* slow = start;
    struct node* fast = start -> next;
 
   
    do{
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    } while (fast != last);
 
    return slow;
}


void search(){
	node* start=head;
	node* end=tail;
	int id12;
	cout<<"Enter id to search :";
	cin>>id12;
	do{
		node* mid=middle(start,end);
		if(mid==NULL){
			
			break;
		}else
	   	    if(mid->id==id12){
	   		
	   	cout<<"|"<<mid->data<<"|";	
	   		break;
		}else if(mid->id<id12){
			
			start=mid->next;
			
		}else if(mid->id>id12){
			end=mid;
			
		}
		
		
	}while(start!=tail);
	
	
	
}










//
// node* binarySearch()
//{
//	 string value;
//	 cout<<"Enter value to search in node::";
//	 cin>>value;
//    struct node* start = head;
//    struct node* last = tail;
// 
//    do
//    {
//        // Find middle
//        node* mid = middle(start, last);
// 
//        // If middle is empty
//        if (mid == NULL)
//            return NULL;
//            
//        // If value is present at middle
//        if (mid->data== value)
//            return mid;
//          
//        // If value is more than mid
//        else if (mid->data < value)
//            start = mid -> next;
// 
//        // If the value is less than mid.
//        else
//            last = mid->prev;
// 
//    }while(true); 
////	while (last == NULL ||
////             last != start);
// 
//    // value not present
//    return NULL;
//}
//	
//	void search(){
//		node* itr=head;
//	do{
//	
//			
//			
//			itr=itr->next;
//		}while(itr!=head);	
//	}
};




int main(){
	virtural_ring v1;
	int choice;
	
while(true){
cout<<endl;
cout<<"Enter 1 for insertion()"<<endl;	
cout<<"Enter 2 for displayClockWise()"<<endl;	
cout<<"Enter 3 for search()"<<endl;
cin>>choice;
switch(choice){
	
	case 1:
		v1.add();
//		global_id++;
		
		break;
	case 2:
		v1.displayclockwise();
		break;
	case 3:
//		v1.binarySearch();
     v1.search();
//       if(choice==3){
//       	   node* n1=v1.middle(v1.head,v1.tail);
//////      node* n1=v1.binarySearch();
//        cout<<n1->data;
//	   }
		break;
		
	default:
		cout<<"You Entered invalid choice...";
//		goto jump;
	
	
}	
}
	
//	jump:
	
	return 0;
}	
	
	
