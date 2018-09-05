// Precompiled header.
#include "stdafx.h"
// Header include.
#include "Maths.h"
// Local includes.
#include "camera/Camera.h"

glm::mat4 maths::createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, float scale)
{
	glm::mat4 matrix(1.0f);
	matrix = glm::translate(matrix, translation);

	matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	matrix = glm::rotate(matrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	matrix = glm::scale(matrix, glm::vec3(scale));

	return matrix;
}

glm::mat4 maths::createViewMatrix(Camera& camera)
{
	glm::mat4 viewMatrix(1.0f);
	viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getPitch()), glm::vec3(1, 0, 0));
	viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getYaw()), glm::vec3(0, 1, 0));

	glm::vec3 cameraPos = camera.getPosition();
	glm::vec3 negativeCameraPos(-cameraPos.x, -cameraPos.y, -cameraPos.z);
	// Invert the view so when we move left, the view goes to the right.
	viewMatrix = glm::translate(viewMatrix, negativeCameraPos);

	return viewMatrix;
}
