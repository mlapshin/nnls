require 'nnls.so'

module NNLS
  def self.nnls(a, b, m, n)
    x, rnorm, status = self._nnls(a, b, m, n)

    case status
    when 2
      raise "The dimensions of the problem are bad (m = 0 or n = 0)"
    when 3
      raise "Iteration count exceeded (more than 3*n iterations)"
    end

    [x, rnorm]
  end
end
