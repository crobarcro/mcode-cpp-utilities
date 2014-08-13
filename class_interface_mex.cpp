#include "mex.h"
#include "class_handle.hpp"

// A set of utility functions are provided in class_handle.hpp
// in the namespace mexutils. These can be to convert between 
// some matlab and std data types, and ease various tasks for 
// the mex interface
using namespace mexutils;

// The class that we are interfacing to, this class would likely be 
// defined elsewhere such as a library in ny real situation
class example
{
public:

    example () { _x = 0; }

    void train (int x) 
    {
        _x = x;
    }

    int test ()
    {
        return _x;
    }

private:

    int _x;

};


// wrapper class to convert matlab arguments to appropriate arguments
// for wrapped class
class example_wrapper
{
public:
    void train(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
    {   
        std::vector<int> nallowed;
        nallowed.push_back (1); // one argument must be supplied

        // check the number of args supplied. We use an offset of 2, as the class
        // interface always requires two arguements and we are only interested in the 
        // subsequent optional arguements
        int noffsetargs = mxnarginchk (nrhs, nallowed, 2);

        // get the input argument
        double input = mxnthargscalar (nrhs, prhs, 1, 2);

        // call the wrapped class's 'train' method
        ex.train ( int(input) );
    }

    void test(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
    {
        // return the value placed in _x
        mxSetLHS (ex.test (), 1, nlhs, plhs);
    }

private:

    // instance of the wrapped c++ class
    example ex;

};

// mexfunction defintion, all the interction with the class is done through
// this function
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{	
     // use the macros provided by class_handle.hpp to create the interface
     // these macros assume the wrapper class can be constructed without arguments.
     // Note that the instance of the wrapper class is declared with 'new' and
     // created on the heap
     BEGIN_MEX_CLASS_WRAPPER(example_wrapper)
       REGISTER_CLASS_METHOD(example_wrapper,train)
       REGISTER_CLASS_METHOD(example_wrapper,test)
     END_MEX_CLASS_WRAPPER(example_wrapper)
}


