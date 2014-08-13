classdef classB < cppinterface
    
    properties 
        
    end
    
    methods
        
        function this = classB()
            % call the constructor for the parent cppinterface class with
            % the mex function for the qucs analysis to be performed
            this = this@cppinterface (@classB_mex);
        end
        
        function useclassA(this, theclassA)
            this.cppcall ('useclassA', theclassA.objectHandle); 
        end
        
        function sety(this, y)
            this.cppcall ('sety', y); 
        end
        
        function printy(this)
            this.cppcall ('printy'); 
        end
        
    end 
    
end