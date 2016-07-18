AM_DEFAULT_SOURCE_EXT = .cpp
common_cxxflags = -I$(srcdir)/../../../../include
common_ldadd = $(builddir)/../../../../lib/libcfa.la

TESTS = base.test
check_PROGRAMS = $(TESTS)

base_test_LDADD = $(common_ldadd)
base_test_CXXFLAGS = $(common_cxxflags)
