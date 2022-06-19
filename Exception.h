#ifndef Exception_h
#define Exception_h

#include <exception>
#include <string>


class DeckFileNotFound: public std::exception {
public:
    const char* what() const noexcept override {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError: public std::exception {
public:
    explicit DeckFileFormatError(int lineNumber) :
    m_error("Deck File Error: File format error in line " + std::to_string(lineNumber))
    { }

    const char* what() const noexcept override {
        return m_error.c_str();
    }
    
private:
    std::string m_error;
};

class DeckFileInvalidSize: public std::exception {
public:
    const char* what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};

class InvalidPlayer {};

#endif
