AM_DEFAULT_SOURCE_EXT = .cpp
common_cxxflags = -I$(srcdir)/../../../../include
common_ldadd = $(builddir)/../../../../lib/libcfa.la

TESTS = calculator.test
check_PROGRAMS = $(TESTS)

calculator_test_LDADD = $(common_ldadd)
calculator_test_CXXFLAGS = $(common_cxxflags)
