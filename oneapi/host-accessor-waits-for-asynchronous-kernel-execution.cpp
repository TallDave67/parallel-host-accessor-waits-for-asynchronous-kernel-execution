//==============================================================
// Copyright © 2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================

// The original Intel code has been modified by David Bellis in 2021


#include <CL/sycl.hpp>
using namespace sycl;

int main() {
  constexpr int N = 256;
  auto R = range<1>(N);
  std::vector<int> v(N, 10);
  //gpu_selector selector;
  cpu_selector selector;
  queue q(selector);
  // Buffer takes ownership of the data stored in vector.  
  buffer buf(v);
  std::cout << "start: q.submit" << std::endl;
  q.submit([&](handler& h) {
    accessor a(buf,h);
    std::cout << "start: h.parallel_for" << std::endl;
    sycl::stream out(65536, 64, h);
    h.parallel_for(R, [=](auto i) { a[i] -= 2; out << "in: h.parallel_for[" << i << "]" << cl::sycl::endl;});
    std::cout << "done: h.parallel_for" << std::endl;
  });
  std::cout << "done: q.submit" << std::endl;
  // Creating host accessor is a blocking call and will only return after all
  // enqueued DPC++ kernels that modify the same buffer in any queue completes
  // execution and the data is available to the host via this host accessor.
  std::cout << "start: raw output display" << std::endl;
  for (int i = 0; i < N; i++) std::cout << v[i] << " ";
  std::cout << std::endl;
  std::cout << "done: raw output display" << std::endl;
  std::cout << "start: host_accessor" << std::endl;
  host_accessor b(buf,read_only);
  std::cout << "done: host_accessor" << std::endl;
  std::cout << "start: accessor output display" << std::endl;
  for (int i = 0; i < N; i++) std::cout << b[i] << " ";
  std::cout << std::endl;
  std::cout << "done: accessor output display" << std::endl;
  return 0;
}
