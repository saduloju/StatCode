
//Code written by Sunday Aduloju
//Submitted to Prof. Dodds
//for HW1 (CEE 691)

#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main ()
{
	const int max_values = 100;
	int i, j, num_values, nspace, lead_spaces;
	double values [max_values] , value, mean, sum, valuesqs [max_values] ,sumsqs, var,stddev;
	//vector<char> path;
const double dzero = 0.0, one = 1.0, two = 2.0;
char title[80];
ifstream data_file;

//
// open the input file. then check to see if it was opened ok.
// If not, quit...
//
data_file.open("input_1.txt");
if (data_file.fail())
{ 
	cout << "input file could not be opened\n" ;
	cout << "Job terminated ......\n";
	return(0);
}
//
// file opened ok. issue message to user.
// read first complete line of file into the 
//character vector
//
	cout << "File opened ok..." << endl ;
	cout << "Code written by Sunday Aduloju" << endl;
	cout << "Submitted to Prof. Dodds"	<< endl;
	cout << "for CEE 691 HW1 "<< endl;

	data_file.getline( title, 80, '\n');
//
// loop to read data values. each line has one

i = 0;
	while (true)
	{
		data_file >> value;
		if (data_file.eof()) break ;
		values [i] = value;
		i++;
	}
num_values = i;


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
cout << endl << endl << "The number of floating point numbers read is:" << num_values << endl ;
cout <<  "The mean of the set of numbers is:" << mean << endl;
cout << "The standard deviation of the set of numbers is:" << stddev << endl;

cout << "The input data are:" << endl;

for ( i=0; i<num_values; i=i+1)
	{
		cout << values[i] << endl;
	}




return 0;
}
//
