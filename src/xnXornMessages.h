#ifndef XNXORNMESSAGES_H
#define XNXORNMESSAGES_H

#include <stdint.h>
#include <vector>

#include "xnMessage.h"
#include "DgVector.h"
#include "xnCommon.h"
#include "xnGeometry.h"

namespace xn
{
  //-------------------------------------------------------------------
  // Messages
  //-------------------------------------------------------------------

  MESSAGE_HEADER(InsertVertex)
    uint32_t polygonID;
    uint32_t vertexBefore;
    vec2 position;
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

  MESSAGE_HEADER(MouseDown)
    vec2 position;
  };

  MESSAGE_HEADER(MouseUp)
    vec2 position;
  };

  MESSAGE_HEADER(MouseMove)
    vec2 position;
  };

  MESSAGE_HEADER(WindowGainedFocus)
    uint32_t windowID;
  };

  MESSAGE_HEADER(WindowLostFocus)
    uint32_t windowID;
  };

  MESSAGE_HEADER(WindowClosed)
    uint32_t windowID;
  };
}

#endif