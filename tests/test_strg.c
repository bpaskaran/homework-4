#include <criterion/criterion.h>
#include "../strgPtr.h"


Test(strgLen, basic) {
    cr_expect_eq(strgLen("Stony Brook"), 11);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}

Test(strgCopy, truncation) {
    char d[5];
    strgCopy("Computer Science", d, 5);
    cr_expect_str_eq(d, "Comp");
}

Test(strgChangeCase, adjacency) {
    char s[] = "Stony Brook";
    strgChangeCase(s);
    cr_expect_str_eq(s, "sTONY bROOK");
}

Test(strgInterleave, priority) {
    char d[6];
    strgInterleave("abcdef", "12", d, 6);
    cr_expect_str_eq(d, "a1b2c");
}

/* strglen tests */

Test(strgLen, hello){ cr_expect_eq(strgLen("hello"),5); }
Test(strgLen, numbers){ cr_expect_eq(strgLen("12345"),5); }
Test(strgLen, space){ cr_expect_eq(strgLen(" "),1); }
Test(strgLen, two_spaces){ cr_expect_eq(strgLen("  "),2); }
Test(strgLen, symbols){ cr_expect_eq(strgLen("!@#"),3); }
Test(strgLen, mixed){ cr_expect_eq(strgLen("abc123"),6); }
Test(strgLen, single){ cr_expect_eq(strgLen("A"),1); }
Test(strgLen, long_word){ cr_expect_eq(strgLen("computer"),8); }
Test(strgLen, sentence){ cr_expect_eq(strgLen("hello world"),11); }

/* strgcopy tests  */

Test(strgCopy, exact_fit){
    char d[6];
    strgCopy("hello",d,6);
    cr_expect_str_eq(d,"hello");
}

Test(strgCopy, small_buffer){
    char d[4];
    strgCopy("hello",d,4);
    cr_expect_str_eq(d,"hel");
}

Test(strgCopy, empty_source){
    char d[5];
    strgCopy("",d,5);
    cr_expect_str_eq(d,"");
}

Test(strgCopy, single_char){
    char d[5];
    strgCopy("A",d,5);
    cr_expect_str_eq(d,"A");
}

Test(strgCopy, numbers){
    char d[10];
    strgCopy("12345",d,10);
    cr_expect_str_eq(d,"12345");
}

Test(strgCopy, symbols){
    char d[10];
    strgCopy("!@#",d,10);
    cr_expect_str_eq(d,"!@#");
}

Test(strgCopy, size_one){
    char d[1];
    strgCopy("hello",d,1);
    cr_expect_str_eq(d,"");
}

Test(strgCopy, phrase){
    char d[20];
    strgCopy("stony brook",d,20);
    cr_expect_str_eq(d,"stony brook");
}

Test(strgCopy, copy_two){
    char d[3];
    strgCopy("abcd",d,3);
    cr_expect_str_eq(d,"ab");
}

/* strgchangecase tests */

Test(strgChangeCase, hello){
    char s[]="Hello";
    strgChangeCase(s);
    cr_expect_str_eq(s,"hELLO");
}

Test(strgChangeCase, lowercase){
    char s[]="abc";
    strgChangeCase(s);
    cr_expect_str_eq(s,"ABC");
}

Test(strgChangeCase, uppercase){
    char s[]="ABC";
    strgChangeCase(s);
    cr_expect_str_eq(s,"abc");
}

Test(strgChangeCase, digits){
    char s[]="123";
    strgChangeCase(s);
    cr_expect_str_eq(s,"123");
}

Test(strgChangeCase, mixed){
    char s[]="AbCd";
    strgChangeCase(s);
    cr_expect_str_eq(s,"aBcD");
}

Test(strgChangeCase, symbol){
    char s[]="!@#";
    strgChangeCase(s);
    cr_expect_str_eq(s,"!@#");
}

Test(strgChangeCase, single){
    char s[]="A";
    strgChangeCase(s);
    cr_expect_str_eq(s,"a");
}

