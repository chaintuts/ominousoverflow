/* This file contains code for a buffer overflow demo
*
* Author: Josh McIntyre
*/
#include <ominousoverflow.h>

/* This function shows us the secret if we're authenticated,
* otherwise an error message
*/
void output_secret(struct AuthUser* auth_user)
{
	if (auth_user -> authenticated)
	{
		printf("----------\nSecret key: %s\n----------\n", auth_user -> secret);
	}
	else
	{
		printf("----------\nError: not authorized to view secret\n----------\n");
	}
}

int main()
{
	/* Initialize a mock user account with some hard-coded demo values */
	struct AuthUser auth_user;
	
	auth_user.id = 1;
	strcpy(auth_user.secret, "KzEKhqNoWkTDGcv5CA9H9zyjJ7vRSWHZ3krSbbQNbqmxAeqoiFc1");
	strcpy(auth_user.credential, "abc123");
	auth_user.authenticated = 0;
	
	/* Get the password from the command line and authenticate */
	char credential_check[20];
	printf("Please enter your password: ");
	scanf("%s", credential_check);
	
	if (strcmp(credential_check, auth_user.credential) == 0)
	{
		printf("Passwords match\n");
	}
	else
	{
		printf("Incorrect password\n");
	}
	
	authenticate(&auth_user, credential_check);
	
	/* Output the secret if we're authorized */
	output_secret(&auth_user);
	
	return 0;
}
