
//Code written by Sunday Aduloju
//Submitted to Prof. Dodds
//for HW3 (CEE 691)

#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//
// global variables
//
ifstream data_file;

// function prototypes
void user_message(int mess_num);
void get_input_file_and_open(void);
void get_values_from_file( char [], double [], int &, const int);
void compute_statistics( double[], int, double &, double &);
void output_results( char [], int, double, double, double [] );


int main ()
{
const int max_values = 100;
int num_values;
double values[max_values], mean, stddev;
char title[80];
//issue welcome message and enter process to query user for input file
user_message(1);
get_input_file_and_open();
get_values_from_file( title, values, num_values, max_values);
compute_statistics( values, num_values, mean, stddev);
output_results( title, num_values, mean, stddev, values );

return 0;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//																			&
//				function : user_message										&
//				Author : Sunday Aduloju										&
//				Last Modified: 2/2/2018										&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void user_message(int mess_num)
{
	switch ( mess_num ) 
		{ 
		case 1 :
			cout << "\n\n Welcome to Warm-Up 2 program\n\n";
			break;
		case 2 :
			cout << " Please enter the input file name >> " << flush;
			break;
		case 3:
			cout << " Input file could not be opened .....\n" ;
			cout << " Please try again ......\n" ;
			break;
		case 4:
			cout << " File opened Successfully!" << endl ;
			break;
		case 5:
			cout << " An over flow is about to occur \n Job terminated ......\n";
			break;
		default:
			cout << " invalid message number..../n please crosscheck......\n";
			break;
		}
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//																			&
//				function : get_input_file_and_open							&
//				Author : Sunday Aduloju										&
//				Last Modified: 2/3/2018										&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void get_input_file_and_open(void)
{
	int ok;
	char file_id[80];
	ok = false;
	while (!ok ) 
			{
				user_message (2);
				cin >> file_id;
				data_file.open(file_id);
				ok = true;
				if (data_file.fail())
					{
						user_message(3); data_file.clear (); ok = false;
					}
			}
//
// file opened ok. issue message to user.
// read first complete line of file into the character vector
	user_message(4);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//																			&
//				function : get_values_from_file								&
//				Author : Sunday Aduloju										&
//				Last Modified: 2/3/2018										&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void get_values_from_file( char title[], double values[], int &num_values, const int max_values)
{
	int i;
	double value;
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
					user_message(5);
					return;
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
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//																			&
//				function : compute_statistics								&
//				Author : Sunday Aduloju										&
//				Last Modified: 2/3/2018										&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//
// compute mean and standard deviation
//
void compute_statistics( double values[], int num_values, double &mean , double &stddev )

// 
// vector of numerical values named "values" read. Number of
// entries in the vector is "num_values". The first
//numerical value is in values[0]
//
//mean
{
 int i;
 double sum, sumsqs, valuesqs [i];
 const double dzero = (double) 0.0, two = (double) 2.0, one = (double) 1.0;
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
stddev = sqrt(sumsqs / ((double) num_values - one));

}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//																			&
//				function : output_result									&
//				Author : Sunday Aduloju										&
//				Last Modified: 2/2/2018										&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//
// print the number of the floating point numbers
// print the mean of the set of numbers and standard deviation
//
void output_results( char title[], int num_values, double mean, double stddev, double values[] )
{
	int i;
	cout << endl << endl << endl << title << endl;
	cout<< endl << endl << " The number of floating point numbers read is:" << num_values << endl ;
	cout <<  " The mean of the set of numbers is:" << mean << endl;
	cout << " The standard deviation of the set of numbers is:" << stddev << endl;

	cout << "\n The input data are:" << endl;

	for ( i=0; i<num_values; i=i+1)
		{
			cout <<" " << values[i] << endl;
		}
}







