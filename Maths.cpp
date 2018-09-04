#include "stdafx.h"

#include "Maths.h"

glm::mat4 maths::createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale)
{
	glm::mat4 matrix;
	matrix = glm::translate(matrix, translation);

	matrix = glm::rotate(matrix, glm::radians(rx), glm::vec3(1.0f, 0.0f, 0.0f));
	matrix = glm::rotate(matrix, glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
	matrix = glm::rotate(matrix, glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));

	matrix = glm::scale(matrix, glm::vec3(scale));

	return matrix;
}
