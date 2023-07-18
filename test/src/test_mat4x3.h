/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#ifndef CGLM_TEST_MAT4X3_ONCE
#define CGLM_TEST_MAT4X3_ONCE

TEST_IMPL(MACRO_GLM_MAT4X3_ZERO_INIT) {
  mat4x3 mat4x3_zero = GLM_MAT4X3_ZERO_INIT;
  test_assert_mat4x3_eq_zero(mat4x3_zero);
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT4X3_ZERO) {
  mat4x3 mat4x3_zero = GLM_MAT4X3_ZERO;
  test_assert_mat4x3_eq_zero(mat4x3_zero);
  TEST_SUCCESS
}

#endif /* CGLM_TEST_MAT4X3_ONCE */

TEST_IMPL(GLM_PREFIX, mat4x3_make) {
  float src[36] = {
    0.5f, 1.7f, 10.3f, 4.2f, 8.9f, 1.1f, 2.3f, 4.2f, 5.3f, 4.8f, 96.3f, 13.7f,
    4.7f, 5.5f, 2.3f, 4.2f, 2.3f, 4.2f, 66.5f, 23.7f, 6.6f, 8.9f, 0.5f, 1.7f,
    5.3f, 4.8f, 96.3f, 13.7f, 4.7f, 5.5f, 2.3f, 4.2f, 0.5f, 1.7f, 10.3f, 4.2f
  };

  mat4x3 dest[3];

  float *srcp = src;
  unsigned int i, j, k;

  for (i = 0, j = 0, k = 0; i < sizeof(src) / sizeof(float); i+=12,j++) {
    GLM(mat4x3_make)(srcp + i, dest[j]);

    ASSERT(test_eq(src[ i ], dest[j][k][0]));
    ASSERT(test_eq(src[i+1], dest[j][k][1]));
    ASSERT(test_eq(src[i+2], dest[j][k][2]));

    ASSERT(test_eq(src[i+3], dest[j][k+1][0]));
    ASSERT(test_eq(src[i+4], dest[j][k+1][1]));
    ASSERT(test_eq(src[i+5], dest[j][k+1][2]));

    ASSERT(test_eq(src[i+6], dest[j][k+2][0]));
    ASSERT(test_eq(src[i+7], dest[j][k+2][1]));
    ASSERT(test_eq(src[i+8], dest[j][k+2][2]));

    ASSERT(test_eq(src[i+9], dest[j][k+3][0]));
    ASSERT(test_eq(src[i+10], dest[j][k+3][1]));
    ASSERT(test_eq(src[i+11], dest[j][k+3][2]));
  }

  TEST_SUCCESS
}