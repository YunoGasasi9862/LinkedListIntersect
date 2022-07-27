#include <iostream>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;

	Node(int x)  //getNode fucntion
	{
		data = x;
		next = NULL;
	}


	Node* AddBeginning(Node* hp, int data)
	{
		Node* temp = new Node(data);
		temp->next = hp;
		return temp;
	}

	void AddAfter(Node* hp, int data)
	{
		Node* temp = new Node(data);
		temp->next = hp->next;
		hp->next = temp;
    }
	void AddAfter(Node* hp1, Node* hp2)
	{
		hp1->next = hp2; //overload
	}

	Node* DeleteFirst(Node* hp)
	{
		Node* temp = hp;
		hp = temp->next;
		delete(temp);
		return hp;
	}

     void DeleteAfter(Node* hp)
	{
		Node* temp = hp->next;
		hp->next = temp->next;
		delete(temp);
	}
};

Node* ReverseLinkedList(Node* hp)
{

	Node* current=NULL, *prev=NULL, *next=NULL;
	current = hp;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	current = prev;
	return current;
}
int intersectPoint(Node* head1, Node* head2)
{
	Node* temp1 = head1;
	Node* temp2 = head2;
	int cnt1 = 0;
	int cnt2 = 0;
	//do counting method now. Count the nodes, and proceed :)

	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		cnt1++;
	}

	while (temp2 != NULL)
	{
		temp2 = temp2->next;
		cnt2++;
	}

	if (cnt1 > cnt2)
	{
		temp1 = head1;
		for (int i = 0; i < cnt1 - cnt2; i++)
		{
			temp1 = temp1->next;
		}
		temp2 = head2;
	}

	else if (cnt2 > cnt1)
	{
		temp2 = head2;

		for (int i = 0; i < cnt2 - cnt1; i++)
		{
			temp2 = temp2->next;
		}
		temp1 = head1;
	}

	if (cnt1 == cnt2)
	{
		temp1 = head1;
		temp2 = head2;
		
	}
	//check for the test case 12 at night!!!!
	while (temp1 != NULL)
	{
		if (temp1==temp2)
		{
						
			return temp1->data;
		
		}
		else
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}


}


int main(void)
{

	Node* common = NULL;

	common = common->AddBeginning(common, 15);
	common->AddAfter(common, 30);


	Node* LinkedList1 = NULL;
   LinkedList1=LinkedList1->AddBeginning(LinkedList1, 3);
   LinkedList1->AddAfter(LinkedList1, common); //overload
   LinkedList1->AddAfter(LinkedList1, 9);
   LinkedList1->AddAfter(LinkedList1, 6);
 

   Node* LinkedList2 = NULL;
   LinkedList2 = LinkedList2->AddBeginning(LinkedList2, 10);
   LinkedList2->AddAfter(LinkedList2, common); //overload

  
   //now store all the address in a map. 
   //if in the map, the same address is encountered, that point is the intersectionpoint

   //LinkedList1 = ReverseLinkedList(LinkedList1);
   //LinkedList2 = ReverseLinkedList(LinkedList2);
   int Intersection = intersectPoint(LinkedList1, LinkedList2);
	return 0;
}