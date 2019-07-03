/*
 * Author: Aehjaj Ahmed P
 * Date: 2-July-2019
*/
#ifndef PARSER_H
#define PARSER_H

#include <array>
#include <iostream>

//This provides an interface to parse data from server
class Parser{
public:
   virtual bool parse(const std::array<char, 256>& received_buf, int size) = 0;
};


//Parses the data and outputs in standard output
class CoutParser : public Parser {
public:
   bool parse(const std::array<char, 256>& received_buf, int size)  {
       if( (size == 2) && (received_buf[0] == 'O' && received_buf[1] == 'K' ) ){
            std::cout << "Parser: ";
            std::cout.write(received_buf.data(), size);
       } else {
           std::cerr << "Parse error" << std::endl;
           return false;
       }
       return true;
   }
};
#endif