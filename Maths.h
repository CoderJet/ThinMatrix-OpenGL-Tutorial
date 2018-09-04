#pragma once

namespace maths
{
	glm::mat4 createTransformationMatrix(glm::vec3 translation,
										 float rx, float ry, float rz,
										 float scale);
}
