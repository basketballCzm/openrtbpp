/* parsing.h
   Mathieu Stefani, 01 August 2015
   
   JSON Parser for OpenRTB
*/

#include <rapidjson/rapidjson.h>

#pragma once

#include <memory>
#include "openrtb.h"

std::unique_ptr<OpenRTB::BidRequest>
parseBidRequest(const rapidjson::Document& document);
