/* This file contains code for a buffer overflow demo
*
* Author: Josh McIntyre
*/
#include <overflowlib.h>

/* This contains the overflow vulnerability
* Here, we'll check if the passwords match
* We'll set the "authenticated" byte to 1 if they do match (true)
* And set it to 0 (false) if they do not
* We'll then cache the password for user convenience so they only have to 
* enter their password once while using the program
*/
short authenticate(struct AuthUser* auth_user, char* credential_check)
{
	if (strcmp(credential_check, auth_user -> credential) == 0)
	{
		auth_user -> authenticated = 1;
	}
	else
	{
		auth_user -> authenticated = 0;
	}

	/* Uh-oh! This unsafe strcpy can overwrite the memory contents of the
	* adjacent variable in the AuthUser struct, which is `authenticated`
	* Since authenticated will now likely have a non-zero value, entering
	* an 8+ character incorrect password will still allow us to view the secret -
	* a privilege escalation buffer overflow attack!
	*/
	strcpy(auth_user -> credential_cached, credential_check);
}
