//
//  Population.h
//  CSLibrary
//
//  Created by Dylan Crocker on 6/15/12.
//  Copyright 2012 Creative Solutions. All rights reserved.
// 
//  Last edited by: DAC on: 6/15/12.
//
//  This objects represents a statistical population of numerical objects (int, char,
//  double, etc). There is currently no check for type compatibility.
//

#ifndef CSLIBRARY_CPP_STATISTICS_POPULATION_H
#define CSLIBRARY_CPP_STATISTICS_POPULATION_H

#include <algorithm>
#include <cmath>
#include <vector>

using std::vector;

template<typename T>
class Population
{
public:

  //
  // Constructors
  // 
  
  Population();
  explicit Population(T item);
  Population(int size, T inital);
  Population(int size, T* values);
  
  // 
  // Public Member Functions
  //
  
  // Adds and entity to the population.
  void add(T entity);
  
  // Returns the number of samples making up the population.
  int samples();
  
  // Returns the mean value of the population.
  double mean();
  
  // Returns the standard deviation of the population.
  double std_dev();
  
  // Returns the percentile specified by |percent| (double from 0.01 to 1.0). 
  T percentile(double percent);
  
  // Returns the population element at the specified index.
  T get_element(unsigned index);
  
private:
  
  vector<T> entities;
  
};

/******************************* Constructors *********************************/

template<typename T>
Population<T>::Population() 
{  
    vector<T> v;
    entities = v;
}

template<typename T>
Population<T>::Population(T item) 
{  
    vector<T> v(1, item);
    entities = v; 
}

template<typename T>
Population<T>::Population(int size, T inital) 
{  
    vector<T> v(size,inital);
    entities = v;
}

template<typename T>
Population<T>::Population(int size, T* values) 
{  
    vector<T> v(values, values + size);
    entities = v;
}

/*********************** Public Member Functions ******************************/

template<typename T>
void Population<T>::add(T entity)
{
  entities.push_back(entity);
}

template<typename T>
int Population<T>::samples()
{
  return (int)entities.size();
}

template<typename T>
double Population<T>::mean()
{
  double mean = 0;
  for (unsigned i = 0; i < entities.size(); i++)
  {
    mean += entities[i];
  }
  return mean/entities.size();
}

template<typename T>
double Population<T>::std_dev()
{
  T sum = 0;
  T sqrsum = 0;
  unsigned samples = entities.size();
  for (unsigned i = 0; i < samples; i++)
  {
    sum += entities[i];
    sqrsum += (entities[i]*entities[i]);
  }
  return sqrt(sqrsum/samples-pow((double)sum/samples,2));
}

template<typename T>
T Population<T>::percentile(double percent)
{
  // Ensure the desired percentile makes sense.
  if(percent < 0.01)
    percent = 0.01;
  if(percent > 1.0)
    percent = 1.0;
  
  // Create a copy of the population and sort it in ascending order.
  vector<T> copy(entities);
  sort(copy.begin(), copy.end());
  
  // Determine the desired percentile's index.
  int index = static_cast<int>(entities.size()*percent-1);
  
  // Return the desired percentile.
  return copy[index];  
}

template<typename T>
T Population<T>::get_element(unsigned index)
{
  if (index > entities.size())
    return 0;
    
  return entities[index];
}

#endif