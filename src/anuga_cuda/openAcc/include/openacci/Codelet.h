/*
 * Copyright (C) 2008-2013 CAPS entreprise.  All Rights Reserved.
 * 
 * The source code contained or described herein and all documents  related
 * to the source code ("Material") are owned  by  CAPS  entreprise  or  its
 * suppliers or licensors.
 * 
 * Title to the Material remains with CAPS entreprise or its suppliers  and
 * licensors.  The Material contains trade secrets and proprietary and con-
 * fidential information of CAPS entreprise or its suppliers and licensors.
 * 
 * The Material is protected by the French intellectual property code,  in-
 * tellectual property laws and international treaties.  No part of the Ma-
 * terial may be used, copied, reproduced, modified,  published,  uploaded,
 * posted, transmitted, distributed or disclosed in any  way  without  CAPS
 * entreprise's prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other  intellec-
 * tual property right is granted to or conferred upon you by disclosure or
 * delivery of the Material, either expressly, by implication,  inducement,
 * estoppel or otherwise.
 * 
 * Any license under such intellectual property rights  must  be  expressed
 * and approved by CAPS entreprise in writing.
 */
#ifndef OPENACCI_CODELET_H
#define OPENACCI_CODELET_H

#include <openacc/openacc.h>

#include <hmpprt/Grouplet.h>
#include <hmpprt/Codelet.h>

#include <map>

namespace openacci
{
  struct Codelet
  {
    Codelet(const char * module_name, const char * function_name, acc_device_t device_type);
  
    ~Codelet();
  
    int getNumberOfParameters()
    {
      return handle_->getNumberOfParameters();
    }
  
    hmpprt::MemorySpace getMemorySpaceByIndex(int i)
    {
      return handle_->getMemorySpaceByIndex(i);
    }
  
    hmpprt::Intent getIntentByIndex(int i)
    {
      return handle_->getIntentByIndex(i);
    }

    std::string getNameByIndex(int i)
    {
      return handle_->getNameByIndex(i);
    }

    hmpprt::Codelet * getHandle() { return handle_; }
  
  private:
    hmpprt::Grouplet * grouplet_;
    hmpprt::Codelet  * handle_;
  };
  
  typedef std::map<std::string, Codelet *> CodeletMap;
} // openacci namespace
#endif // OPENACCI_CODELET_H