
//Code written by Sunday Aduloju
//Submitted to Prof. Dodds
//for HW1 (CEE 691)

#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void user_message(int mess_num);

void user_message(int mess_num)
{
	switch ( mess_num ) 
		{ 
		case 1 :
			cout << "\n\n Welcome to Warm-Up 2 program\n\n";
			cout << " Please enter the input file name >> " << flush;
			break;
		case 2:
			cout << "input file could not be opened .....\n" ;
			cout << "Please enter the input file name >> " ;
			break;
		case 3:
			cout << " File opened Successfully!" << endl ;
			break;
		case 4:
			cout << " An over flow is about to occur \nJob terminated ......\n";
			break;
		default:
			cout << " invalid message number..../n please crosscheck......\n";
			break;
		}
}


int main ()
{
const int max_values = 100;
int i, j, num_values, nspace, lead_spaces;
double values [max_values] , value, mean, sum, valuesqs [max_values] ,sumsqs, var,stddev;
const double dzero = 0.0, one = 1.0, two = 2.0;
char title[80];
string data_filename;
ifstream data_file;
//issue welcome message and enter process to query user for input file
user_message(1);

getline ( cin , data_filename); // get the input file name
data_file.open(data_filename.c_str() ); // open  the input file 

	while (!data_file.is_open()) //  As long as opening of file fail, follow the steps below
			{
				data_file.close();
				data_file.clear();
				user_message(2);
				getline (cin , data_filename);
				data_file.open(data_filename.c_str());
			}
//
// file opened ok. issue message to user.
// read first complete line of file into the character vector
	user_message(3);
	data_file.getline( title, 80, '\n');
//
// loop to read data values. each line has one

i = 0;
	while (true)
	{
		data_file >> value;
		if (data_file.eof()) break ;
		// check for overflow of data vector
			if ( i > max_values-1)   
				{
					user_message(4);
					return(0);
				}
		//  stick into vector
			else
				{		
					values [i] = value;
					i++;
				}
	}
num_values = i;

// Close the Data File
data_file.close();
cout << " The data file is closed ....." << endl << flush; 
// 
// vector of numerical values named "values" read. Number of
// entries in the vector is "num_values". The first
//numerical value is in values[0]
//
//mean
sum = dzero;
	for ( i=0; i<num_values; i=i+1) 
		{
			sum += values[i]; 
		}
mean = sum / (double) num_values;

//Standard deviation
sumsqs =dzero;
	for ( i=0; i<num_values; i=i+1)
		{
			valuesqs[i] = pow ((values[i] - mean), two);
			sumsqs += valuesqs[i];
		}
var = sumsqs / ((double) num_values - one); // variance
stddev = sqrt(var);
//
// print the number of the floating point numbers
// print the mean of the set of numbers and standard deviation
//
cout << endl << endl << endl << title << endl;
cout << endl << endl << " The number of floating point numbers read is:" << num_values << endl ;
cout <<  " The mean of the set of numbers is:" << mean << endl;
cout << " The standard deviation of the set of numbers is:" << stddev << endl;

cout << "\n The input data are:" << endl;

for ( i=0; i<num_values; i=i+1)
	{
		cout <<" " << values[i] << endl;
	}
return 0;
}
