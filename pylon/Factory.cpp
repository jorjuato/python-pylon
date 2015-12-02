/*---- licence header
###############################################################################
## file :               Factory.cpp
##
## description :        This file has been made to provide a python access to
##                      the Pylon SDK from python.
##
## project :            TANGO
##
## author(s) :          S.Blanch-Torn\'e
##
## Copyright (C) :      2015
##                      CELLS / ALBA Synchrotron,
##                      08290 Bellaterra,
##                      Spain
##
## This file is part of Tango.
##
## Tango is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Tango is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with Tango.  If not, see <http:##www.gnu.org/licenses/>.
##
###############################################################################
*/

#include "Factory.h"

Transport::Transport() { }

Transport::~Transport() { }

void Transport::CreateTl()
{
  _tl = Pylon::CTlFactory::GetInstance().CreateTl( Camera_t::DeviceClass() );
}

void Transport::ReleaseTl()
{
  Pylon::CTlFactory::GetInstance().ReleaseTl(_tl);
}

int Transport::DeviceDiscovery()
{
  int nCamera = 0;

  if ( _tl != NULL )
  {
    nCamera = _tl->EnumerateDevices( deviceList );
    deviceIterator = deviceList.begin();
  }
  return nCamera;
}

Camera_t::DeviceInfo_t* Transport::getNextDeviceInfo()
{
  Camera_t::DeviceInfo_t* deviceInfo;

  if ( deviceIterator != deviceList.end() )
  {
    deviceInfo = static_cast<const Camera_t::DeviceInfo_t&>(*deviceIterator);
    deviceIterator++;
    return deviceInfo;
  }
  else
  {
    return NULL;
  }
}


