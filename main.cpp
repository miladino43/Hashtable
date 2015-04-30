//#include "LinkedList.h"
#define _CRTDBG_MAP_ALLOC

//#include <crtdbg.h>
#include "HashTable.h"
//#include "time.h"

void LinkedListTest();
void HashTableTest();
void setTest();
void simpleTest();

int main(){
	 //srand(time(0));

 

  //    // This ugly stuff here is required to display debug data about memory leaks

  //  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);

  //  _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);

  //  _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);

  //  _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);

  //  _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);

  //  _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	//LinkedListTest();
	//HashTableTest();
	//simpleTest();
	setTest();
	//_CrtDumpMemoryLeaks();
	return 0;
}
void LinkedListTest(){


	LinkedList list;

	cout<<"0-"<<list.search("hello")<<endl;
	cout<<"1-"<<list.insert("hello")<<endl;
	cout<<"1-"<<list.insert("milad")<<endl;
	cout<<"0-"<<list.insert("hello")<<endl;
	cout<<"1-"<<list.insert("HELLO")<<endl;
	cout<<"1-"<<list.insert("amir")<<endl;
	cout<<"1-"<<list.insert("mahtab")<<endl;
	cout<<"1-"<<list.insert("melika")<<endl;

	cout<<"1-"<<list.remove("amir")<<endl;
	cout<<"0-"<<list.remove("amir")<<endl;
	cout<<"0-"<<list.remove("shayan")<<endl;
	cout<<"0-"<<list.search("amir")<<endl;

	vector<string> listvec = list.get();

	for(int i=0; i < listvec.size(); i++){
	
	cout << listvec[i] <<",";
	
	}

}
void HashTableTest(){
	HashTable ht;
	//cout<<"1-"<<ht.primeCheck(2)<<endl;
	//cout<<"0-"<<ht.primeCheck(10)<<endl;
	//cout<<"1-"<<ht.primeCheck(19)<<endl;

	HashTable ht2(3);

	/*cout<<"1-"<<ht2.hashFunc("a")<<endl;
	cout<<"2-"<<ht2.hashFunc("b")<<endl;
	cout<<"3-"<<ht2.hashFunc("c")<<endl;
	cout<<"26-"<<ht2.hashFunc("z")<<endl;
	cout<<"25-"<<ht2.hashFunc("y")<<endl;*/
	

	cout<<"1-"<<ht2.insert("abc")<<endl;

	//vector<string> table=ht2.listArr[6].get();

	cout<<"0-"<<ht2.insert("")<<endl;
	cout<<"1-"<<ht2.search("abc")<<endl;
	cout<<"0-"<<ht2.search("cab")<<endl;
	
	HashTable ht3(1);
	cout<<"1-"<<ht3.insert("abc")<<endl;
	cout<<"1-"<<ht3.insert("zxy")<<endl;
	cout<<"1-"<<ht3.insert("uvw")<<endl;
	cout<<"1-"<<ht3.insert("def")<<endl;
	cout<<"1-"<<ht3.remove("def")<<endl;
	cout<<"0-"<<ht3.remove("def")<<endl;
	cout<<"1-"<<ht3.insert("def")<<endl;
	cout<<"0-"<<ht3.insert("def")<<endl;
	cout<<"1-"<<ht3.insert("a")<<endl;
	cout<<"0-"<<ht3.remove("")<<endl;
	cout<<"0-"<<ht3.insert("as;")<<endl;
	

	HashTable ht4(ht3);
	HashTable ht5 = ht4;
	HashTable ht6;
	cout<<"1-"<<ht6.insert("as;")<<endl;
	vector<string> intersection = ht4.intersection(ht2);
	vector<string> unions = ht5.unions(ht4);
	vector<string> difference = ht5.difference(ht4);

	//cout<<"75-"<<ht2.hashFunc("zyx")<<endl;

	//cout<<"1091-"<<ht2.hashFunc("abc")<<endl;
}
void simpleTest()

{

  HashTable ht1(9);

  ht1.insert("bat");

  ht1.insert("cat");

  ht1.insert("rhinoceros");

  ht1.insert("ocelot");

  ht1.insert("elephant");

  ht1.insert("hippopotamus");

  ht1.insert("giraffe");

  ht1.insert("camel");

  ht1.insert("lion");

  ht1.insert("panther");

  ht1.insert("bear");

  ht1.insert("wolf");

 

  // search

  cout << "search" << endl;

  string test1 = "frog";

  string test2 = "camel";

  cout << test1 << ": " << ht1.search(test1) << endl;

  cout << test2 << ": " << ht1.search(test2) << endl;

 

  // copy constructor and remove

  HashTable ht2(ht1);

  ht2.remove("ocelot");

  ht2.remove("camel");

  ht2.remove("rhinoceros");

 

  // set difference

  cout << endl << "set difference" << endl;

  vector<string> difference = ht1.difference(ht2);

  for(int i=0; i < difference.size(); ++i){

         cout << difference[i] << endl;

  }

}
void setTest(){

	HashTable ht;

	cout<<"1-"<<ht.insert("abc")<<endl;
	cout<<"1-"<<ht.insert("big")<<endl;
	cout<<"1-"<<ht.insert("dinosour")<<endl;
	cout<<"1-"<<ht.insert("longlivetheking")<<endl;
	cout<<"1-"<<ht.insert("ineedtofinishthisgayshit")<<endl;

	HashTable ht1;

	cout<<"1-"<<ht1.insert("cat")<<endl;
	cout<<"1-"<<ht1.insert("manchester")<<endl;
	cout<<"1-"<<ht1.insert("dinosour")<<endl;
	cout<<"1-"<<ht1.insert("newyork")<<endl;
	cout<<"1-"<<ht1.insert("ineedtofinishthisgayshit")<<endl;

	vector<string> intersection = ht.intersection(ht1);
	cout<<endl;
	cout<<endl;
	for(int i = 0; i<intersection.size(); i++){
	
		cout<<intersection[i]<<",";
	}

	vector<string> unions = ht.unions(ht1);
	cout<<endl;
	cout<<endl;
	for(int i = 0; i<unions.size(); i++){
	
		cout<<unions[i]<<",";
	}

	vector<string> difference = ht.difference(ht1);
	cout<<endl;
	cout<<endl;
	for(int i = 0; i<difference.size(); i++){
	
		cout<<difference[i]<<",";
	}
	cout<<endl;
	cout<<"LoadFactor:"<<ht1.loadFactor()<<endl;
	cout<<"Numberof elements:"<<ht1.size()<<endl;
	cout<<"array size:"<<ht1.maxSize()<<endl;
	//------------------------------------------------------------------------------------------------


	HashTable ht3;
	HashTable ht4;
	vector<string> intersection2 = ht3.intersection(ht4);
	cout<<endl;
	cout<<endl;
	for(int i = 0; i<intersection2.size(); i++){
	
		cout<<intersection2[i]<<",";
	}

	vector<string> unions2 = ht3.unions(ht4);
	cout<<endl;
	cout<<endl;
	for(int i = 0; i<unions2.size(); i++){
	
		cout<<unions2[i]<<",";
	}

	vector<string> difference2 = ht3.difference(ht4);
	cout<<endl;
	cout<<endl;
	for(int i = 0; i<difference2.size(); i++){
	
		cout<<difference2[i]<<",";
	}
	cout<<endl;
	HashTable empty;
	HashTable empty2;

	vector<string> unionempty = empty.unions(empty2);
}