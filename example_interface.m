% EXAMPLE_INTERFACE Example MATLAB/Octave class wrapper to an underlying C++ class
classdef example_interface < cppinterface

    methods
        %% Constructor
        function this = example_interface()

            % initialise the cppinterface parent class by passing the 
            % mexfunction to the superclass constructor
            this = this@cppinterface(@class_interface_mex);

        end

        function train (this, x)
            this.cppcall ('train', x);
        end

        function x = test (this)
            x = this.cppcall ('test');
        end
        
    end

end
