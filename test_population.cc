// Code to test the Population utility.

#include "Population.h"
#include <cstdlib>
#include <iostream>

using namespace std;

#define ASIZE 10

// Main program entry point.
int main () 
{
  //int array[] = { 1,2,3,4,5,6,7,8,9,10 };
  double array[] = { 2,2,2,2,2,2,2,2,2,2 };
  
  Population pop1(ASIZE, array);
  cout << "Population #1: ";
  for(int i = 0; i < pop1.samples(); i++)
  {
    cout << pop1.get_element(i) << " ";
  }
  cout << endl;
  cout << "Population #1 samples = " << pop1.samples() << endl;
  cout << "Population #1 mean = " << pop1.mean() << endl;
  cout << "Population #1 std. dev. = " << pop1.std_dev() << endl;
  cout << "Population #1 90th percentile = " << pop1.percentile(0.9) << endl;
  
  Population pop2;
  for(int i = 1; i <= ASIZE; i++)
  {
    pop2.add(i);
  } 
  cout << "Population #2: ";
  for(int i = 0; i < pop2.samples(); i++)
  {
    cout << pop2.get_element(i) << " ";
  }
  cout << endl;
  cout << "Population #2 samples = " << pop2.samples() << endl;
  cout << "Population #2 mean = " << pop2.mean() << endl;
  cout << "Population #2 std. dev. = " << pop2.std_dev() << endl;
  cout << "Population #2 90th percentile = " << pop2.percentile(0.9) << endl;
  
  Population pop3(3.3);
  cout << "Population #3: ";
  for(int i = 0; i < pop3.samples(); i++)
  {
    cout << pop3.get_element(i) << " ";
  }
  cout << endl;
  
  Population pop4;
  srand ( time(NULL) ); /* initialize random seed: */
  for(int i = 1; i <= 100; i++)
  {
    pop4.add(rand() % 100 + 1);
  } 
  cout << "Population #4: ";
  for(int i = 0; i < pop4.samples(); i++)
  {
    cout << pop4.get_element(i) << " ";
  }
  cout << endl;
  cout << "Population #4 samples = " << pop4.samples() << endl;
  cout << "Population #4 mean = " << pop4.mean() << endl;
  cout << "Population #4 std. dev. = " << pop4.std_dev() << endl;
  cout << "Population #4 90th percentile = " << pop4.percentile(0.9) << endl;
  
  
  return 0;
}