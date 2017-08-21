#include "../Inc/Component.hpp"


Component::Component()
{
    return ;
}

Component::~Component()
{
    //std::cout << "IM DEAD " << std::endl;
    return ;
}

Component::Component( Text_Model const &tmp_model, GLfloat const &rot_x, GLfloat const &rot_y, GLfloat const &rot_z, GLfloat const &tmp_scale, glm::vec3 const &tmp_pos )
{
    this->model = tmp_model;
    this->Rotation_x = rot_x;
    this->Rotation_y = rot_y;
    this->Rotation_z = rot_z;
    this->Scale = tmp_scale;
    this->position = tmp_pos;
}

void Component::inc_rotation( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z )
{
    this->Rotation_x += tmp_x;
    this->Rotation_y += tmp_y;
    this->Rotation_z += tmp_z;
}

void Component::inc_position( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z )
{
    this->position.x += tmp_x;
    this->position.y += tmp_y;
    this->position.z += tmp_z;
}

void Component::dec_position( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z )
{
    this->position.x -= tmp_x;
    this->position.y -= tmp_y;
    this->position.z -= tmp_z;
}

void Component::dec_rotation( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z )
{
    this->Rotation_x -= tmp_x;
    this->Rotation_y -= tmp_y;
    this->Rotation_z -= tmp_z;
}

void Component::SetTextModel( Text_Model const &tmp_model )
{
    this->model = tmp_model;
}

void Component::SetRotX( GLfloat const &rot_x )
{
    this->Rotation_x = rot_x;
}

void Component::SetRotY( GLfloat const &rot_y )
{
    this->Rotation_y = rot_y;
}

void Component::SetRotZ( GLfloat const &rot_z )
{
    this->Rotation_z = rot_z;
}

void Component::SetScale( GLfloat const &tmp_scale )
{
    this->Scale = tmp_scale;
}

void Component::SetPosition( glm::vec3 const &tmp_position )
{
    this->position = tmp_position;
}

Text_Model Component::GetTextModel( ) const
{
    return (this->model);
}

GLfloat Component::GetRotX( ) const
{
    return (this->Rotation_x);
}

GLfloat Component::GetRotY( ) const
{
    return (this->Rotation_y);
}

GLfloat Component::GetRotZ( ) const
{
    return (this->Rotation_z);
}

GLfloat Component::GetScale( ) const
{
    return (this->Scale);
}

glm::vec3 Component::GetPosition( ) const
{
    return (this->position);
}
