% test_class_passing.m

classa1 = classA (); 
classa2 = classA ();

classa1.printx ();
classa2.printx ();

classa1.setx (1);
classa2.setx (2);

classa1.printx ();
classa2.printx ();


classa1.useother (classa2);
classa1.useother (classa1);
classa2.useother (classa1);
classa2.useother (classa2);

%%

classa1 = classA ();

classb1 = classB ();

classa1.setx (1);
classb1.sety (2);

classb1.useclassA (classa1);


