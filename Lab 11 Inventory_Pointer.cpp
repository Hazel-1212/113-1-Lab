#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void display(int* IDs,int* qs); //Display the ID and quantity
void update(int* IDs,int* qs,int ID,int q); //Update the quantity of Product ID
void query(int* IDs,int* qs,int ID); //Inquire the quantity of Product ID 
void sq(int* IDs,int* qs); //Sort by the incremental sequence of quantity
void sid(int* IDs,int* qs); //Sort by the incremental sequence of ID

void display(int* IDs,int* qs){
	cout<<"ProductIDs: ";
	for(int i=0;i<5;i++){
		cout<<setw(5)<<*(IDs+i); //pointer is compulsive to be used in Lab 11
	}
	cout<<endl;
	cout<<"Quantities: ";
	for(int i=0;i<5;i++){
		cout<<setw(5)<<*(qs+i);
	}
	cout<<endl;
	cout<<endl;
}

void update(int* IDs,int* qs,int ID,int q){
	int index=-1;
	
	for(int i=0;i<5;i++){
			if(*(IDs+i)==ID){
				index=i;
				break;
			}
		
	}
	
	if(index==-1){
		cout<<"Error: productID "<<ID<<" not found!\n";
	}else{
		cout<<"ProductID "<<ID<<": ";
		cout<<*(qs+index)<<" -> "<<q<<endl;
		*(qs+index)=q;
	}
	cout<<endl;

}

void query(int* IDs,int* qs,int ID){
	int index=-1;
	
	for(int i=0;i<5;i++){
			if(*(IDs+i)==ID){
				index=i;
				break;
			}
		
	}
	
	if(index==-1){
		cout<<"Error: productID "<<ID<<" not found!\n";
	}else{
		cout<<"ProductID "<<ID<<": ";
		cout<<*(qs+index)<<endl;
	}
	cout<<endl;
}

void sq(int* IDs,int* qs){
	int temp;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
		if(*(qs+j)>*(qs+j+1)){
			temp=*(qs+j);
			*(qs+j)=*(qs+j+1);
			*(qs+j+1)=temp;
			
			temp=*(IDs+j);
			*(IDs+j)=*(IDs+j+1);
			*(IDs+j+1)=temp;
		}
   	 }
	}
	cout<<endl;
}

void sid(int* IDs,int* qs){
	int temp;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
		if(*(IDs+j)>*(IDs+j+1)){
			temp=*(IDs+j);
			*(IDs+j)=*(IDs+j+1);
			*(IDs+j+1)=temp;
			
			temp=*(qs+j);
			*(qs+j)=*(qs+j+1);
			*(qs+j+1)=temp;
		}
   	 }
	}
	cout<<endl;
}

int main(){
	//5 items 
	int* IDs=new int [5];
	int* qs=new int [5];
	int ID,newQ;

cin>>IDs[0]>>IDs[1]>>IDs[2]>>IDs[3]>>IDs[4];
cin>>qs[0]>>qs[1]>>qs[2]>>qs[3]>>qs[4];

	string command;
	int time=0;
	cin.ignore(); //switch cin to getline
	
while(1){
	//Read command
	getline(cin,command);
	
	if(command=="display"){
		cout<<"Current command: ";
		cout<<command<<endl;
		display(IDs,qs);
	}
	
	else if(command.find("update")==0){
		cout<<"Current command: ";
		cout<<"update"<<endl;
		int pos=command.find(" ",0);
		int next=command.find(" ",pos+1);
		string strID=command.substr(pos+1,next-pos-1);
		string strQ=command.substr(next+1,command.length()-next-1);
		ID=atoi(strID.c_str());
		newQ=atoi(strQ.c_str());
		update(IDs,qs,ID,newQ);
	}
	
	else if(command.find("query",0)==0){
		cout<<"Current command: ";
		cout<<"query"<<endl;
		int pos=command.find(" ",0);
		int next=command.length();
		string strID=command.substr(pos+1,next-pos-1);
		ID=atoi(strID.c_str());
		query(IDs,qs,ID);
	}
	
	else if(command.find("sq",0)==0){
		cout<<"Current command: ";
		cout<<"sq"<<endl;
		sq(IDs,qs);
	}
	
	else if(command.find("sid",0)==0){
		cout<<"Current command: ";
		cout<<"sid"<<endl;
		sid(IDs,qs);
	}
	
	
	else if(command=="exit"){
		cout<<"Current command: ";
		cout<<"exit"<<endl;
		break;
	}
	
	else{
		cout<<"Error: Invalid command!\n";
		cout<<endl;
	}	
	}
}
	

