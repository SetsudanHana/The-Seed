#include "ShaderLoader.h"

static std::string TAG = "ShaderLoader";

utils::ShaderLoader::ShaderLoader(){
}

utils::ShaderLoader::ShaderLoader(const ShaderLoader &){
}

utils::ShaderLoader::~ShaderLoader(){
}

gl::Shader utils::ShaderLoader::load(const std::string name)
{
	std::string vs_container = loadShaderFile(SHADER_DIRECTORY + name + ".vs");

	if (vs_container == "") {
		utils::Log::Instance()->logError(TAG, "VertexShader " + name + ": failed to read file");
		return gl::Shader();
	}

	std::string fs_container = loadShaderFile(SHADER_DIRECTORY + name + ".fs");

	if (fs_container == "") {
		utils::Log::Instance()->logError(TAG, "FragmentShader " + name + ": failed to read file");
		return gl::Shader();
	}

	const char* vertex_shader = vs_container.c_str();
	const char* fragment_shader = fs_container.c_str();

	GLint lenVS = vs_container.length();
	GLint lenFS = fs_container.length();

	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vs, 1, &vertex_shader, &lenVS);
	glCompileShader(vs);
	glShaderSource(fs, 1, &fragment_shader, &lenFS);
	glCompileShader(fs);

	bool result = true;

	result = checkShaderErrors(vs);

	if (!result) {
		utils::Log::Instance()->logError(TAG, "VertexShader " + name + " compiled with errors");
		return gl::Shader();
	}

	result = checkShaderErrors(fs);

	if (!result) {
		utils::Log::Instance()->logError(TAG, "FragmentShader " + name + " compiled with errors");
		return gl::Shader();
	}

	unsigned int shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	std::stringstream out;
	out << "Created Shader id: " << shader_programme;
	utils::Log::Instance()->logError(TAG, out.str());
	return gl::Shader(shader_programme);
}

bool utils::ShaderLoader::checkShaderErrors(const unsigned & shaderId){
	GLint blen = 0;
	GLsizei slen = 0;

	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &blen);

	if (blen > 1) {
		GLchar* compiler_log = (GLchar*)malloc(blen);
		glGetInfoLogARB(shaderId, blen, &slen, compiler_log);
		std::string out = std::string("\ncompiler_log:\n") + compiler_log;
		utils::Log::Instance()->logError(TAG, out);
		free(compiler_log);
		return false;
	}
	return true;
}

std::string utils::ShaderLoader::loadShaderFile(const std::string & path) {
	std::ifstream file(path);

	if (!file.good()) {
		utils::Log::Instance()->logError(TAG, "Opening Text file: " + path + " failed");
		return "";
	}

	std::stringstream stream;
	stream << file.rdbuf();

	file.close();

	return stream.str();
}
