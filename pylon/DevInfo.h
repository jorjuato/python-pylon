/*---- licence header
###############################################################################
## file :               DevInfo.h
##
## description :        This file has been made to provide a python access to
##                      the Pylon SDK from python.
##
## project :            python-pylon
##
## author(s) :          S.Blanch-Torn\'e
##
## Copyright (C) :      2015
##                      CELLS / ALBA Synchrotron,
##                      08290 Bellaterra,
##                      Spain
##
## This file is part of python-pylon.
##
## python-pylon is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## python-pylon is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with python-pylon.  If not, see <http://www.gnu.org/licenses/>.
##
###############################################################################
*/

#ifndef DEVINFO_H
#define DEVINFO_H

#include <pylon/PylonIncludes.h>
#include <pylon/gige/BaslerGigEDeviceInfo.h>
#include "Logger.h"

//TODO: add other DevInfo subclasses (like the usb)

class CppDevInfo : public Logger
{
protected:
  CppDevInfo(){};
public:
  CppDevInfo(const Pylon::CInstantCamera::DeviceInfo_t&);
  virtual ~CppDevInfo();
  Pylon::String_t GetSerialNumber();
  Pylon::String_t GetModelName();
  Pylon::String_t GetUserDefinedName();
  Pylon::String_t GetDeviceVersion();
  Pylon::String_t GetDeviceFactory();
  Pylon::CDeviceInfo GetDeviceInfo();
protected:
  Pylon::CDeviceInfo _devInfo;
};

class CppGigEDevInfo : public CppDevInfo
{
public:
  CppGigEDevInfo(const Pylon::CInstantCamera::DeviceInfo_t&);
  ~CppGigEDevInfo();
  Pylon::String_t GetAddress();
  Pylon::String_t GetIpAddress();
  Pylon::String_t GetDefaultGateway();
  Pylon::String_t GetSubnetMask();
  Pylon::String_t GetPortNr();
  Pylon::String_t GetMacAddress();
  Pylon::String_t GetInterface();
  Pylon::String_t GetIpConfigOptions();
  Pylon::String_t GetIpConfigCurrent();
  bool IsPersistentIpActive();
  bool IsDhcpActive();
  bool IsAutoIpActive();
  bool IsPersistentIpSupported();
  bool IsDhcpSupported();
  bool IsAutoIpSupported();
//  bool IsSubset(IProperties& Subset);
private:
  Pylon::CBaslerGigEDeviceInfo _gige;
};

CppGigEDevInfo* dynamic_cast_CppGigEDevInfo_ptr(CppDevInfo*);

#endif /* DEVINFO_H */