Test(strgChangeCase, word){
    char s[]="Brook";
    strgChangeCase(s);
    cr_expect_str_eq(s,"bROOK");
}

Test(strgChangeCase, two_letters){
    char s[]="Ab";
    strgChangeCase(s);
    cr_expect_str_eq(s,"aB");
}

/* strgdiff tests */

Test(strgDiff, identical){
    cr_expect_eq(strgDiff("abc","abc"),-1);
}

Test(strgDiff, first_diff){
    cr_expect_eq(strgDiff("abc","xbc"),0);
}

Test(strgDiff, middle_diff){
    cr_expect_eq(strgDiff("abc","axc"),1);
}

Test(strgDiff, last_diff){
    cr_expect_eq(strgDiff("abc","abd"),2);
}

Test(strgDiff, diff_length){
    cr_expect_eq(strgDiff("abc","abcd"),3);
}

Test(strgDiff, empty){
    cr_expect_eq(strgDiff("",""),-1);
}

Test(strgDiff, empty_vs_char){
    cr_expect_eq(strgDiff("","a"),0);
}

Test(strgDiff, char_vs_empty){
    cr_expect_eq(strgDiff("a",""),0);
}

Test(strgDiff, null_case){
    cr_expect_eq(strgDiff(NULL,"abc"),-2);
}

Test(strgDiff, null_case2){
    cr_expect_eq(strgDiff("abc",NULL),-2);
}

/* strginterleave tests */

Test(strgInterleave, simple){
    char d[10];
    strgInterleave("abc","123",d,10);
    cr_expect_str_eq(d,"a1b2c3");
}

Test(strgInterleave, second_short){
    char d[10];
    strgInterleave("abcd","12",d,10);
    cr_expect_str_eq(d,"a1b2cd");
}

Test(strgInterleave, first_empty){
    char d[10];
    strgInterleave("","123",d,10);
    cr_expect_str_eq(d,"123");
}

Test(strgInterleave, second_empty){
    char d[10];
    strgInterleave("abc","",d,10);
    cr_expect_str_eq(d,"abc");
}

Test(strgInterleave, small_buffer){
    char d[5];
    strgInterleave("abc","123",d,5);
    cr_expect_str_eq(d,"a1b2");
}

Test(strgInterleave, one_each){
    char d[5];
    strgInterleave("a","1",d,5);
    cr_expect_str_eq(d,"a1");
}

Test(strgInterleave, numbers_letters){
    char d[10];
    strgInterleave("12","ab",d,10);
    cr_expect_str_eq(d,"1a2b");
}

Test(strgInterleave, both_empty){
    char d[5];
    strgInterleave("","",d,5);
    cr_expect_str_eq(d,"");
}

Test(strgInterleave, long_first){
    char d[10];
    strgInterleave("abcde","1",d,10);
    cr_expect_str_eq(d,"a1bcde");
}

/* strgreverseletters tests*/

Test(strgReverseLetters, simple){
    char s[]="abc";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"cba");
}

Test(strgReverseLetters, four_letters){
    char s[]="abcd";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"dcba");
}

Test(strgReverseLetters, mixed_symbols){
    char s[]="a,b$c";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"c,b$a");
}

Test(strgReverseLetters, numbers){
    char s[]="ab12cd";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"dc12ba");
}

Test(strgReverseLetters, single){
    char s[]="a";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"a");
}

Test(strgReverseLetters, empty){
    char s[]="";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"");
}

Test(strgReverseLetters, symbols){
    char s[]="!@#";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"!@#");
}

Test(strgReverseLetters, letters_symbols){
    char s[]="ab!cd";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"dc!ba");
}

Test(strgReverseLetters, letters_numbers){
    char s[]="abc123";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"cba123");
}

Test(strgReverseLetters, two_letters){
    char s[]="ab";
    strgReverseLetters(s);
    cr_expect_str_eq(s,"ba");
}