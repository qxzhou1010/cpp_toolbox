#include "gtest/gtest.h"
#include <emp-tool/emp-tool.h>

using namespace emp;
namespace alltest {

namespace emptool {

TEST(EmpToolTest, Prg) {
  PRG prg; // using a secure random seed

  int rand_int, rand_ints[100];
  block rand_block[3];

  prg.random_data(&rand_int,
                  sizeof(rand_int)); // fill rand_int with 32 random bits
  prg.random_block(rand_block, 3);   // fill rand_block with 128*3 random bits

  prg.reseed(&rand_block[1]); // reset the seed and counter in prg
  prg.random_data_unaligned(
      rand_ints + 2, sizeof(int) * 98); // when the array is not 128-bit-aligned
}

// TEST(EmpToolTest, Prp) {
//   block key;
//   PRG().random_block(&key, 1);
//   PRP prp(key); // if no parameter is provided, a public, fixed key will be
//   used

//   block rand_block[3], b3[3];
//   int rand_ints[100];

//   prp.permute_block(rand_block, 3); // applying pi on each block of data
//   prp.permute_data(rand_ints, sizeof(int) * 100);

//   block b2 =
//       prp.H(rand_block[1],
//             1); // b2 = pi(r)\xor r, where r = doubling(random_block)\xor 1

//   prp.H<3>(b3, rand_block,
//            0); // apply the above H on three blocks using counter 0, 1, and
// }

// TEST(EmpToolTest, Hash) {
//   Hash hash;

//   //   char *data = new char[1024 * 1024], dig[Hash::DIGEST_SIZE];

//   //   hash.put(data, 1024 * 1024);
//   //   hash.digest(dig);
// }

TEST(EmpToolTest, Commitment) {

  Commitment c;

  char *data = new char[1024 * 1024];
  Com com;
  Decom decom;

  c.commit(decom, com, data,
           1024 * 1024); // commit, will fill values decom and com
  assert(c.open(decom, com, data,
                1024 * 1024)); // open, return if the decommitment is valid or
}

} // namespace emptool

} // namespace alltest