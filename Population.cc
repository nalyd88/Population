//
//  Population.cc
//  Population
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
//  MIT License
//
//  Copyright (C) 2013 Dylan Crocker
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this 
//  software and associated documentation files (the "Software"), to deal in the Software 
//  without restriction, including without limitation the rights to use, copy, modify, 
//  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to the following 
//  conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies 
//  or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
//  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
//  OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include "Population.h"
#include <math.h>
using namespace std;

namespace population
{

/******************************* Constructors *********************************/

Population::Population() 
{  
    vector<double> v;
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

double Population::median()
{
  // Do a couple checks first.
  if (entities.size() < 1)
    return 0;
  if (entities.size() < 2)
    return entities[0];

  // Create a copy of the population and sort it in ascending order.
  vector<double> copy(entities);
  sort(copy.begin(), copy.end());
  double median;
  
  // If the population has an even number of entities average the middle two values;
  // otherwise, return the entity in the middle.
  if (entities.size() % 2 == 0)
  {
    int index1 = static_cast<int>(entities.size()/2);
    median = (copy[index1] + copy[index1 - 1]) / 2;
  }
  else
  {
    // Determine the median index.
    int index = static_cast<int>(entities.size()/2);
    median = copy[index];
  }
  
  // Return the median value.
  return median;  
}

vector<double> Population::mode()
{ 
  // A population could have multiple modes, so return a vector.
  vector<double> modes;
  
  // Do a couple checks first.
  if (entities.size() < 1)
    return modes; // Empty vector
  if (entities.size() < 2)
    return entities; // One element vector - so it is the return value...

  // Create a copy of the population and sort it in ascending order.
  vector<double> copy(entities);
  sort(copy.begin(), copy.end());
  
  int streak = 0;
  int count = 0;
  double value = copy[0]; // Initialize to first item.
  for (unsigned int i = 0; i < copy.size(); i++)
  {
    if (value == copy[i])
    {
      count++;
    }
    else
    {
      // New value found so start over counting.
      value = copy[i];
      count = 1;
    }
    
    // Possibly found multiple modes.
    if (count == streak)
      modes.push_back(value);
    
    if (count > streak)
    {
      // So this value has been found more than any others. Start over with modes.
      modes.clear();
      modes.push_back(value);
      streak = count;
    }
  }
  
  // Return the modes.
  return modes;  
}

double Population::stddev()
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

void Population::remove_element(unsigned index)
{
  entities.erase (entities.begin() + index);
}

} // end namespace