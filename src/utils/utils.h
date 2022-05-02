//
// Created by violin on 2022/02/22
//

#ifndef UTILS_H
#define UTILS_H

#include <boost/python.hpp>
#include "esmini/esminiLib.hpp"

namespace Utils {
    SE_ScenarioObjectState getCurrentObs(int objectId);
    boost::python::list getCurrentObs();
}

#endif // UTILS_H