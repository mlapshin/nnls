require File.dirname(__FILE__) + "/nnls.so"

A = [0.5, 0.3, 0.2,
     0.2, 0.7, 0.8]

B = [0.1, 0.1, 0.7]

puts NNLS._nnls(A, B, 3, 2).inspect
