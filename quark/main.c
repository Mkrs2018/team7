/*
   Quark reference C implementation

   Copyright (c) 2010-2014 Jean-Philippe Aumasson <jeanphilippe.aumasson@gmail.com>

   To the extent possible under law, the author(s) have dedicated all copyright
   and related and neighboring rights to this software to the public domain
   worldwide. This software is distributed without any warranty.

   You should have received a copy of the CC0 Public Domain Dedication along with
   this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint64_t u64;
typedef uint8_t u8;

int quark( u8 *out, const u8 *in, u64 inlen );

#define MAXDIGEST 48

int test_vectors()
{
  u8 out[MAXDIGEST];

#if   defined(UQUARK)
  const u8 digest_empty[] =
  {
    0x12,0x6b,0x75,0xbc,0xab,0x23,0x14,0x47,
    0x50,0xd0,0x8b,0xa3,0x13,0xbb,0xd8,0x00,
    0xa4
  };
  const char prefix='u';
#elif defined(DQUARK)
  const u8 digest_empty[] =
  {
    0x82,0xc7,0xf3,0x80,0xe2,0x31,0x57,0x8e,
    0x2f,0xf4,0xc2,0xa4,0x02,0xe1,0x8b,0xf3,
    0x7a,0xea,0x84,0x77,0x29,0x8d
  };
  const char prefix='d';
#elif defined(SQUARK)
  const u8 digest_empty[] =
  {
    0x03,0x25,0x62,0x14,0xb9,0x2e,0x81,0x1c,
    0x32,0x1a,0xe8,0x6b,0xab,0x4b,0x0e,0x7a,
    0xe9,0xc2,0x2c,0x42,0x88,0x2f,0xcc,0xde,
    0x8c,0x22,0xbf,0xf6,0xa0,0xa1,0xd6,0xf1
  };
  const char prefix='s';
#elif defined(CQUARK)
  const u8 digest_empty[] =
  {
    0x1c,0xb9,0x77,0x0e,0xe7,0xc2,0x5f,0xa9,
    0xdc,0xe2,0xc9,0x46,0x45,0x78,0x33,0x7c,
    0x69,0xc7,0xe2,0x6c,0xb4,0xf1,0xbd,0xf4,
    0x48,0x69,0xf1,0xa9,0x36,0x39,0xf1,0xf3,
    0x60,0xb8,0x88,0x97,0x5f,0xf9,0xff,0xee,
    0x88,0x0d,0x2c,0x49,0x91,0x08,0xa2,0x7a
  };
  const char prefix='c';
#endif

  printf( "%c-Quark\n", prefix );

  /* hash the empty string */
  quark( out, NULL, 0 );

  return memcmp( out, digest_empty, sizeof( digest_empty ) );

}

int main(int argc, char* argv[])
{
  // read the file
  if(argc > 1)
  {
    FILE *file_pointer;
    file_pointer = fopen(argv[1], "rb")
  }
  

  return 0;
}