## General
____________

### Author
* Josh McIntyre

### Website
* jmcintyre.net

### Overview
* OminousOverflow is a demo of a buffer overflow privilege escalation vulnerability

## Development
________________

### Git Workflow
* development for bugfixes and new features

### Building
* make build
Build the utility
* make Tests
Build the unit tests
* make clean
Clean the build directory

### Features
* Demonstrate a privilege escalation vulnerability via a buffer overflow
* Shows a secret value if password is correct, or if vulnerability is triggered
* This is done via a password input - correct password is "abc123"
* Incorrect password below 8 characters will reject user
* Incorrect password above 8 characters (8-22 characters) will trigger the vulnerability, authenticating user and showing the secret
* Use password of 8-22 characters for best results, seeing the secret. Longer will also overwrite the secret buffer. 

### Requirements
* Requires a terminal emulator

### Platforms
* Windows
* Linux
* MacOSX

## Usage
____________

### CLI Usage
* Run `ominousoverflow.exe` and enter password
* Enter password via command-line input - correct password is "abc123"
* Incorrect password below 8 characters will reject user
* Incorrect password above 8 characters (8-22 characters) will trigger the vulnerability, authenticating user and showing the secret
* Use password of 8-22 characters for best results, seeing the secret. Longer will also overwrite the secret buffer. 

### Tests
* Run `test_ominousoverflow.exe` to run unit tests
