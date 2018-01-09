#include<iostream>
#include"LinkedList.h"
using namespace std;

int main(){
	
	LinkedList ll;
	ll.push(1);
	ll.push(2);
	ll.push(3);
	ll.push(4);
	// LinkedList *ll;
	// cout<<"1";
	// ll->push(1);
	// ll->push(2);
	// ll->push(3);
	// ll->push(4);
	cout<<ll.first()<<" "<<ll.last()<<endl;
	Node *p = ll.getFront();
	while(p != nullptr) {
		cout<<p->getData()<<" ";
		p = p->next();
	}
	cout<<endl;
	ll.reverse();
	p = ll.getFront();
	while(p != nullptr) {
		cout<<p->getData()<<" ";
		p = p->next();
	}
	cout<<endl;
	int index1 = ll.indexOf(2);
	int index2 = ll.indexOf(5);
	int index3 = ll.indexOf(4);
	cout<<index1<<" "<<index2<<" "<<index3<<endl;
	cout<<ll.contains(2)<<" "<<ll.contains(5)<<" "
		<<ll.contains(4)<<endl;
	// while(!ll.isEmpty()) {
	// 	cout<<ll.popFront()<<" ";
	// }
	// cout<<endl;
	// ll.push(1);
	// ll.push(2);
	// ll.push(3);
	// ll.push(4);
	// while(!ll.isEmpty()) {
	// 	cout<<ll.pop()<<" ";
	// }
	// cout<<endl;
	// cout<<ll->first()<<" "<<ll->last()<<endl;
	return 0;

}