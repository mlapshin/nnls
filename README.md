Non-negative Less Square Algorithm
===================

It's a C. Lawson and R. Hanson Fortran 77 code published in
"Solving Least Squares Problems" translated to C code and binded to Ruby.

Usage
----------

    $ gem install nnls

    a = [0.5, 0.3, 0.2,
         0.2, 0.7, 0.8]

    b = [0.1, 0.1, 0.7]

    result = NNLS.nnls(a, b, 2, 3)
