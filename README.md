# News Reader with Atom and RSS Format support with TLS

Author: Vladislav Mikhed

## Description
A RSS reader has been implemented, which will output information to users from sources downloaded.
The reader supports RSS 2.0 and Atom formats.
## Poznamky
For compiling and running the project, it is necessary to use the openSSL library and the pkg-config tool. 
## Compilation
A Makefile is provided for compilation. To compile, use the command:
```
make
```
### Testing
```
make test
```


## Execution
```
./feadreader <url addresa | -f <feedfile>> [-c <certfile>] [-C <certaddr>] [-T] [-a] [-u]
```
| Arguments | Description |
|---|---|
| url | the address of the source from which information will be received for the program output |
| -f <feedfile> | path to the feedfile file. The file must contain individual sources, each source on a separate line, so there is a possibility of comments, a line with a comment must start with #|
| -c <certfile> | path to the certificate that will be used for server verification
| -C <certaddr> | path to the certificate store, which can be used for server verification
| -T| for each record, the publication time or modification time will be displayed
| -a | for each record, the author will be displayed
| -u |for each record, the associated url will be displayed
| -h | prints usage instructions for the program

One of the parameters url or feedfile must be specified.
Parameters must be separated by spaces.

## Example
```
./feedreader 'https://what-if.xkcd.com/feed.atom' -u -T -a
```


## File List
- ./Connect.cpp  
- ./Connect.h  
- ./Error.cpp  
- ./Error.h  
- ./feedfile  
- ./FeedReader.cpp  
- ./FeedReader.h  
- ./main.cpp  
- ./ParseArguments.cpp  
- ./ParseArguments.h     
- ./UrlParser.cpp  
- ./UrlParser.h  
- ./XMLParser.cpp  
- ./XMLParser.h  
- ./test/complex/test.py  
- ./test/unit/Error.cpp  
- ./test/unit/test.cpp  
- ./test/unit/TestArgumentParser.cpp  
- ./test/unit/TestArgumentParser.h  
- ./test/unit/TestConnect.cpp  
- ./test/unit/TestConnect.h  
- ./test/unit/TestUrlParser.cpp  
- ./test/unit/TestUrlParser.h  
- ./test/unit/UnitTests.cpp  
- ./test/unit/UnitTests.h  
- ./test/feedlist  
- ./README  
- ./manual.pdf
- ./Makefile 