#include <functional>
#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <vector>

PYBIND11_MAKE_OPAQUE(std::vector<int>);

using namespace std;

vector<int> backend(int length, std::function<void (int, int, vector<int>&)>& callback)
{
	vector<int> result(length);
	for (int i = 0; i < result.size(); i++)
	{
		result[i] = -1;
		callback(i, i, result);
	}
	return result;
}

PYBIND11_MODULE(python_modarg, m)
{
	pybind11::bind_vector<std::vector<int> >(m, "stdvectorint");

	m.def("backend", &backend, "backend");
}

