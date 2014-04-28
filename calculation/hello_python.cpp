#include "hello.h"

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(hello)
{
	boost::python::def("InitGame", Hello::InitGame);
	boost::python::def("logIn", Hello::LogIn);
}
