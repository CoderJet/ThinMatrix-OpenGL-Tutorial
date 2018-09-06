#pragma once

class Loader;
class RawModel;

namespace obj
{
	namespace loader
	{
		void readObjFile(std::stringstream& ss, const std::string& fileName);

		template<typename T>
		void readIntoFloatVector(std::vector<T>& destination, std::istringstream& source, size_t size)
		{
			std::array<std::string, 3> arr;
			source.seekg(2);

			if (size == 2)
			{
				source >> arr[0] >> arr[1];
			}
			else
			{
				source >> arr[0] >> arr[1] >> arr[2];
			}

			T _result;
			for (size_t i = 0; i < size; i++)
			{
				_result[i] = std::stof(arr[i]);
			}
			destination.push_back(_result);
		}

		void readIntoStringVector(std::vector<std::string>& destination, std::istringstream& source);

		RawModel loadObjModel(const std::string& fileName, Loader& loader);

		static sf::Clock m_clock;
	}
}

