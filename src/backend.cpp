#include <functional>
#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <vector>

PYBIND11_MAKE_OPAQUE(std::vector<int>);

using namespace std;

vector<int> backend(int length, std::function<void (int, int, pybind11::object&)>& callback)
{
	vector<int> result(length);
	pybind11::object py_result = pybind11::cast(&result);
	for (int i = 0; i < result.size(); i++)
	{
		result[i] = -1;
		callback(i, i, py_result);
	}
	return result;
}

PYBIND11_MODULE(python_modarg, m)
{
	pybind11::bind_vector<std::vector<int> >(m, "stdvectorint");

	m.def("backend", &backend, "backend");
}

