// Precompiled header.
#include "stdafx.h"
// Header include.
#include "OBJLoader.h"
// Local includes.
#include "models/RawModel.h"
#include "render-engine/Loader.h"

void split(const std::string& s, char delim, std::vector<std::string>& elems)
{
	std::stringstream ss(s);
	
	std::string item;
	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
	}
}

void obj::loader::readObjFile(std::stringstream& ss, const std::string& fileName)
{
	std::ifstream objFile;
	// ensure ifstream objects can throw exceptions:
	objFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		objFile.open("./res/models/" + fileName);
		// read file's buffer contents into streams
		ss << objFile.rdbuf();
		// close file handlers
		objFile.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::OBJ::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
}

void obj::loader::readIntoStringVector(std::vector<std::string>& destination, std::istringstream & source)
{
	std::array<std::string, 3> arr;
	source.seekg(2);

	source >> arr[0] >> arr[1] >> arr[2];

	for (int i = 0; i < 3; i++)
	{
		destination.push_back(arr[i]);
	}
}

RawModel obj::loader::loadObjModel(const std::string& fileName, Loader& loader)
{
	std::stringstream objData;
	obj::loader::readObjFile(objData, fileName);
	
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> textCoords;
	std::vector<glm::vec3> normals;
	std::vector<std::string> faces;

	// Read the buffer and place into separate vectors to process later
	std::string line;
	while (std::getline(objData, line))
	{
		std::istringstream ss(line);

		if (ss.peek() == 'v')
		{
			ss.seekg(1);

			// Vertex
			if (ss.peek() == ' ')
			{
				readIntoFloatVector(vertices, ss, 3);
			}
			// Texture
			else if (ss.peek() == 't')
			{
				readIntoFloatVector(textCoords, ss, 2);
			}
			// Normals
			else if (ss.peek() == 'n')
			{
				readIntoFloatVector(normals, ss, 3);
			}
		}
		// Faces
		else if (ss.peek() == 'f')
		{
			readIntoStringVector(faces, ss);
		}
	}

	std::vector<GLfloat> finalVertices;
	std::vector<GLfloat> finalTexCoords;
	std::vector<GLfloat> finalNormals;
	std::vector<GLuint> indices;

	if (!vertices.empty())
	{
		GLint gli[3];
		int pointAt, indexCount = 0;
		std::string str;
		for (auto& i : faces)
		{
			std::istringstream ss(i);

			pointAt = 0;
			while (getline(ss, str, '/')) {
				gli[pointAt] = std::stoi(str);
				pointAt++;
			}
			// Time to generate all the VBO details.
			for (int v = 0; v < 3; v++)
			{
				finalVertices.push_back(vertices.at(gli[0] - 1)[v]);
			}

			for (int v = 0; v < 2 && !textCoords.empty(); v++)
			{
				finalTexCoords.push_back(textCoords.at(gli[1] - 1)[v]);
			}

			for (int v = 0; v < 3 && !normals.empty(); v++)
			{
				finalNormals.push_back(normals.at(gli[2] - 1)[v]);
			}

			for (int v = 0; v < 3; v++)
			{
				indices.push_back(indexCount);
				indexCount++;
			}
		}
	}
	return loader.loadToVAO(finalVertices, finalTexCoords, finalNormals, indices);
}
