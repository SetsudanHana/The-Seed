#include "Shader.h"

static std::string TAG = "Shader";

struct ShaderDeleter {
	inline void operator()(unsigned* program) {
		std::stringstream out;
		out << "Remove program: " << *program;
		utils::Log::Instance()->logDebug(TAG, out.str());
		glDeleteProgram(*program);
	}
};

gl::Shader::Shader(){
}

gl::Shader::Shader(unsigned & program){
	std::unique_ptr<unsigned int, std::function<void(unsigned int*)>> ptr(&program, ShaderDeleter());
	mProgram = std::move(ptr);
}

gl::Shader::Shader(const Shader &){
}

gl::Shader::~Shader(){
}

void gl::Shader::useProgram(){
	std::stringstream out;
	out << "Using program: " << *mProgram;
	utils::Log::Instance()->logInfo(TAG, out.str());
	glUseProgram(*mProgram);
}

void gl::Shader::setField(const float & value, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach field which does not exist, with name: " + name);
	}
	glUniform1f(location, value);
}

void gl::Shader::setSampler(const UINT & sampler, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach sampler which does not exist, with name: " + name);
	}
	glUniform1i(location, sampler);
}

void gl::Shader::setVector2(const glm::vec2 & vector, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach vec2 which does not exist, with name: " + name);
	}
	glUniform2fv(location, 1, glm::value_ptr(vector));
}

void gl::Shader::setVector3(const glm::vec3 & vector, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach vec3 which does not exist, with name: " + name);
	}
	glUniform3fv(location, 1, glm::value_ptr(vector));
}

void gl::Shader::setVector4(const glm::vec4 & vector, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach vec4 which does not exist, with name: " + name);
	}
	glUniform4fv(location, 1, glm::value_ptr(vector));
}

void gl::Shader::setMatrix2(const glm::mat2 & matrix, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach mat2 which does not exist, with name: " + name);
	}
	glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void gl::Shader::setMatrix3(const glm::mat3 & matrix, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach mat3 which does not exist, with name: " + name);
	}
	glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void gl::Shader::setMatrix4(const glm::mat4 & matrix, const std::string & name){
	GLint location = glGetUniformLocation(*mProgram, name.c_str());
	if (location == -1) {
		utils::Log::Instance()->logWarning(TAG, "Trying to attach mat4 which does not exist, with name: " + name);
	}
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
