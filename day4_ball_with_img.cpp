#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
float const grav = -9.8;

struct Image {
	int mx;
	int my;
	int* points;
};

struct Node {
	float t;
	float h;
	float v;
	Node *next;
};

void createImage(Image* img, int tmx, int tmy)
{
	img->mx = tmx;
	img->my = tmy;
	img->points = new int[tmx * tmy]{ 1 };
}


void showImage(Image* img) {
	for (int i = 0; i < img->mx; i++) 
	{
		for (int j = 0; j < img->my; j++) 
		{
			cout << img->points[(i * (img->my)) + j];
		}
		cout << endl;
	}
}

int getPointImage(Image* img, int x, int y) 
{
	img->points[(y * img->mx + x)];
}

void setPointImage(Image* img, int x, int y, int color) 
{
	img->points[(y * img->mx + x)] = color;
}

void saveToPnmFile(Image* img, string fileName) {

	fstream out;
	out.open(fileName, fstream::out);

	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++)
		{
			out << img->points[i * img->mx + j] << " ";
		}
		out << endl;
	}
	out.close();
}


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
	float savedHeight = h;
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
	while (end->next != NULL)
	{
		if (end->h < 0)
		{
			cout << "Ball collision";
			return -1;
		}
		end = end->next;
	}
	float timeOfEmulation = end->t;
	Image* img = new Image;
	createImage(img, int(timeOfEmulation) * 50, int(savedHeight)*5);
	end = head;
	while (end != NULL)
	{
		setPointImage(img, int(50*end->t), int(head->h - end->h)*5, 1);
		end = end->next;
	}
	saveToPnmFile(img,"TestImage.pnm");
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
	runTest(testCollision, "Collision");
}
