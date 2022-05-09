//
// Created by violin on 2022/4/30.
//

#include "road_sensor.h"

#include <boost/python.hpp>
#include "esmini/esminiLib.hpp"
#include "esmini/esminiRMLib.hpp"

namespace Sensor {
    RoadSensor::RoadSensor(int objectId) : Sensor(objectId, "RoadSensor") {
        posHandle = RM_CreatePosition();
    }

    RoadSensor::~RoadSensor() {
       RM_DeletePosition(posHandle);
    }

    boost::python::tuple RoadSensor::report() {
       SE_ScenarioObjectState s;
       SE_GetObjectState(objectId, &s);
       RM_SetWorldPosition(posHandle, s.x, s.y, s.z, s.h, s.p, s.r);
       boost::python::list roads;
       int roadNum = RM_GetNumberOfRoadsOverlapping(posHandle);
       for(int i = 0; i < roadNum; i++) {
           boost::python::list lanes;
           int roadId = RM_GetOverlappingRoadId(posHandle, i);
           int laneNum = RM_GetRoadNumberOfLanes(roadId, s.s);
           for(int j = 0; j < laneNum; j++) {
               boost::python::dict lane;
               int laneId = RM_GetLaneIdByIndex(roadId, j, s.s);
               float width = RM_GetLaneWidthByRoadId(roadId, laneId, s.s);
               lane["id"] = laneId;
               lane["width"] = width;
               lanes.append(lane);
           }
           roads.append(lanes);
       }

       return boost::python::make_tuple(sensorType, roadNum, roads); // TODO: add more road info
    }
}
