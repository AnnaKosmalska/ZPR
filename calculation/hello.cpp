#include <cstdlib>
#include <iostream>
#include <boost/python.hpp>


std::string initGame()
{
    /* starting game*/
	return "Rozpoczynam grę";
}

std::string login()
{
    /*login player*/
	return "Loguję gracza";
}
BOOST_PYTHON_MODULE(hello)
{
	boost::python::def("initGame", initGame);
	boost::python::def("login", login);
}
