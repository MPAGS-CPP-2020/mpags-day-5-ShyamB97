#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

VigenereCipher::VigenereCipher(const std::string& key)
{
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    //store the key
    _key = key;

    //make letters uppercase
    std::transform( std::begin(_key), std::end(_key), std::begin(_key), ::toupper);

    //remove non-alpha chars
    _key.erase( std::remove_if( std::begin(_key), std::end(_key), [](char c){ return !std::isalpha(c); } ), std::end(_key) );

    //if key is empy, replace with default
    if(_key == "")
    {
        _key = "KEY";
    }

    /* for each letter, initialize a CaesarCipher class 
       and assign the alphabet position as the key
       then create an element of the lookup table storing the letter and
       correspoonding CaesarCipher object and insert it.
    */
    for(char letter : _key)
    {
        int pos = Alphabet::alphabet.find(letter);
        CaesarCipher caesarCipher = CaesarCipher(pos);
        std::pair<char, CaesarCipher> lookUpElement = std::make_pair(letter, caesarCipher);
        _charLookUp.insert(lookUpElement);
    }
}

std::string VigenereCipher::applyCipher(const std::string& input, const CipherMode mode) const
{
    std::string outputText = "";
    for(size_t i = 0; i < input.size(); i++)
    {
        // get the relevant CaesarCipher class and truncate the key
        CaesarCipher caesarCipher = _charLookUp.at(_key[i%_key.size()]);
        
        // convert char to string
        std::string letter(1, input[i]);
        
        // apply CaesarCipher to the character, using relevant mode and add the output to the output text
        outputText += caesarCipher.applyCipher(letter, mode);
    }
    
    return outputText;
}