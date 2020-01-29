#include <functional>
#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <vector>

PYBIND11_MAKE_OPAQUE(std::vector<int>);

using namespace std;

void backend(vector<int>& result, std::function<void (int, int&)>& callback)
{
	for (int i = 0; i < result.size(); i++)
		callback(i, result[i]);
}

PYBIND11_MODULE(python_tbb, m)
{
	pybind11::bind_vector<std::vector<int> >(m, "stdvectorint");

	m.def("backend", &backend, "backend");
}

