#pragma once

#include "Base.hpp"
#include "Text_Model.hpp"

class Component
{
    private:

        Text_Model model;

        GLfloat Rotation_x;
        GLfloat Rotation_y;
        GLfloat Rotation_z;

        GLfloat Scale;

        glm::vec3 position;

        Component();

    public:

        Component( Text_Model const &tmp_model, GLfloat const &rot_x, GLfloat const &rot_y, GLfloat const &rot_z, GLfloat const &tmp_scale, glm::vec3 const &tmp_pos );
        ~Component();

        void SetTextModel( Text_Model const &tmp_model );
        void SetRotX( GLfloat const &rot_x );
        void SetRotY( GLfloat const &rot_y );
        void SetRotZ( GLfloat const &rot_z );
        void SetScale( GLfloat const &tmp_scale );
        void SetPosition( glm::vec3 const &tmp_position );

        Text_Model GetTextModel( ) const;
        GLfloat GetRotX( ) const;
        GLfloat GetRotY( ) const;
        GLfloat GetRotZ( ) const;
        GLfloat GetScale( ) const;
        glm::vec3 GetPosition( ) const;

        void inc_rotation( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z );
        void inc_position( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z );
        void dec_position( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z );
        void dec_rotation( GLfloat const &tmp_x, GLfloat const &tmp_y, GLfloat const &tmp_z );

};
