#include<iostream>
#include<stdio.h>
using namespace std;

void main() {
// Exercitiu: cauta elementul "2" in vectorul [0,2,4,6,8]
	int valCautata = 3;
	bool gasit = false;
	int v[] = { 0,2,4,6,8 };
	//v[5] = 10;//eroare
	for (int i = 0; i < 5; i++) {
		if (v[i] == valCautata) {
			cout << i;
			gasit = true;
			i = 5;
			break;
		}
	}
	if (gasit == false) {
		cout << -1;
	}

    //Def.1.: Tipuri de erori ( https://ro.differbetween.com/article/difference_between_compile_time_and_runtime ) 
            //Erori de compilare-> apar in momentul compilarii
            //Erori de executie-> apar in momentul executiei
    //OBS: Start Debugging!

    //Def.2.: Performanta unui program
            //Timp de executie & Memorie ocupata
   
    //Def.3.: Timp de executie: BigO ( https://www.geeksforgeeks.org/analysis-algorithms-big-o-analysis/ )
            //Exemplul initial de cautare a unui numar intr-un sir are complexitatea O(n) 
	
    //Def.4.: Memorie ocupata:
    cout << endl <<"Int= "<< sizeof(int);
	cout << endl << "Float= " << sizeof(float);
	cout << endl << "Double= " << sizeof(double);
	cout << endl << "Long= " << sizeof(long);
	cout << endl << "Long long= " << sizeof(long long);

	cout << endl << "Char= " << sizeof(char);
	cout << endl << "Bool= " << sizeof(bool);


	//Def.5.: STACK vs. HEAP (https://ocw.cs.pub.ro/courses/so/laboratoare/laborator-05)
    
	//Exemplu pe tabla: https://www.youtube.com/watch?v=_8-ht2AKyH4
	
	//Obs: 	
        //->Stack OVERFLOW (https://www.techtarget.com/whatis/definition/stack-overflow)
        //->Heap OVERFLOW (https://en.wikipedia.org/wiki/Heap_overflow)
        //->Memory Leaks (https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/)
}