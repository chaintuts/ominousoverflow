/* This file contains structs and function definitions for a simple buffer overflow. 
*
* Author: Josh McIntyre
*/
#include <stdio.h>
#include <string.h>

struct AuthUser
{
		/* The user information */
		int id;
		char secret[53];
		char credential[9];

		/* Credential checking for authentication
		* This is the bad code we will exploit
		* strcpy-ing a password larger than 8 characters will 
		* overwrite the authenticated byte
		*/
		char credential_cached[8];
		short authenticated;
};

short authenticate(struct AuthUser* auth_user, char* credential_check);
