#ifndef _ROS_SERVICE_AlterUrdf_h
#define _ROS_SERVICE_AlterUrdf_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iai_urdf_msgs
{

static const char ALTERURDF[] = "iai_urdf_msgs/AlterUrdf";

  class AlterUrdfRequest : public ros::Msg
  {
    public:
      int8_t action;
      const char* xml_elements_to_add;
      uint8_t element_names_to_remove_length;
      char* st_element_names_to_remove;
      char* * element_names_to_remove;
      enum { ADD = 1 };
      enum { REMOVE = 2 };

    AlterUrdfRequest():
      action(0),
      xml_elements_to_add(""),
      element_names_to_remove_length(0), element_names_to_remove(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_xml_elements_to_add = strlen(this->xml_elements_to_add);
      memcpy(outbuffer + offset, &length_xml_elements_to_add, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->xml_elements_to_add, length_xml_elements_to_add);
      offset += length_xml_elements_to_add;
      *(outbuffer + offset++) = element_names_to_remove_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < element_names_to_remove_length; i++){
      uint32_t length_element_names_to_removei = strlen(this->element_names_to_remove[i]);
      memcpy(outbuffer + offset, &length_element_names_to_removei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->element_names_to_remove[i], length_element_names_to_removei);
      offset += length_element_names_to_removei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->action = u_action.real;
      offset += sizeof(this->action);
      uint32_t length_xml_elements_to_add;
      memcpy(&length_xml_elements_to_add, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_xml_elements_to_add; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_xml_elements_to_add-1]=0;
      this->xml_elements_to_add = (char *)(inbuffer + offset-1);
      offset += length_xml_elements_to_add;
      uint8_t element_names_to_remove_lengthT = *(inbuffer + offset++);
      if(element_names_to_remove_lengthT > element_names_to_remove_length)
        this->element_names_to_remove = (char**)realloc(this->element_names_to_remove, element_names_to_remove_lengthT * sizeof(char*));
      offset += 3;
      element_names_to_remove_length = element_names_to_remove_lengthT;
      for( uint8_t i = 0; i < element_names_to_remove_length; i++){
      uint32_t length_st_element_names_to_remove;
      memcpy(&length_st_element_names_to_remove, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_element_names_to_remove; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_element_names_to_remove-1]=0;
      this->st_element_names_to_remove = (char *)(inbuffer + offset-1);
      offset += length_st_element_names_to_remove;
        memcpy( &(this->element_names_to_remove[i]), &(this->st_element_names_to_remove), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return ALTERURDF; };
    const char * getMD5(){ return "ef7efe9a5c6f814f25e7f61e3fad05bf"; };

  };

  class AlterUrdfResponse : public ros::Msg
  {
    public:
      bool success;

    AlterUrdfResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return ALTERURDF; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class AlterUrdf {
    public:
    typedef AlterUrdfRequest Request;
    typedef AlterUrdfResponse Response;
  };

}
#endif
