Non-negative Least Square Algorithm
===================

It's a C. Lawson and R. Hanson Fortran 77 code published in
["Solving Least Squares Problems"](http://books.google.com/books?id=ROw4hU85nz8C&lpg=PA261&ots=mj7CFK4GNo&dq=mda%20is%20the%20first%20dimensioning%20parameter&pg=PP1#v=onepage&q&f=false) translated to C code and binded to Ruby.

Usage
----------

    $ gem install nnls

    a = [0.5, 0.3, 0.2,
         0.2, 0.7, 0.8]

    b = [0.1, 0.1, 0.7]

    result = NNLS.nnls(a, b, 2, 3)
    => [[0.05263157894736844, 0.0, 0.10526315789473684], 0.0]

License
----------

This gem is distributed under MIT license.