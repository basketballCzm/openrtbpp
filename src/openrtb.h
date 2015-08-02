/* openrtb.h
   Mathieu Stefani, 01 August 2015
   
   OpenRTB specification definition in C++
*/

#include <rapidjson/document.h>

#pragma once

#include "types/optional.h"
#include "types/types.h"
#include <vector>

namespace OpenRTB {

using namespace Types;

DefineEnum(
    Type(AuctionType),
        Value(FirstPrice),
        Value(SecondPrice)
);

DefineEnum(
    Type(BannerAdType),
        Value(XHTMLText),
        Value(XHTMLBanner),
        Value(JavaScript),
        Value(IFrame)
);

DefineEnum(
    Type(CreativeAttribute),
        Value(AudioAutoPlay),
        Value(AudioUserInitiated),
        Value(ExpandableAutomatic),
        Value(ExpandableUserInitiatedClick),
        Value(ExpandableUserInitiatedRollover),
        Value(InBannerVideoAutoPlay),
        Value(InBannerVideoUserInitiated),
        Value(Pop),
        Value(Provocative),
        Value(Shaky),
        Value(Surveys),
        Value(TextOnly),
        Value(UserInteractive),
        Value(WindowsDialog),
        Alias(AlertStyle, WindowsDialog),
        Value(HasAudioOnOff),
        Value(Skippable)
);

DefineEnum(
    Type(ApiFramework),
        Value(VPAID10),
        Value(VPAID20),
        Value(MRAID1),
        Value(ORMMA),
        Value(MRAID2)
);

DefineEnum(
    Type(AdPosition),
        Value(AboveFold),
        Value(Unused),
        Value(BelowFold),
        Value(Header),
        Value(Footer),
        Value(Sidebar),
        Value(Fullscreen)
);

DefineEnum(
    Type(VideoLinearity),
        Value(Linear),
        Alias(InStream, Linear),
        Value(NonLinear),
        Alias(Overlay, NonLinear)
);

DefineEnum(
    Type(VideoBidResponseProtocol),
        Value(VAST10),
        Value(VAST20),
        Value(VAST30),
        Value(VAST10Wrapper),
        Value(VAST20Wrapper),
        Value(VAST30Wrapper)
);

DefineEnum(
    Type(VideoPlaybackMethod),
        Value(AutoPlaySoundOn),
        Value(AutoPlaySoundOff),
        Value(ClickToPlay),
        Value(MouseOver)
);

DefineEnum(
    Type(VideoStartDelay),
        Value(PreRoll)
);

DefineEnum(
    Type(ConnectionType),
        Value(Ethernet),
        Value(Wifi),
        Value(CellularUnknown),
        Value(Cellular2G),
        Value(Cellular3G),
        Value(Cellular4G)
);

DefineEnum(
    Type(ExpandableDirection),
        Value(Left),
        Value(Right),
        Value(Up),
        Value(Down),
        Value(FullScreen)
);

DefineEnum(
    Type(ContentDeliveryMethod),
        Value(Streaming),
        Value(Progressive)
);

DefineEnum(
    Type(ContentContext),
        Value(Video),
        Value(Game),
        Value(Music),
        Value(Application),
        Value(Text),
        Value(Other),
        Alias(Unknown2, Unknown) // LOL
);

DefineEnum(
    Type(VideoQuality),
        Value(Professional),
        Value(Prosumer),
        Value(UserGenerated)
);

DefineEnum(
    Type(LocationType),
        Value(GPS),
        Value(IPAddress),
        Value(UserProvider)
);

DefineEnum(
    Type(DeviceType),
        Value(Mobile),
        Value(PC),
        Value(ConnectedTV),
        Value(Phone),
        Value(Tablet),
        Value(ConnectedDevice),
        Value(SetTopBox)
);

DefineEnum(
    Type(VASTCompanionType),
        Value(StaticResource),
        Value(HTMLResource),
        Value(IFrameResource)
);

DefineEnum(
    Type(QAGMediaRating),
        Value(AllAudiences),
        Value(Over12),
        Value(MatureAudiences)
);



struct Banner {
    Id id;
    Integer<> w;
    Integer<> h;
    Integer<> wmax;
    Integer<> hmax;
    Integer<> wmin;
    Integer<> hmin;
    Integer<> pos;
    std::vector<Enum<BannerAdType>> btype;
    std::vector<Enum<CreativeAttribute>> battr;
    std::vector<std::string> mimes;
    Bool<> topframe;
    std::vector<Enum<ExpandableDirection>> expdir;
    std::vector<Enum<ApiFramework>> api;
    rapidjson::Value ext;
};

struct Video {
    Id id;
    std::vector<std::string> mimes;
    Integer<> minduration;
    Integer<> maxduration;
    Enum<VideoBidResponseProtocol> protocol;
    std::vector<Enum<VideoBidResponseProtocol>> protocols;
    Integer<> w;
    Integer<> h;
    Enum<VideoStartDelay> stardelay;
    Enum<VideoLinearity> linearity;
    Integer<1> sequence;
    std::vector<Enum<CreativeAttribute>> battr;
    Integer<> maxextended;
    Integer<> minbitrate;
    Integer<> maxbirate;
    Bool<true> boxingallowed;
    std::vector<Enum<VideoPlaybackMethod>> playbackmethod;
    std::vector<Enum<ContentDeliveryMethod>> delivery;
    Enum<AdPosition> pos;
    std::vector<Banner> companionad;
    std::vector<Enum<ApiFramework>> api;
    rapidjson::Value ext;
};

struct Publisher {
    Id id;
    std::string name;
    std::vector<std::string> cat;
    std::string domain;
    rapidjson::Value ext;
};

typedef Publisher Producer;

struct Content {
    Id id;
    Integer<> episode;
    std::string title;
    std::string series;
    std::string season;
    std::string url;
    std::vector<std::string> cat;
    Enum<VideoQuality> videoquality;
    std::string keywords;
    std::string contentrating;
    std::string userrating;
    Enum<ContentContext> context;
    Bool<> livestream;
    Integer<> sourcerelationship;
    Optional<Producer> producer;
    Integer<> len;
    Enum<QAGMediaRating> qagmediarating;
    Bool<> embaddable;
    std::string language;
    rapidjson::Value ext;
 };


struct Site {
    Id id;
    std::string name;
    std::string domain;
    std::vector<std::string> cat;
    std::vector<std::string> sectioncat;
    std::vector<std::string> pagecat;
    std::string page;
    Bool<> privacypolicy;
    std::string ref;
    std::string search;
    Optional<Publisher> publisher;
    Optional<Content> content;
    std::string keywords;
    rapidjson::Value ext;
};

struct App {
    Id id;
    std::string name;
    std::string domain;
    std::vector<std::string> cat;
    std::vector<std::string> sectioncat;
    std::vector<std::string> pagecat;
    std::string ver;
    std::string bundle;
    Bool<> privacypolicy;
    Bool<> paid;
    Optional<Publisher> publisher;
    Optional<Content> content;
    std::string keywords;
    std::string storeurl;
    rapidjson::Value ext;
};

struct Geo {
    Float lat;
    Float lon;
    std::string country;
    std::string region;
    std::string regionfips104;
    std::string metro;
    std::string city;
    std::string zip;
    Enum<LocationType> type;
    rapidjson::Value ext;
};

struct Device {
    Bool<> dnt;
    std::string ua;
    std::string ip;
    Optional<Geo> geo;
    std::string didsha1;
    std::string didmd5;
    std::string dpidsha1;
    std::string dpidm5;
    std::string macsha1;
    std::string macmd5;
    std::string ipv6;
    std::string carrier;
    std::string language;
    std::string make;
    std::string model;
    std::string os;
    std::string osv;
    Bool<> js;
    Enum<ConnectionType> connectiontype;
    Enum<DeviceType> devicetype;
    std::string flashver;
    std::string ifa;
    rapidjson::Value ext;
};

struct Segment {
    Id id;
    std::string name;
    std::string value;
    rapidjson::Value ext;
};

struct Data {
    Id id;
    std::string name;
    std::vector<Segment> segment;
    rapidjson::Value ext;
};

struct User {
    Id id;
    std::string buyeruid;
    Integer<> yob;
    std::string gender;
    std::string keywords;
    std::string customdata;
    Optional<Geo> geo;
    std::vector<Data> data;
    rapidjson::Value ext;
};

struct Regulations {
    Bool<> coppa;
    rapidjson::Value ext;
};

struct Deal {
    Id id;
    Float bidfloor;
    std::string bidfloorcur;
    std::vector<std::string> wseat;
    std::vector<std::string> wadomain;
    Enum<AuctionType> at;
    rapidjson::Value ext;
};

struct PMP {
    Bool<> private_auction;
    std::vector<Deal> deals;
    rapidjson::Value ext;
};

struct Impression {
    Id id;
    Optional<Banner> banner;
    Optional<Video> video;
    std::string displaymanager;
    std::string displaymanagerver;
    Integer<> instl;
    std::string tagid;
    Float bidfloor;
    std::string bidfloorcur; 
    Bool<> secure;
    std::vector<std::string> iframebuster;
    Optional<PMP> pmp;
    rapidjson::Value ext;
};

struct BidRequest {
    Id id;
    std::vector<Impression> imp;
    Optional<Site> site;
    Optional<App> app;
    Optional<Device> device;
    Optional<User> user; 
    Enum<AuctionType, AuctionType::SecondPrice> at;
    Integer<> tmax;
    std::vector<std::string> wseat;
    Bool<> allimps;
    std::vector<std::string> cur;
    std::vector<std::string> bcat;
    std::vector<std::string> badv;
    Optional<Regulations> regs;
    rapidjson::Value ext;
};

} // namespace OpenRTB
