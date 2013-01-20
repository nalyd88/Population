//
//  Population.h
//  CSLibrary
//
//  Created by Dylan Crocker on 6/15/12.
//  Copyright 2012 Creative Solutions. All rights reserved.
// 
//  Last edited by: DAC on: 6/15/12.
//
//  This objects represents a statistical population of numerical values represented as
//  double precision values. This can be used with any numerical data type since there is
//  no loss of data when converting to a double.
//

#ifndef CSLIBRARY_CPP_STATISTICS_POPULATION_H
#define CSLIBRARY_CPP_STATISTICS_POPULATION_H

#include <algorithm>
#include <vector>
#include <cmath>

using std::vector;

class Population
{

public:

  //
  // Constructors
  // 
  
  Population();
  explicit Population(double item);
  Population(int size, double inital);
  Population(int size, double* values);
  
  // 
  // Public Member Functions
  //
  
  // Adds and entity to the population.
  void add(double entity);
  
  // Returns the number of samples making up the population.
  int samples();
  
  // Returns the mean value of the population.
  double mean();
  
  // Returns the median value of the population.
  double median();
  
  // Returns the standard deviation of the population.
  double std_dev();
  
  // Returns the percentile specified by |percent| (double from 0.01 to 1.0). 
  double percentile(double percent);
  
  // Returns the population element at the specified index.
  double get_element(unsigned index);
  
private:
  
  vector<double> entities;
  
};

#endif