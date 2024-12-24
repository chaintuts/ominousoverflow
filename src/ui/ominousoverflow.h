/* This file contains structs and function definitions for a simple buffer overflow. 
*
* Author: Josh McIntyre
*/
#include <stdio.h>
#include <string.h>

#include <overflowlib.h>

void output_secret(struct AuthUser*);