#include "stdafx.h"
#include "ETString.h"
#include "Functions.h"
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;




void check(fstream & istr)
{
	if (istr.fail())
	{
		cout << "Unable to find the output file." << endl;
		system("pause");
		exit(1);
	}
}