mcode-cpp-utilities
===================

Header file with C++ class wrapper and other related utilities for creating mex interfaces to C++ classes and functions.

This submission expands on previous work done by Oliver Woodford on safely wrapping a persistent C++ object in a classdef wrapper. The supplied header file simplifies the creation of interfaces by providing some preprocessor macros, and a set of utility functions for performing argument checking, conversion between Matlab data types and std data types etc.

A base matlab class (cppinterface.m) is supplied to simplify the creation of your wrapper. This is intended to be subclassed by your classdef interface class.

An example is also provided of allowing two wrapped C++ object to communicate with each other directly through access to their pointers.

This code is offered under the GPLv2 licence, other licences may be made available on request.
