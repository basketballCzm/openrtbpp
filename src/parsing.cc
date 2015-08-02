/* parsing.cc
   Mathieu Stefani, 01 August 2015
   
   Implementation of the JSON OpenRTB parser
*/

#include "parsing.h"

std::unique_ptr<OpenRTB::BidRequest>
parseBidRequest(const rapidjson::Document& document)
{
    std::unique_ptr<OpenRTB::BidRequest> br(new OpenRTB::BidRequest);
    if (document.HasMember("id")) {
        br->id = document["id"].GetString();
    }
    return br;
}
