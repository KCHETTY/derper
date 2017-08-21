#include "../Inc/Shaders.hpp"

Shaders::Shaders()
{
    this->program_id = 0;
    this->vertex_id = 0;
    this->fragment_id = 0;
    this->num_attr = 0;
}

Shaders::~Shaders()
{

}

GLuint Shaders::GetProgramID() const
{
    return (this->program_id);
}

void Shaders::compile_shaders(const std::string &vertexfile_path, const std::string &fragmentfile_path)
{
	//Creates Empty Program Object,
	//A program object is an object to which shader objects can be attached;
	program_id = glCreateProgram();

	//Creates Empty Shader Object (Vertex Shader),
	//Shader is used contain the shader source code strings (code withing shader text file).
	if ( (vertex_id = glCreateShader( GL_VERTEX_SHADER )) == 0 )
		std::cerr << "ERROR HELP" << std::endl;

	//Creates Empty Shader Object (Fragment Shader),
	//Shader is used contain the shader source code strings (code withing shader text file).
	if ( (fragment_id = glCreateShader( GL_FRAGMENT_SHADER )) == 0 )
		std::cerr << "ERROR HELP" << std::endl;

	//Debug
	std::cout << vertex_id << std::endl;
	std::cout << fragment_id << std::endl;

	//Compile Vertex Shaders
	compile( vertexfile_path, vertex_id );

	//Compile Fragment Shaders
	compile( fragmentfile_path, fragment_id );

	link_shaders();
}

void Shaders::link_shaders()
{
	//Attaches Shaders to the program object.
	glAttachShader(program_id, vertex_id);
	glAttachShader(program_id, fragment_id);

    add_attributes("position");
    add_attributes("texCoord");
    add_attributes("normal");
	//Links the Shaders to the respective programmable Proccesors and creates executables that allow them to run.
	glLinkProgram(program_id);

	GLint is_linked = 0;

	//Equivalent to glGetShaderiv.
	glGetProgramiv(program_id, GL_LINK_STATUS, &is_linked);
	if (is_linked == GL_FALSE)
	{
		GLint maxlength = 0;

		glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &maxlength);

		std::vector <char> errorlog(maxlength);

		glGetProgramInfoLog(program_id, maxlength, &maxlength, &errorlog[0]);

		//Deletes Program Object.
		glDeleteProgram(program_id);
		glDeleteShader(vertex_id);
		glDeleteShader(fragment_id);

		std::cerr << "BAD NEWS BUB" << std::endl;

		return;
	}

	//Detaches Shaders From the Program object.
	glDetachShader(program_id, vertex_id);
	glDetachShader(program_id, fragment_id);
}

void Shaders::compile(const std::string &file_path, GLuint &tmp_id)
{

	//Will Copies contents of shader file to the contents string so it can be binded to the shader object later.
	std::ifstream file(file_path);
	if (file.fail())
		std::cerr << "Error Help DEEZZ" << std::endl;

	//Debug
	std::cout << tmp_id << std::endl;

	std::string file_contents = "";
	std::string line = "";

	while (getline(file, line))
	{
		file_contents += line + "\n";
	}

	file.close();

	const char *file_data = file_contents.c_str();

	std::cout << file_data << std::endl;

	//Copies the Source code from the contents string to the Shader object and prepares the shader code to be compiled later.
	glShaderSource(tmp_id, 1, &file_data, nullptr);

	//Compiles the source code strings stored in the shader object. Will return GL_TRUE if Compiled Succesfully.
	glCompileShader(tmp_id);

	GLint success = 0;

	//Returns Shader Information, in this case the compile Status.
	glGetShaderiv(tmp_id, GL_COMPILE_STATUS, &success);

	//Throws Error if Shaders Are not compiled correctly.
	if (GL_FALSE == success)
	{
		GLint maxlength = 0;

		//Gets the Shader Error/Info Log Size.
		glGetShaderiv(tmp_id, GL_INFO_LOG_LENGTH, &maxlength);

		GLchar errorlog[maxlength];

		//Return the Shader Info Log.
		glGetShaderInfoLog(tmp_id, maxlength, &maxlength, errorlog);

		//Deletes The Shader Object.
		glDeleteShader(tmp_id);

		std::cerr << "Failed Son" << std::endl;

		for (GLint i = 0; i < maxlength; i++)
		{
			std::cout << errorlog[i] << " ";
		}
		std::cout << std::endl;

		return;
	}
}

void Shaders::load_float( GLint location_id, GLfloat val )
{
    glUniform1f( location_id, val );
}

void Shaders::load_vect( GLint location_id, glm::vec3 vect )
{
    glUniform3f( location_id, vect.x, vect.y, vect.z );
}

void Shaders::load_bool( GLint location_id, bool val )
{
    glUniform1f( location_id, static_cast< GLfloat > (val) );
}

void Shaders::load_matrix( GLint location_id, glm::mat4 &matrix )
{
    glUniformMatrix4fv( location_id, 1, GL_FALSE, glm::value_ptr( matrix ) );
}

GLint Shaders::GetUniformLocation(const std::string &Uniform_name)
{
	GLint Location_ID;
	Location_ID = glGetUniformLocation(program_id, Uniform_name.c_str());

	if (GL_INVALID_INDEX == Location_ID)
	{
		std::cerr << "Location Id" << std::endl;
	}

	return Location_ID;
}

void Shaders::add_attributes(const std::string &attr_name)
{
	//Associates a generic Vertex attribute index with a name.
	glBindAttribLocation(program_id, num_attr++, attr_name.c_str());
}

void Shaders::use_prog()
{
	//Makes the Compiled Shader Executables usable in the rendering process.
	glUseProgram(program_id);
	for (int i = 0; i < num_attr; i++)
	{
		//Uses Currently bound Vertex array object for the operation.
		glEnableVertexAttribArray(i);
	}
}

void Shaders::unuse_prog()
{
	glUseProgram(0);
	for (int i = 0; i < num_attr; i++)
	{
		glDisableVertexAttribArray(i);
	}
}
