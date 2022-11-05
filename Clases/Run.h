#ifndef RUN_H
#define RUN_H

#include <iostream>

using namespace std;

class RUN
{
    private:
        long suRun;
        char dv;
    public:
        //Constructor
        RUN();
        RUN(long, char);

        //Sets
        void setRun(long x){suRun = x;}
        void setDv(char x){dv = x;}

        //Gets
        long getRun(){return suRun;}
        char getDv(){return dv;}

        void verRun();
};

#endif //RUN_H