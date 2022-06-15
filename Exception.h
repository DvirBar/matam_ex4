#ifndef Exception_h
#define Exception_h

#include <exception>

class DeckFileNotFound: public std::exception {
    
};

class DeckFileFormatError: public std::exception {
public:
    DeckFileFormatError(int lineNumber);
    
private:
    int lineNumber;
};

class DeckFileInvalidSize: public std::exception {
    
};

class InvalidPlayer {};

#endif
