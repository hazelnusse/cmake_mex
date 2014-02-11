Simple example of how to make a Matlab mex file that uses the CMake build
system.

To build this example, do the following:

    $ mkdir build
    $ cmake ..
    $ make

If this succeeds, you should be able to call add(x, y) from Matlab by changing
into the build directory and simply calling add:

    >> x = rand(10, 10);
    >> y = rand(10, 10);
    >> z = add(x, y)

