//! Unit Tests for objects of type Cipher
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CipherFactory.hpp"
#include "CipherType.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher(const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& expectedOutputText)
{
    std::string outputText = cipher.applyCipher(inputText, mode);

    return (expectedOutputText == outputText) ? true: false;
}

TEST_CASE("Caesar Cipher encryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN") == true);
}

TEST_CASE("Caesar Cipher decryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD") == true);
}

TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher pc{"hello"};
  REQUIRE( testCipher(pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") == true); 
}

TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher pc{"hello"};
  REQUIRE( testCipher(pc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") == true); 
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]")
{
  VigenereCipher vc{"key"};
  REQUIRE( testCipher(vc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN") == true);
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]")
{
  VigenereCipher vc{"key"};
  REQUIRE( testCipher(vc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD") == true);
}


TEST_CASE("cipher encryptions", "[cipher]")
{
  //Create a collection of cipher types
  std::vector<std::unique_ptr<Cipher> > inventory;
  inventory.push_back( cipherFactory(CipherType::Caesar, "10") );
  inventory.push_back( cipherFactory(CipherType::Playfair, "hello") );
  inventory.push_back( cipherFactory(CipherType::Vigenere, "key") );

  //Create a pair of inputs and outputs
  std::vector<std::pair<std::string, std::string> > io;
  io.push_back( std::make_pair("HELLOWORLD", "ROVVYGYBVN") );
  io.push_back( std::make_pair("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") );
  io.push_back( std::make_pair("HELLOWORLD", "RIJVSUYVJN") );

  for(size_t i = 0; i < inventory.size(); i++)
  {
    REQUIRE( inventory[i]->applyCipher(io[i].first, CipherMode::Encrypt) == io[i].second );
  }
}

TEST_CASE("cipher decryptions", "[cipher]")
{
  //Create a collection of cipher types
  std::vector<std::unique_ptr<Cipher> > inventory;
  inventory.push_back( cipherFactory(CipherType::Caesar, "10") );
  inventory.push_back( cipherFactory(CipherType::Playfair, "hello") );
  inventory.push_back( cipherFactory(CipherType::Vigenere, "key") );

  //Create a pair of inputs and outputs
  std::vector<std::pair<std::string, std::string> > io;
  io.push_back( std::make_pair("ROVVYGYBVN", "HELLOWORLD") );
  io.push_back( std::make_pair("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") );
  io.push_back( std::make_pair("RIJVSUYVJN", "HELLOWORLD") );

  for(size_t i = 0; i < inventory.size(); i++)
  {
    REQUIRE( inventory[i]->applyCipher(io[i].first, CipherMode::Decrypt) == io[i].second );
  }
}
