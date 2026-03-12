#include <criterion/criterion.h>
#include "../cse_caesar.h"

Test(encryptCaesar, basic) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("abc", buf, 2);
    cr_expect_eq(r, 3);
    cr_expect_str_eq(buf, "ceg__EOM__");
}

Test(decryptCaesar, basic) {
    char buf[32] = "xxxxxxxx";
    int r = decryptCaesar("ceg__EOM__", buf, 2);
    cr_expect_eq(r, 3);
    cr_expect_str_eq(buf, "abc");
}

/*encrypt */

Test(encryptCaesar, empty_string) {
    char buf[32] = "xxxxxxxxxxxxxxxx";
    int r = encryptCaesar("", buf, 1);
    cr_expect_eq(r, 0);
    cr_expect_str_eq(buf, "__EOM__");
}

Test(encryptCaesar, uppercase_letters) {
    char buf[32] = "xxxxxxxxxxxxxxxx";
    int r = encryptCaesar("ABC", buf, 1);
    cr_expect_eq(r, 3);
}

Test(encryptCaesar, digits) {
    char buf[32] = "xxxxxxxxxxxxxxxx";
    int r = encryptCaesar("123", buf, 3);
    cr_expect_eq(r, 3);
}

Test(encryptCaesar, null_plaintext) {
    char buf[32] = "xxxxxxxxxxxxxxxx";
    int r = encryptCaesar(NULL, buf, 1);
    cr_expect_eq(r, -2);
}

/* decrypt */

Test(decryptCaesar, empty_plaintext_buffer) {
    char buf[1] = "";
    int r = decryptCaesar("abc__EOM__", buf, 2);
    cr_expect_eq(r, 0);
}

Test(decryptCaesar, digits) {
    char buf[32] = "xxxxxxxx";
    int r = decryptCaesar("357__EOM__", buf, 1);
    cr_expect_gt(r, 0);
}

Test(decryptCaesar, missing_eom) {
    char buf[32] = "xxxxxxxx";
    int r = decryptCaesar("abcdef", buf, 1);
    cr_expect_eq(r, -1);
}

Test(decryptCaesar, null_ciphertext) {
    char buf[32] = "xxxxxxxx";
    int r = decryptCaesar(NULL, buf, 1);
    cr_expect_eq(r, -2);
}