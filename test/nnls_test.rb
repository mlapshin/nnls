require File.dirname(__FILE__) + "/test_helper"

class NnlsTest < Test::Unit::TestCase
  def test_nnls
    a = [0.5, 0.3, 0.2,
         0.2, 0.7, 0.8]

    b = [0.1, 0.1, 0.7]

    result = nil
    assert_nothing_raised do
      result = NNLS.nnls(a, b, 2, 3)
    end

    assert_equal Array, result[0].class
    assert_equal 3, result[0].size

    assert_equal Float, result[1].class
  end
end
