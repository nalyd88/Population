//
//  Population.cpp
//  CSLibrary
//
//  Created by Dylan Crocker on 1/19/13.
//  Copyright 2012 Creative Solutions. All rights reserved.
// 
//  Last edited by: DAC on: 1/19/13.
//
//  This objects represents a statistical population of numerical values represented as
//  double precision values. This can be used with any numerical data type since there is
//  no loss of data when converting to a double.
//

#include "Population.h"
using namespace std;

/******************************* Constructors *********************************/

Population::Population() 
{  
    vector<double> v(100); // Start with space for 100 values.
    entities = v;
}

Population::Population(double item) 
{  
    vector<double> v(1, item);
    entities = v; 
}

Population::Population(int size, double inital) 
{  
    vector<double> v(size,inital);
    entities = v;
}

Population::Population(int size, double* values) 
{  
    vector<double> v(values, values + size);
    entities = v;
}

/*********************** Public Member Functions ******************************/

void Population::add(double entity)
{
  entities.push_back(entity);
}

int Population::samples()
{
  return (int)entities.size();
}

double Population::mean()
{
  double mean = 0;
  for (unsigned i = 0; i < entities.size(); i++)
  {
    mean += entities[i];
  }
  return mean/entities.size();
}

double Population::std_dev()
{
  double sum = 0;
  double sqrsum = 0;
  unsigned samples = entities.size();
  for (unsigned i = 0; i < samples; i++)
  {
    sum += (double)entities[i];
    sqrsum += (double)(entities[i]*entities[i]);
  }
  return sqrt(sqrsum/samples-pow(sum/samples,2));
}

double Population::percentile(double percent)
{
  // Ensure the desired percentile makes sense.
  if(percent < 0.01)
    percent = 0.01;
  if(percent > 1.0)
    percent = 1.0;
  
  // Create a copy of the population and sort it in ascending order.
  vector<double> copy(entities);
  sort(copy.begin(), copy.end());
  
  // Determine the desired percentile's index.
  int index = static_cast<int>(entities.size()*percent-1);
  
  // Return the desired percentile.
  return copy[index];  
}

double Population::get_element(unsigned index)
{
  if (index > entities.size())
    return 0;
    
  return entities[index];
}