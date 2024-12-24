/* This file contains simple unit tests for the ominousoverflow library
*
* Author: Josh McIntyre
*/
#include <overflowlib.h>
#include <test_ominousoverflow.h>

/* Test basic authentication */
int test_authenticate()
{
	/* Initialize a mock user account with some hard-coded demo values */
	struct AuthUser auth_user;
	
	auth_user.id = 1;
	strcpy(auth_user.secret, "KzEKhqNoWkTDGcv5CA9H9zyjJ7vRSWHZ3krSbbQNbqmxAeqoiFc1");
	strcpy(auth_user.credential, "abc123");
	auth_user.authenticated = 0;
	
	/* Test cases */
	int result = 0;

	/* First try the correct password */
	authenticate(&auth_user, "abc123");
	if (auth_user.authenticated != 1)
	{
		result = 1;
	}

	/* Next, an incorrect password within the length guidelines < 8 chars */
	authenticate(&auth_user, "wrong");
	if (auth_user.authenticated != 0)
	{
		result = 1;
	}

	printf("test_authenticate result: %d\n", result);
	return result;
}

/* Test the privilege escalation buffer overflow */
int test_authenticate_overflow()
{
	/* Initialize a mock user account with some hard-coded demo values */
	struct AuthUser auth_user;
	
	auth_user.id = 1;
	strcpy(auth_user.secret, "KzEKhqNoWkTDGcv5CA9H9zyjJ7vRSWHZ3krSbbQNbqmxAeqoiFc1");
	strcpy(auth_user.credential, "abc123");
	auth_user.authenticated = 0;
	
	/* Test cases */
	int result = 0;

	/* Try incorrect password that will overflow the character buffer
	* Password > 8 characters
	* This will result in the authenticate variable in the struct being overwritten 
	* with a nonzero value, thus giving a "true" value for authenticated.
	* This elevates privileges even with the correct password
	*/
	authenticate(&auth_user, "incorrect");
	if (auth_user.authenticated == 0)
	{
		result = 1;
	}

	printf("test_authenticate_overflow result: %d\n", result);
	return result;
}

/* The main entry point for the unit tests */
int main(int argc, char* argv[])
{
	int tests = 2;
	int results[2];

	int res_authenticate = test_authenticate();
	results[0] = res_authenticate;
	
	int res_authenticate_overflow = test_authenticate_overflow();
	results[1] = res_authenticate_overflow;
	
	int tests_passed = 0;
	int tests_failed = 0;
	for (int i = 0; i < tests; i++)
	{
		if (results[i] == 0)
		{
			tests_passed++;
		}
		else
		{
			tests_failed++;
		}
	}
	
	printf("-----\n");
	printf("Tests passed: %d\n", tests_passed);
	printf("Tests failed: %d\n", tests_failed);
	
	return 0;
}