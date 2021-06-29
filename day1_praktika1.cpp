#include <iostream>
#include <string>
#define _countof(array) (sizeof(array) / sizeof(array[0]))
//Dzhumabaev, M3O-112B-20, var 3, zadanie 1, 2.
int CompareMas(int* source, int* dest, unsigned int size){
    int count = 0;
    for (unsigned int n = 0; n<size ; n++){
        if (source[n] != dest[n])
        count = count + 1;
    }
    if (count != 0){
    	std::cout << "-1 \n";
    	return -1;
    	}
    else{
    	std::cout << "0 \n";
    	return 0;
		}
}

void test(int* source, int* dest, unsigned int size) {
	int a = CompareMas(source, dest, size);
    if ((a == -1) || (a == 0))
        printf("OK");
    else 
        printf("FAIL");
}

int main()
{
    unsigned int size = 4;
    int source[] = {1,3,5,7};
    int dest[] = {1,3,5,6};
    while ((_countof(source) < size) || (_countof(source) < size)){
		std::cout << "Wrong size, enter a new one";
		std::cin >> size;
	}
	test(source, dest, size);
}

