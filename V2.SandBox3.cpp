//Name: Ethan Thomas
//CS 132 Section: A
//Description: This program will read into a file and 
//then store the data using my string class
//that I created and saves all data
//into a vector. This vector will then combine five words
// at a time. Then it will organize the new words
//from smallest to biggest. For now though capital
//letters will be before lowercase letters.
//The program then will write out the results to
//another file along with length count and capacity 
//count on each line. At the end the program will display
//the number of instances created and the number of 
//current instances.

#include "stdafx.h"
#include "ETString.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;


int main()
{
	fstream fin;
	fstream fout;
	vector<ETString> vector_of_char_str(100);
	ETString temp;
	
	fin.open("infile3.txt");
	check(fin);
	
	
	int i = 0;
	int count = 0;
	while(fin >> temp)
	{
		count++;
		vector_of_char_str[i] = vector_of_char_str[i] + temp;
		if (count == 5)
		{
			i++;
			count = 0;
		}		
	} vector_of_char_str.resize(i + 1);
	fin.close();
	

	bool swapped = true;
	while (swapped)
	{			  
		swapped = false;
		for (int i = 0; i < vector_of_char_str.size()-1; i++)
		{
			if (vector_of_char_str[i+1] < vector_of_char_str[i])
				{
					swapped = true;
					temp = vector_of_char_str[i + 1];
					vector_of_char_str[i + 1] = vector_of_char_str[i];
					vector_of_char_str[i] = temp;
				}	
		}
	}
	
	
	fout.open("output.txt");
	check(fout);
	

	for (int i = 0; i < vector_of_char_str.size(); i++)
	{	
		fout << vector_of_char_str[i];
		fout << setw(95 - vector_of_char_str[i].length());
		fout << vector_of_char_str[i].length() << " : " << vector_of_char_str[i].capacityFunc();
		fout << endl;
	}
	fout << endl;
	fout << "The number of instances created: " << ETString::getCreatedCount() << endl;
	fout << "The number of current instances: " << ETString::getCurrentCount() << endl;
	fout.close();	


	system("pause");
    return 0;
}

//Output:
//
//Ibegantocomparethe                                                                           18 : 20
//Ifeltwasimpossible.Or                                                                        21 : 40
//Theyseemedamazinglybusy.I                                                                    25 : 40
//andrulesinhisbody ?																		   18 : 20
//anironcladorasteam                                                                           18 : 20
//asaman'sbrainsits                                                                            17 : 20
//askmyselfforthefirst                                                                         20 : 40
//begantoaskmyselfwhat                                                                         20 : 40
//didaMartiansitwithin                                                                         20 : 40
//each, ruling, directing, using, much                                                         32 : 40
//enginewouldseemtoan                                                                          19 : 20
//intelligentloweranimal.ThisIsMyAmazinglyLongStringToMakeYourExtractionOperatorWorkCorrectly. 92 : 100
//intelligentmechanisms ? Suchathing                                                           32 : 40
//theycouldbe.Werethey                                                                         20 : 40
//thingstohumanmachines, to                                                                    24 : 40
//timeinmylifehow                                                                              15 : 20
//
//The number of instances created : 180
//The number of current instances : 17