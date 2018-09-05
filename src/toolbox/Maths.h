#pragma once

class Camera;

namespace maths
{
	glm::mat4 createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, float scale);

	glm::mat4 createViewMatrix(Camera& camera);
}
