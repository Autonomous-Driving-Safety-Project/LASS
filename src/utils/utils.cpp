//
// Created by violin on 2022/02/22.
//

#include "utils.h"
#include "esmini/esminiLib.hpp"

namespace Utils
{
    SE_ScenarioObjectState getCurrentObs(int objectId) {
        SE_ScenarioObjectState state;
        SE_GetObjectState(objectId, &state);
        return state;
    }

    boost::python::list getCurrentObs()
    {
        int num = SE_GetNumberOfObjects();
        boost::python::list obs;
        for(int i=0; i<num; i++)
        {
            SE_ScenarioObjectState obs_i = getCurrentObs(SE_GetId(i));
            obs.append(obs_i);
        }
        return obs;
    }
}
