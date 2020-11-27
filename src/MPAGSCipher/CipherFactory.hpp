#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP

#include <memory>
#include <string>
#include "Cipher.hpp"
#include "CipherType.hpp"


std::unique_ptr<Cipher> cipherFactory ( const CipherType cmd_type, const std::string key );

#endif