#include<iostream>
#include<string.h>
using namespace std;
class Person{
	string name;
	char sex;
	Person *father;
	Person *mother;
  public:
	Person(string name,char sex,Person* father,Person* mother){
		this->name=name;
		this->sex=sex;
		this->father=father;
		this->mother=mother;
	}
	~Person(){}
	void setName(string name){
	this->name=name;
	}
	void setSex(char sex){
	this->sex=sex;
	}
	void setFather(Person *father){
	this->father=father;
	}
	void setMother(Person *mother){
	this->mother=mother;
	}
	string getName(){
	return name;
	}
	char getSex(){
	return sex;
	}
	Person * getFather(){
	return father;
	}
	Person * getMother(){
	return mother;	
	}
};
int main(){
	Person p1("张三",'M',NULL,NULL),p2("李四",'F',NULL,NULL),
			p3("王五",'M',NULL,NULL),p4("赵六",'F',NULL,NULL),
			p5("张二",'M',&p1,&p2),p6("王四",'F',&p3,&p4),
			p7("我",'F',&p5,&p6),p8("张一",'F',&p5,&p6);
	cout<<p7.getName()<<"的兄弟姐妹是";
	Person p[8]={p1,p2,p3,p4,p5,p6,p7,p8};
	for(int i=0;i<8;i++){
		if(i==6)
	    continue;
		else if(p[i].getFather()==p[6].getFather() || p[i].getMother()==p[6].getMother())
		    cout<<p[i].getName()<<" ";
	}
	cout<<endl;
	if(p7.getFather()!=NULL&&p7.getFather()->getFather()!=NULL)
		cout<<p7.getName()<<"的爷爷是"<<p7.getFather()->getFather()->getName()<<endl;
	if(p7.getFather()!=NULL&&p7.getFather()->getMother()!=NULL)
		cout<<p7.getName()<<"的奶奶是"<<p7.getFather()->getMother()->getName()<<endl;
	if(p7.getMother()!=NULL&&p7.getMother()->getFather()!=NULL)
		cout<<p7.getName()<<"的外公是"<<p7.getMother()->getFather()->getName()<<endl;
	if(p7.getMother()!=NULL&&p7.getMother()->getMother()!=NULL)
	    cout<<p7.getName()<<"的外婆是"<<p7.getMother()->getMother()->getName()<<endl;
	return 0;
}
