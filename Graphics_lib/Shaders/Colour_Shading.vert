#version 330 core

layout ( location = 0 )  in vec3 position;
layout ( location = 1 )  in vec2 texCoord;
layout ( location = 2 )  in vec3 normal;

out vec2 textures;
out vec3 surface_normal;
out vec3 toLightVector;
out vec3 toCameraVector;

uniform mat4 model; // converts locall co-ordinates to camera co-ordinates
uniform mat4 scale; //
uniform mat4 view;	// converts normalized co-ordinates to window co-ordinates

uniform mat4 projection; // converts camera co-ordinates to normalized co-ordinates ( 0 - 1 )
uniform vec3 light_pos;

void main( )
{
	vec4 world_pos = view * model * vec4( position, 1.0 );

	gl_Position = projection * world_pos;
	textures = vec2( texCoord.x, 1.0 - texCoord.y);

	surface_normal = ( view * model * vec4(normal, 0.0f) ).xyz;
	toLightVector = light_pos - world_pos.xyz;

	toCameraVector = (inverse(view) * vec4( 0.0f, 0.0f, 0.0f, 1.0f )).xyz - world_pos.xyz;
};
