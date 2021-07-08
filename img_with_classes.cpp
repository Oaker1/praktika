#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class task{
public:
struct Image {
	int mx;
	int my;
	int* points;
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

void saveToPnmFile(Image* img, ofstream &fileName) 
{
	for (int i = 0; i < img->mx; i++) 
	{
		for (int j = 0; j < img->my; j++) 
		{
			fileName << img->points[(i * (img->mx + 1)) + j];
		}
		fileName << endl;
	}
}

int testCreateImage()
{
	Image* img = new Image;
	createImage(img, 1, 3);
	if (img->points[0] == 0 && img->points[2] == 0 && img->mx == 1 && img->my == 2)
		cout<<"Test CreateImage FAIL\n";
	cout<<"Test CreateImage OK\n";
}

int testSetPointImage()
{
	Image* img = new Image;
	createImage(img, 1, 3);
	setPointImage(img, 1, 0, 245);
	setPointImage(img, 0, 3, 255);
	if (getPointImage(img, 1, 0) == 245 && getPointImage(img, 0, 3) == 255)
		cout<<"Test SetPointImage FAIL\n";
	cout<<"Test SetPointImage OK\n";
}

int testGetPointImage()
{
	Image* img = new Image;
	createImage(img, 1, 3);
	img->points[2] = 255;
	if (getPointImage(img, 1, 2) == 255 && getPointImage(img, 1, 1) == 0)
		cout<<"Test GetPointImage FAIL\n";
	cout<<"Test CreateImage OK\n";
}

int testSaveToPnmFile() {
	Image* img = new Image;
	createImage(img, 6, 6);
	ofstream fount;
	fount.open("TestFile.txt");
	saveToPnmFile(img, fount);
	fstream f;
	f.open("TestFile.txt", ios::in);
	long file_size;
	f.seekg(0, ios::end);
	file_size = f.tellg();
	if (file_size == 0) {
		f.close();
		cout<<"Test SaveToPnmFile FAIL\n";
	}
	f.close();
	cout<<"Test SaveToPnmFile OK\n";
}

};


int main()
{
	task test;
	test.testSaveToPnmFile();
	test.testGetPointImage();
	test.testSetPointImage();
	test.testCreateImage();
}
