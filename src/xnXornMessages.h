#ifndef XNXORNMESSAGES_H
#define XNXORNMESSAGES_H

#include <stdint.h>
#include <vector>

#include "xnMessage.h"
#include "DgVector.h"
#include "xnCommon.h"
#include "xnGeometry.h"

#define MESSAGE_HEADER(t) \
  class Message_ ## t : public Message {\
  public:\
    static size_t Size();\
    static uint32_t GetStaticID();\
    uint32_t GetID() const override;\
    std::string ToString() const override;\
    static Message * Create();


namespace xn
{
  //-------------------------------------------------------------------
  // Messages
  //-------------------------------------------------------------------

  MESSAGE_HEADER(InsertVertex)
    uint32_t polygonID;
    uint32_t vertexIndex;
    vec2 newPosition;
  };

  MESSAGE_HEADER(RemoveVertex)
    uint32_t polygonID;
    uint32_t vertexIndex;
  };

  MESSAGE_HEADER(MoveVertex)
    uint32_t polygonID;
    uint32_t vertexIndex;
    vec2 newPosition;
  };

  MESSAGE_HEADER(TransformPolygon)
    uint32_t polygonID;
    Transform t;
  };

  MESSAGE_HEADER(RemovePolygon)
    uint32_t polygonID;
  };

  MESSAGE_HEADER(AddPolygon)
    std::vector<vec2> points;
  };
}

#endif