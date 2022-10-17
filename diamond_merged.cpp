/*
 * Copyright 2021 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "diamond.h"

void diamond(data_t vecIn[N], data_t vecOut[N])
{
  data_t c1[N], c2[N], c3[N], c4[N];
#pragma HLS dataflow
  funcA(vecIn, c1, vecOut);
}

void funcA(hls::stream<data_t> *in, hls::stream<data_t> *out)
{
Loop0:
  for (int i = 0; i < N; i++)
  {
#pragma HLS pipeline rewind //rewind shall only appear at the top level set II = 1?
#pragma HLS unroll factor = 2
    data_t t = in[i] * 3;
    //out1[i] = t;
    //out2[i] = t;
    data_t tb_in = t;
    data_t tc_in = t;

    data_t tb_out = tb_in + 25;
    data_t tc_out = tc_in * 2;
    out[i] = tb_out + tc_out * 2;
;  }
}
/*
void funcB(data_t *in, data_t *out)
{
Loop0:
  for (int i = 0; i < N; i++)
  {
#pragma HLS pipeline rewind
#pragma HLS unroll factor = 2
    out[i] = in[i] + 25;
  }
}

void funcC(data_t *in, data_t *out)
{
Loop0:
  for (data_t i = 0; i < N; i++)
  {
#pragma HLS pipeline rewind
#pragma HLS unroll factor = 2
    out[i] = in[i] * 2;
  }
}

void funcD(data_t *in1, data_t *in2, data_t *out)
{
Loop0:
  for (int i = 0; i < N; i++)
  {
#pragma HLS pipeline rewind
#pragma HLS unroll factor = 2
    out[i] = in1[i] + in2[i] * 2;
  }
}
*/