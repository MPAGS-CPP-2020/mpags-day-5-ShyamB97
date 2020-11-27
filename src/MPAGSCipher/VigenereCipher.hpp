#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include <map>
#include <string>

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */
class VigenereCipher
{
private:
    /// The cipher key, essentially each letter represents the amount to shift a corresponding input letter by.
    std::string _key {""};

    /// Stores the CaesarCipher class for each letter in the key
    std::map<char, CaesarCipher> _charLookUp;

public:
    /**
     * Create a new CaesarCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit VigenereCipher( const std::string& key);

    /**
     * converts \param key into the appropriate format, 
     * then assigns a CaesarCipher class to each letter where the caesar-key for
     * a single CasesarCipher class is the letter's position in the alphabet.
     * Then stores the key and CaesarCipher class as in \param _charLookUp.
     */
    void setKey(const std::string& key);

    /**
     * Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText, const CipherMode& cipherMode) const;
};



#endif