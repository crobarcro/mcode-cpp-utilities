#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <typeinfo>
#include "mex.h"
#include "../class_handle.hpp"
#include "classB.h"

using namespace std;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    // Value-Defintions of the different class methods available
    enum ClassMethods { evNotDefined,
                        useclassA, 
                        sety,
                        printy
                      };
                  
    DECLARE_CLASS_MAP
    ADD_CLASS_METHOD_TO_MAP(useclassA)
    ADD_CLASS_METHOD_TO_MAP(sety)
    ADD_CLASS_METHOD_TO_MAP(printy)
    MEX_WRAPPER_START(classB)
    
    // Call the various class methods
    // Switch on the value
    switch(QUERY_CLASS_MAP)
    {
    case useclassA:
        classB_instance->useclassA (nlhs, plhs, nrhs, prhs);
        return;
    case sety:
        classB_instance->sety (nlhs, plhs, nrhs, prhs);
        return;
    case printy:
        classB_instance->printy ();
        return;
    default:
        mexErrMsgTxt("Unrecognised class command string.");
        break;
    }

}

