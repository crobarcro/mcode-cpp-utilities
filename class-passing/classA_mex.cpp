#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <typeinfo>
#include "mex.h"
#include "../class_handle.hpp"
#include "classA.h"

using namespace std;

// Value-Defintions of the different class methods available
enum ClassMethods { evNotDefined,
                    useother, 
                    setx,
                    printx
                  };

// Map to associate the command strings with the class
// method enum values
std::map<std::string, ClassMethods> s_mapClassMethodStrs;

void Initialize()
{
    // Set up the class methods map
    s_mapClassMethodStrs["useother"] = useother;
    s_mapClassMethodStrs["setx"] = setx;
    s_mapClassMethodStrs["printx"] = printx;
}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    // Get the command string
    char cmd[128];

    Initialize();

    if (nrhs < 1 || mxGetString(prhs[0], cmd, sizeof(cmd)))
    {
        mexErrMsgTxt("First input should be a command string less than 128 characters long.");
    }

    // New
    if (!strcmp("new", cmd))
    {
        // Check parameters
        if (nlhs != 1)
            mexErrMsgTxt("New: One output expected.");
        // Return a handle to a new C++ instance
        plhs[0] = convertPtr2Mat<classA>(new classA);
        return;
    }

    // Check there is a second input, which should be the class instance handle
    if (nrhs < 2)
    {
        mexErrMsgTxt("Second input should be a class instance handle.");
    }

    // Delete
    if (!strcmp("delete", cmd))
    {
        // Destroy the C++ object
        destroyObject<classA>(prhs[1]);
        // Warn if other commands were ignored
        if (nlhs != 0 || nrhs != 2)
            mexWarnMsgTxt("Delete: Unexpected arguments ignored.");
        return;
    }

    // Get the class instance pointer from the second input
    classA *classA_instance = convertMat2Ptr<classA>(prhs[1]);

    // Call the various class methods
    // Switch on the value
    switch(s_mapClassMethodStrs[cmd])
    {
    case useother:
        classA_instance->useother (nlhs, plhs, nrhs, prhs);
        return;
    case setx:
        classA_instance->setx (nlhs, plhs, nrhs, prhs);
        return;
    case printx:
        classA_instance->printx ();
        return;
    default:
        mexErrMsgTxt("Unrecognised class command string.");
        break;
    }

}
