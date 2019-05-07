#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main(){

    ofstream influxTxt("data.txt");

    string measurement[3]={"temperature","air_pressure","used_energy"};
    string tagValue[3]={"machine_1","machine_2","machine_3"};
    string valueName[3]={"degrees","Pa","kW"};

    string line="",tag="machine";

    srand (time(NULL));
    

    if(influxTxt.is_open()){

        influxTxt<<"# DDL\nCREATE DATABASE factory\n\n# DML\n# CONTEXT-DATABASE: factory\n\n";

        //Temperature

        for(int i=0; i<2000000; i++){
           for(int j=0; j<3; j++){

              line=measurement[0]+","+tag+"="+tagValue[j]+" "+valueName[0]+"="+ to_string(rand()%250)+" "+to_string(1556496000+i)+"\n";

              influxTxt<<line;

           }
        }

        //Air pressure


        for(int i=0; i<2000000; i++){
           for(int j=0; j<3; j++){
 
              line=measurement[1]+","+tag+"="+tagValue[j]+" "+valueName[1]+"="+ to_string(rand()%1000)+" "+to_string(1556496000+i)+"\n";

              influxTxt<<line;
           }
        }

        //Energy

        for(int i=0; i<2000000; i++){
           for(int j=0; j<3; j++){
 
              line=measurement[2]+","+tag+"="+tagValue[j]+" "+valueName[2]+"="+ to_string(rand()%1000 + 100)+" "+to_string(1556496000+i)+"\n";

              influxTxt<<line;
           }
        }

        influxTxt.close();

    }else cout<<"Couldn´t open file\n";
    

    return 0;
}