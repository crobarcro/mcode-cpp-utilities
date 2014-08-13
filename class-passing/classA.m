classdef classA < cppinterface
    
    properties 
        
    end
    
    methods
        
        function this = classA()
            % call the constructor for the parent cppinterface class with
            % the mex function for the qucs analysis to be performed
            this = this@cppinterface (@classA_mex);
        end
        
        function useother(this, other)
            this.cppcall ('useother', other.objectHandle); 
        end
        
        function setx(this, x)
            this.cppcall ('setx', x); 
        end
        
        function printx(this)
            this.cppcall ('printx'); 
        end
        
    end 
    
end