#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the purely abstract base Cipher class
 */

/**
 * \class Cipher
 * \brief generic behaviour for types that represent a cipher
 */
class Cipher {
    public:
        Cipher() = default;  // allows creation of constructor
        Cipher(const Cipher& rhs) = default; // allows constructor to be made by cloning an existing one
        Cipher(Cipher&& rhs) = default; // allows constructor to be made by moving an existing one
        Cipher& operator=(const Cipher& rhs) = default; // allows constructor to be assigned by cloning an existing one
        Cipher& operator=(Cipher&& rhs) = default; // allows constructor to be assigned by moving an existing one
        virtual ~Cipher() = default; // destructor, cleans up resources allocated to memory when object is destroyed

        /**
         * Apply the cipher to the provided text
         *
         * \param inputText the text to encrypt or decrypt
         * \param cipherMode whether to encrypt or decrypt the input text
         * \return the result of applying the cipher to the input text
         */
        virtual std::string applyCipher(const std::string& input, const CipherMode mode) const = 0;
};

#endif