/*****************************************************************************************************************
 Copyright 2018 ARI. All rights reserved.
------------------------------------------------------------------------------------------------------------------
File name: json_wrapper.h

Description: This file contains the public and private interfaces for the CANOPEN functionality.
*****************************************************************************************************************/
#ifndef __JSON_WRAPPER_H__
#define __JSON_WRAPPER_H__

/*****************************************************************************************************************
-- #Include's --
*****************************************************************************************************************/
#include <iostream>
#include <map>
#include <fstream>
#include "json.h"	
extern "C" {
#endif

using namespace std;

/*****************************************************************************************************************
** -- #Define, Struct's, Typedef's, Enum's --
*****************************************************************************************************************/

struct JSON_J1939_SPN
{

	unsigned int GUID;				/* Defined by ACL layer */
	unsigned char Type;	  			/* 0 - SPN */
	string  Description;		/* Description */ 
	string  Units;				/* Units */
	char  Byte_Offset;				/* Byte_Offset */
	char  Bit_Offset;					/* Bit_Offset */ 
	char  Number_of_Bits;			/* Number_of_Bits */
	double  Units_Per_Bit;			/* Units_Per_Bit */
	double  Units_Offset;			/* Units_Offset */
	short  Minimum;					/* Minimum */
	short  Maximum;					/* Maximum */
	int Min_Warning;					/* Min_Warning */
	int Max_Warning;					/* Max_Warning */
	int Min_Error;						/* Min_Error */
	int Max_Error;						/* Max_Error */
	unsigned char Num_digits; 		/* Number of digits after decimal point */
	map <unsigned short,string > status_conv;	/* status conversion */
};

struct JSON_J1939_PGN
{
	unsigned char CAN_Port; 		/* CAN Port Number */
	unsigned int PGN;      			/* PGN Number */
	unsigned char spn_count;		/* count of spn */
	unsigned char priority;  		/* Priotity if Applicable */
	unsigned short period; 			/* Periodicity if Applicable */
	unsigned char addr;  			/* Address to be configure */
	unsigned char msg_length;  	/* Size of the PGN */
	unsigned short missed_pgn_count;   	/* missed pgn count if applicable */
	map<unsigned int, JSON_J1939_SPN> spn_map;	/* SPN map */
};

map<unsigned int, JSON_J1939_PGN> RX_PGN;		///final map....


typedef map<unsigned int, JSON_J1939_SPN> json_j1939_spn_map_t; /////spn map (first arg is GUID and second is SPN structure).
typedef map<unsigned int, JSON_J1939_PGN> json_j1939_pgn_map_t; /////pgn map (first arg is PGN and second is SPN structure ).


/*****************************************************************************************************************
CanariJsonManager is abstract base class. JSON contains single this base class.
*****************************************************************************************************************/
class CanariJsonManager
{
	public:
		bool ParseJson(ifstream& jsonString);
		json_j1939_spn_map_t GetFullStructure();
	private:
		void global_spn_mapdata(struct JSON_J1939_SPN spn_var);
		void global_pgn_mapdata(struct JSON_J1939_PGN spn_var);
	
};

#ifdef __cplusplus 
}
#endif

