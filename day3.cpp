#include <iostream>
#include <cmath>
using namespace std;
float const grav = -9.8;

struct Node {
	float t;
	float h;
	float v;
	Node *next;
};

void init (Node *node, float height)
{
	node->t = 0;
	node->h = height;
	node->v = 0;
	node->next = NULL;
}

void pushNode(Node* head, float timeStep) 
{
	Node* p = head;
	while (p->next != NULL) 
	p = p->next;
	p->next = new Node;
	p->next->t = p->t + timeStep;
	p->next->h = p->h + (p->v * timeStep) + (grav*timeStep*timeStep/2);
	p->next->v = p->v + grav * timeStep; 
	p->next->next = NULL;
}

void show(Node* head) 
{
	Node *element = head;
	while (element != NULL)
	{
		cout <<"\n Time:" << element->t << "\n Height: " << element->h <<"\n Velocity: "<<element->v<<"\n Acceleration: "<< grav;
		cout << "\n-----------------------";
		element = element->next;
	}
	cout << "\n";
}

float collision(Node *head, float h,float loss, float hitTime)
{
	Node *l = head;
	while(l->next != NULL)
	{
		l = l->next;
	}
	l->t = hitTime;
	l->h = 0;
	l->v = sqrt(2*(-grav)*h) * sqrt((100-loss)/100);
	return l->v;
}

int testCollision()
{
	Node *head = new Node;
	float h = 3;
	float loss = 50;
	float timeStep = 0.1;
	float hitTime = sqrt(2.0*h/(-grav));
	init(head,h);
	float t = 0;
	while (h > 0.001)
	{
		while (t < hitTime - timeStep)
		{
			pushNode(head, timeStep);
			t += timeStep;
		}
		float v = collision(head,h,loss,hitTime);
		t = hitTime;
		float t = v/(-grav);
		h = v*t + grav*t*t/2;
		hitTime += 2*t;
	}
	show(head);
	Node *end = head;
	return 0;
}

int mainCollision(int h, int loss, float timeStep)
{
	Node *head = new Node;
	float hitTime = sqrt(2.0*h/(-grav));
	init(head,h);
	float t = 0;
	while (h > 0.001)
	{
		while (t < hitTime - timeStep)
		{
			pushNode(head, timeStep);
			t += timeStep;
		}
		float v = collision(head,h,loss,hitTime);
		t = hitTime;
		float t = v/(-grav);
		h = v*t + grav*t*t/2;
		hitTime += 2*t;
	}
	show(head);
	Node *end = head;
	return 0;
}

static void runTest(int (*testFunction)(), const std::string& Name)
{
  if((testFunction()== 0))
    cout << "Test "<< Name << " OK" << std::endl;
  else 
    cout << "Test "<< Name << " FAIL" << std::endl;
}

int main()
{
	runTest(testCollision,"Collision");
	cout << "Enter height: ";
	float h;
	cin >> h;
	cout << "\nEnter loss: ";
	float loss;
	cin >> loss;
	cout << "\nEnter time step: ";
	float timeStep;
	cin >> timeStep;
	mainCollision(h, loss, timeStep);
}
