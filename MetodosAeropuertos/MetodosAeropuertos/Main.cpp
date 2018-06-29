#include "Header.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	ProyectMethods pm;
	string a = "hola";
	/*char *ab = new char[300];

	pm.Read_Airport(ab, 1);

	cout << ab << endl;*/
	
	/*cout << pm.Exist_Airport("B");

	cout << pm.Lenght_R()<<"\n";

	cout<< pm.Create_Route("BEL", "MXC", 2190)<<"\n";
	cout << pm.Create_Route("BEL", "LPR", 3012); "\n";

    cout<<pm.Lenght_R();*/

	//cout << pm.Create_Route("BEL", "MXC", 2190) << "\n";


	////pm.Delete_Airport("TGS");
	/*pm.Update_Airport("BLZ", "BLE", 15.00, 15.00);*/
	
	/*cout << pm.Read_Airport(1)<<endl;*/
	//pm.Create_Airport(m, 23, 45);

	//cout << pm.Read_Airport(2);
	//cout << pm.Lenght_Arch();
	
	/*string buffer("46.45 904.45");
	size_t sz;

	double nombre = stod(buffer, &sz);
	double nm = stod(buffer.substr(sz));

	cout << nombre << "\t" << nm;
	*/

	pm.Update_Route("QDS", "TOP", "PTO", 2345);

	/*char *p=new char[200];
	pm.Read_Route(p, 1);*/

	
	system("pause");
}