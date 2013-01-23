//
//  Population.h
//  Population
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

#ifndef CSLIBRARY_CPP_STATISTICS_POPULATION_H
#define CSLIBRARY_CPP_STATISTICS_POPULATION_H

#include <algorithm>
#include <vector>
#include <cmath>

using std::vector;

namespace population {

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
  
  // Returns the mode of the population. Populations may have multiple modes, therefore
  // the returned value is a vector.
  vector<double> mode();
  
  // Returns the standard deviation of the population.
  double stddev();
  
  // Returns the percentile specified by |percent| (double from 0.01 to 1.0). 
  double percentile(double percent);
  
  // Returns true if the population can be considered to be normally distributed within
  // the specified tolerance.
  // bool isnorm(double error);
  
  // Returns the population element at the specified index.
  double get_element(unsigned index);
  
  // Remove an element at the specified index.
  void remove_element(unsigned index);
  
private:
  
  vector<double> entities;
  
}; // end class header

}  // end namespace

#endif