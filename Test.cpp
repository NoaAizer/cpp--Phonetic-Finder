#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "band happy pe bump";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "be") == string("pe"));
    CHECK(find(text, "pand") == string("band"));
    CHECK(find(text, "band") == string("band"));
    CHECK(find(text, "bump") == string("bump"));
    CHECK(find(text, "pump") == string("bump"));
    CHECK(find(text, "bumb") == string("bump"));
    CHECK(find(text, "pumb") == string("bump"));
  

}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Dond Happi be WORRY";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "Be") == string("be"));
    CHECK(find(text, "BE") == string("be"));
    CHECK(find(text, "bE") == string("be"));
    CHECK(find(text, "worry") == string("WORRY"));
    CHECK(find(text, "Worry") == string("WORRY"));
    CHECK(find(text, "dont") == string("Dond"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "wave worry love";
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "vorry") == string("worry"));
    CHECK(find(text, "love") == string("love"));
    CHECK(find(text, "lowe") == string("love"));
    CHECK(find(text, "wave") == string("wave"));
    CHECK(find(text, "vave") == string("wave"));
    CHECK(find(text, "wawe") == string("wave"));
    CHECK(find(text, "vawe") == string("wave"));
   
}

TEST_CASE("Test replacement of b and f") {
    string text = "buffet ball first";
    CHECK(find(text, "ball") == string("ball"));
    CHECK(find(text, "fall") == string("ball"));
    CHECK(find(text, "first") == string("first"));
    CHECK(find(text, "birst") == string("first"));
    CHECK(find(text, "buffet") == string("buffet"));
    CHECK(find(text, "bubbet") == string("buffet"));
    CHECK(find(text, "fuffet") == string("buffet"));
    CHECK(find(text, "bufbet") == string("buffet"));
    CHECK(find(text, "bubfet") == string("buffet"));
    CHECK(find(text, "fubbet") == string("buffet"));
    CHECK(find(text, "fubfet") == string("buffet"));
    CHECK(find(text, "fufbet") == string("buffet"));
   
   
}
TEST_CASE("Test replacement of p and f") {
    string text = "pizza happy first flop";
    CHECK(find(text, "first") == string("first"));
    CHECK(find(text, "pirst") == string("first"));
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "pizza") == string("pizza"));
    CHECK(find(text, "fizza") == string("pizza"));
    CHECK(find(text, "flop") == string("flop"));
    CHECK(find(text, "flof") == string("flop"));
    CHECK(find(text, "plof") == string("flop"));
    CHECK(find(text, "plop") == string("flop"));
    
}

TEST_CASE("Test replacement of g and j") {
    string text = "juggling jump good";
    CHECK(find(text, "jump") == string("jump"));
    CHECK(find(text, "gump") == string("jump"));
    CHECK(find(text, "good") == string("good"));
    CHECK(find(text, "jood") == string("good"));
    CHECK(find(text, "juggling") == string("juggling"));
    CHECK(find(text, "guggling") == string("juggling"));
    CHECK(find(text, "jujjling") == string("juggling"));
    CHECK(find(text, "jujgling") == string("juggling"));
    CHECK(find(text, "jugjling") == string("juggling"));
    CHECK(find(text, "gujgling") == string("juggling"));
    CHECK(find(text, "gugjling") == string("juggling"));
    
}

TEST_CASE("Test replacement of c and k") {
    string text = "kind cook cry";
    CHECK(find(text, "kind") == string("kind"));
    CHECK(find(text, "cind") == string("kind"));
    CHECK(find(text, "cry") == string("cry"));
    CHECK(find(text, "kry") == string("cry"));
    CHECK(find(text, "cook") == string("cook"));
    CHECK(find(text, "kook") == string("cook"));
    CHECK(find(text, "cooc") == string("cook"));
    CHECK(find(text, "kooc") == string("cook"));
    
}

TEST_CASE("Test replacement of c and q") {
    string text = "icq cry queen";
    CHECK(find(text, "cry") == string("cry"));
    CHECK(find(text, "qry") == string("cry"));
    CHECK(find(text, "queen") == string("queen"));
    CHECK(find(text, "cueen") == string("queen"));
    CHECK(find(text, "icq") == string("icq"));
    CHECK(find(text, "iqc") == string("icq"));
    CHECK(find(text, "icc") == string("icq"));
    CHECK(find(text, "iqq") == string("icq"));

}

TEST_CASE("Test replacement of k and q") {
    string text = "queen kind quick";
    CHECK(find(text, "quick") == string("quick"));
    CHECK(find(text, "quicq") == string("quick"));
    CHECK(find(text, "kuick") == string("quick"));
    CHECK(find(text, "kuicq") == string("quick"));
    CHECK(find(text, "queen") == string("queen"));
    CHECK(find(text, "kueen") == string("queen"));
    CHECK(find(text, "qind") == string("kind"));
    CHECK(find(text, "kind") == string("kind"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "gas size zipper";
    CHECK(find(text, "size") == string("size"));
    CHECK(find(text, "sise") == string("size"));
    CHECK(find(text, "zise") == string("size"));
    CHECK(find(text, "zize") == string("size"));
    CHECK(find(text, "zipper") == string("zipper"));
    CHECK(find(text, "sipper") == string("zipper"));
    CHECK(find(text, "gas") == string("gas"));
    CHECK(find(text, "gaz") == string("gas"));
   
}

TEST_CASE("Test replacement of d and t") {
    string text = "tat dot tend";
    CHECK(find(text, "dot") == string("dot"));
    CHECK(find(text, "dod") == string("dot"));
    CHECK(find(text, "tot") == string("dot"));
    CHECK(find(text, "tod") == string("dot"));
    CHECK(find(text, "tat") == string("tat"));
    CHECK(find(text, "dad") == string("tat"));
    CHECK(find(text, "dat") == string("tat"));
    CHECK(find(text, "tat") == string("tat"));
    CHECK(find(text, "tend") == string("tend"));
    CHECK(find(text, "tent") == string("tend"));
    CHECK(find(text, "dend") == string("tend"));
    CHECK(find(text, "dent") == string("tend"));

    
}

TEST_CASE("Test replacement of o and u") {
    string text = "up soup cook";
    CHECK(find(text, "cook") == string("cook"));
    CHECK(find(text, "cuuk") == string("cook"));
    CHECK(find(text, "cuok") == string("cook"));
    CHECK(find(text, "couk") == string("cook"));
    CHECK(find(text, "soup") == string("soup"));
    CHECK(find(text, "suup") == string("soup"));
    CHECK(find(text, "suop") == string("soup"));
    CHECK(find(text, "soop") == string("soup"));
    CHECK(find(text, "up") == string("up"));
    CHECK(find(text, "op") == string("up"));
    
}

TEST_CASE("Test replacement of i and y") {
    string text = "history happy worri";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "happi") == string("happy"));
    CHECK(find(text, "worri") == string("worri"));
    CHECK(find(text, "worry") == string("worri"));
    CHECK(find(text, "history") == string("history"));
    CHECK(find(text, "histori") == string("history"));
    CHECK(find(text, "hystory") == string("history"));
    CHECK(find(text, "hystori") == string("history"));
}