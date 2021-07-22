# Parallel: Host Accessor Waits for Asynchronous Kernel Execution (DPC++)

Using Intel's oneAPI DPC++.  The kernel function invoked by a command group submitted to a queue will execute asynchronously.  By contrast, the host call to submit the command group returns immediately.  One way to make the host wait for kernel execution to complete is for the host to acquire a host_accessor to a buffer used by the kernel.

Linux distro "Pop!_OS 21.04"

cmake version 3.18.4

Intel(R) oneAPI DPC++/C++ Compiler 2021.3.0 (2021.3.0.20210619)

## Steps

*I placed this in my .bashrc file so the dpcpp compiler can be found.*

> *export ONEAPI_DIR="/opt/intel/oneapi"*

> *[ -s "$ONEAPI_DIR/setvars.sh" ] && \. "$ONEAPI_DIR/setvars.sh"  # initialize oneAPI environment*

cd oneapi

./build.sh

./build/host-accessor-waits-for-asynchronous-kernel-execution

## History

dates: 21 - 22, 2021

duration: 2 hours

### Code from Another Developer

This code came directly from Intel.

[oneAPI Base Training Module 2: DPC++ Program Structure](https://devcloud.intel.com/oneapi/get_started/baseTrainingModules/)

I modified the original Intel code to output start/in/done logging to see clearly the execution order of host and accelerator code.

Rod Burns posted about how to add logging to a kernel function.

[Add Kernel Logging](https://stackoverflow.com/questions/59064283/how-to-print-inside-sycl-parallel-for-kernel)

## Output

[Output](https://github.com/TallDave67/parallel-host-accessor-waits-for-asynchronous-kernel-execution/blob/main/oneapi/output.txt)
