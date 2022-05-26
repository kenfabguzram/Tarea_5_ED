#include <iostream>
#include "time.h"
#include <windows.h>
#include "HashTable.h"
#include "Dictionary.h"


using namespace std;
void intAndStringTest(){
    //Se configura el programa para que muestre tildes
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    srand(time(0));
    //Pide la cantidad de elementos para los hashTable
    cout<<"Inserte la cantidad de buckets que desea para las dos HashTables diferentes: ";

    int nbuckets;
    cin>>nbuckets;
    cout<<"Inserte una cantidad de elementos para insertar en dos HashTables diferentes: ";

    int size;
    cin>>size;
    if(size<=0)  throw runtime_error("Error: El número ingresado debe ser un entero positivo.");
//---------------------------------------------------------------------------------------------------------------------------
//test constructor
    Dictionary<int,string> *hash1=new HashTable<int,string>(nbuckets);
    Dictionary<int,string> *hash2=new HashTable<int,string>(nbuckets);


    //Agrega elementos aleatorios a los HashTables
    int random1;
    int random2;
    random1=rand();
    random2=rand();
    for(int i=0;i<size;i++){
        while (true){
//---------------------------------------------------------------------------------------------------------------------------
//test contains
            if(hash1->contains(random1) ||hash2->contains(random1) ||hash1->contains(random2)||hash2->contains(random2)){
                random1=rand();
                random2=rand();
            }
            else{
//---------------------------------------------------------------------------------------------------------------------------
//test insert
                hash1->insert(random1,to_string(rand()));
                hash2->insert(random2,to_string(rand()));
                break;
            }
        }
    }
//---------------------------------------------------------------------------------------------------------------------------
//test getSize
    cout<<"El número de elementos escogido por el usuario fue: "<<hash1->getSize()<<endl;
    cout<< "Impresión Hash 1: "<<endl;
    hash1->print();



    cout<<"Llaves del hash 1: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test getKeys
    List<int>* keys1=hash1->getKeys();
    keys1->print();
    cout<<"Valores relacionados a las llaves del hash 1: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test getValues
    List<string>* values1=hash1->getValues();
    values1->print();
    keys1->goToPos(3);
//---------------------------------------------------------------------------------------------------------------------------
//test remove
    cout<<"Removiendo la llave "<< keys1->getElement()<<" con el valor "<<hash1->remove(keys1->getElement())<<" del hash 1..."<<endl;

    cout<<"Imprimiendo hash 1: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test print
    hash1->print();
    keys1->goToPos(1);
//---------------------------------------------------------------------------------------------------------------------------
//test getValue
    cout<<"Imprimiendo el valor ligado a la llave en la posición 1 de la lista de llaves del hash 1: "<<hash1->getValue(keys1->getElement())<<endl;
    cout<<"Sustituyendo el valor impreso anteriormente por \"casa\"..."<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test setValue
    hash1->setValue(keys1->getElement(), "casa");
    cout<<"Imprimiendo hash 1: "<<endl;
    hash1->print();

    cout<< "Verificando si existe la llave cuyo valor fue cambiado por \"casa\" y si existe la llave removida del hash1..."<<endl;
    if(hash1->contains(keys1->getElement()))
        cout<<"La llave del valor casa sí existe!!!"<<endl;
    keys1->goToPos(3);
    if(!hash1->contains(keys1->getElement()))
        cout<<"La llave eliminada no existe..."<<endl;

    cout<<"Estas son las llaves y valores del hash 2: "<<endl;
    cout<<"Llaves: "<<endl;
    List<int>* keys2=hash2->getKeys();
    keys1->print();
    cout<<"Valores: "<<endl;
    List<string>* values2=hash2->getValues();
    values1->print();
    cout<<"Si unimos ambos diccionarios con el método update este sería el diccionario que nos quedaría: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test update
    hash1->update(hash2);
    hash1->print();
    cout<<"Por otro lado si unimos la lista de llaves y valores (no actualizada) del hash 1 al hash 2 por medio de zip nos quedaría el siguiente hash2:"<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test zip
    hash2->zip(keys1,values1);
    hash1->print();
//---------------------------------------------------------------------------------------------------------------------------
//test clear
    hash1->clear();
    cout<<"Imprimiendo hash 1 limpio: "<<endl;
    hash1->print();
    delete keys1;
    delete keys2;
    delete values1;
    delete values2;
//---------------------------------------------------------------------------------------------------------------------------
//test destructor

    delete hash1;
    delete hash2;
}
void stringAndIntTest(){
    //Se configura el programa para que muestre tildes
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    srand(time(0));
    //Pide la cantidad de elementos para los hashTable
    cout<<"Inserte la cantidad de buckets que desea para las dos HashTables diferentes: ";

    int nbuckets;
    cin>>nbuckets;
    cout<<"Inserte una cantidad de elementos para insertar en dos HashTables diferentes: ";

    int size;
    cin>>size;
    if(size<=0)  throw runtime_error("Error: El número ingresado debe ser un entero positivo.");
//---------------------------------------------------------------------------------------------------------------------------
//test constructor
    Dictionary<string,int> *hash1=new HashTable<string,int>(nbuckets);
    Dictionary<string,int> *hash2=new HashTable<string,int>(nbuckets);


    //Agrega elementos aleatorios a los HashTables
    int random1;
    int random2;
    random1=rand();
    random2=rand();
    for(int i=0;i<size;i++){
        while (true){
//---------------------------------------------------------------------------------------------------------------------------
//test contains
            if(hash1->contains(to_string(random1)) ||hash2->contains(to_string(random1)) ||hash1->contains(to_string(random2))
               ||hash2->contains(to_string(random2))){
                random1=rand();
                random2=rand();
            }
            else{
//---------------------------------------------------------------------------------------------------------------------------
//test insert
                hash1->insert(to_string(random1),rand());
                hash2->insert(to_string(random2),rand());
                break;
            }
        }
    }
//---------------------------------------------------------------------------------------------------------------------------
//test getSize
    cout<<"El número de elementos escogido por el usuario fue: "<<hash1->getSize()<<endl;
    cout<< "Impresión Hash 1: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test print
    hash1->print();



    cout<<"Llaves del hash 1: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test getKeys
    List<string>* keys1=hash1->getKeys();
    keys1->print();
    cout<<"Valores relacionados a las llaves del hash 1: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test getValues
    List<int>* values1=hash1->getValues();
    values1->print();
//---------------------------------------------------------------------------------------------------------------------------
//test goToPos
    keys1->goToPos(3);
//---------------------------------------------------------------------------------------------------------------------------
//test remove
    cout<<"Removiendo la llave "<< keys1->getElement()<<" con el valor "<<hash1->remove(keys1->getElement())<<" del hash 1..."<<endl;

    cout<<"Imprimiendo hash 1: "<<endl;
    hash1->print();
    keys1->goToPos(1);
//---------------------------------------------------------------------------------------------------------------------------
//test getValue
    cout<<"Imprimiendo el valor ligado a la llave en la posición 1 de la lista de llaves del hash 1: "<<hash1->getValue(keys1->getElement())<<endl;
    cout<<"Sustituyendo el valor impreso anteriormente por el entero 5..."<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test setValue
    hash1->setValue(keys1->getElement(), 5);
    cout<<"Imprimiendo hash 1: "<<endl;
    hash1->print();
    cout<< "Verificando si existe la llave cuyo valor fue cambiado por el entero 5 y si existe la llave removida del hash1..."<<endl;
    if(hash1->contains(keys1->getElement()))
        cout<<"La llave del valor casa sí existe!!!"<<endl;
    keys1->goToPos(3);
    if(!hash1->contains(keys1->getElement()))
        cout<<"La llave eliminada no existe..."<<endl;

    cout<<"Estas son las llaves y valores del hash 2: "<<endl;
    cout<<"Llaves: "<<endl;
    List<string>* keys2=hash2->getKeys();
    keys1->print();
    cout<<"Valores: "<<endl;
    List<int>* values2=hash2->getValues();
    values1->print();
    cout<<"Si unimos ambos diccionarios con el método update este sería el diccionario que nos quedaría: "<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test update
    hash1->update(hash2);
    hash1->print();
    cout<<"Por otro lado si unimos la lista de llaves y valores (no actualizada) del hash 1 al hash 2 por medio de zip nos quedaría el siguiente hash2:"<<endl;
//---------------------------------------------------------------------------------------------------------------------------
//test zip
    hash2->zip(keys1,values1);
    hash1->print();
//---------------------------------------------------------------------------------------------------------------------------
//test clear
    hash1->clear();
    cout<<"Imprimiendo hash 1 limpio: "<<endl;
    hash1->print();
    delete keys1;
    delete keys2;
    delete values1;
    delete values2;
//---------------------------------------------------------------------------------------------------------------------------
//test destructor
    delete hash1;
    delete hash2;
}
int main(){
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    while(true){
        cout<<"Inserte 1 para realizar el test de KVPair<int,string> y 2 para realizar el test de KVPair<string,int>: ";
        int eleccion;
        cin>>eleccion;
        if (eleccion==1){
            intAndStringTest();
            break;
        }
        if (eleccion==2){
            stringAndIntTest();
            break;
        }
    }
    return 0;
}

