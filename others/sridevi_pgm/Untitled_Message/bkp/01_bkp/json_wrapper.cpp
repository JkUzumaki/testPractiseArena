/*****************************************************************************************************************
Copyright 2018 ARI. All rights reserved.

FILE NAME: json_wrapper.cpp
Description: This file contains the operations of JSON Parasing and registring it's data into PGN structure.

*****************************************************************************************************************/

/*****************************************************************************************************************
-- #Include's --
*****************************************************************************************************************/
#include "json_wrapper.h"
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include<jsoncpp/json/json.h>
//#include<json/value.h>
using namespace std;

int main()
{
//ifstream ifs("application.json", ifstream::binary);
ifstream ifs("application.json");
/*ifs >> application;
cout << "application " << application << endl;
cout << "application [Canaria] " << application[Canaria] << "\n";
*/
Json::Reader reader;
Json::Value obj;
reader.parse(ifs, obj); // Reader can also read strings
cout << obj ;
//cout << "Last name: " << obj["GUID"].asString() << endl;
//cout << "First name: " << obj["Bit_Offset"].asString() << endl;
return 1;



}


//using namespace std;

/*void CanariJsonManager::global_spn_mapdata(struct JSON_J1939_SPN spn_var)
{
	///fill the global spn map
}
void CanariJsonManager::global_pgn_mapdata(struct JSON_J1939_PGN spn_var)
{
	///fill the global pgn map
	///don't forget, PGN structure contains SPN map, we need to get the data from  json_j1939_spn_map_t(SPN map)
}

json_j1939_pgn_map_t CanariJsonManager::GetFullStructure()
{
	///when we call this function need to return PGN map.....it is input to data_processing layer
}*/

bool CanariJsonManager::ParseJson(ifstream& jsonString)
{
	///Parse the json file and fill the structure's (JSON_J1939_PGN and JSON_J1939_SPN).
	///call the function global_spn_mapdata() to store the structures into the map.
	///call the function global_pgn_mapdata() to store the structures into the map.
	
	///if parse is success return trure or return false if parse fails.
	//JSON_J1939_SPN.GUID = 1001; 
	/*s1.GUID = 1001; 
        s1.Type =0;
        s1.Description="Driver's Demand Engine Pct Torque";
        s1.Units="%";
        s1.Byte_Offset=1;
        s1.Bit_Offset=0;
        s1.Number_of_Bits=8;
        s1.Units_Per_Bit=1;
        s1.Units_Offset=-125;
        s1.Minimum=-125;
        s1.Maximum=125;
        s1.Min_Warning=-50;
        s1.Max_Warning=90;
        s1.Min_Error=-100;
        s1.Max_Error=100;
        s1.Num_digits= 8;
        s1.status_conv=NULL;
        s2.CAN_Port=1;
        s2.PGN= 61444;
        s2.spn_count=3;
        s2.priority=6;
        s2.period=10;
        s2.addr=255;
        s2.msg_length=8;
        s2.spn_map */
  //      s1.SPN;
    //    s2.RX_PGN;
      
  
         
            

}



