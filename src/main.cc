#include "openrtb.h"
#include "parsing.h"

#include <fstream>
#include <iostream>
#include <rapidjson/rapidjson.h>

using namespace std;
using namespace rapidjson;
czm
int main() {
    ifstream in("bid_requests.json");
    if (!in) {
        cerr << "Could not open Bid Requests file" << endl;
        return 1;
    }

    std::string line;
    std::getline(in, line);

    Document document;
    document.Parse(line.c_str());

    auto br = parseBidRequest(document);
    cout << br->id << endl;
}
