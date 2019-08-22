#ifndef BDSDATA_H
#define BDSDATA_H

#include <QObject>
#include <QJsonObject>
#include <QDebug>
#include <QVariant>
#include <QFile>
#include <QDateTime>
#include <QFileInfo>

#include "globaldefine.h"
#include "simpledata.h"
#include "imagedata.h"

class BDSData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY BDSDataChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY BDSDataChanged)
    Q_PROPERTY(QString homenumber READ getHomenumber WRITE setHomenumber NOTIFY BDSDataChanged)
    Q_PROPERTY(QString street READ getStreet WRITE setStreet NOTIFY BDSDataChanged)
    Q_PROPERTY(QString ward READ getWard WRITE setWard NOTIFY BDSDataChanged)
    Q_PROPERTY(QString district READ getDistrict WRITE setDistrict NOTIFY BDSDataChanged)
    Q_PROPERTY(QString province READ getProvince WRITE setProvince NOTIFY BDSDataChanged)
//    Q_PROPERTY(QString city READ getCity WRITE setCity NOTIFY BDSDataChanged)
    Q_PROPERTY(double priceUnit READ getPriceUnit WRITE setPriceUnit NOTIFY BDSDataChanged)
    Q_PROPERTY(double price READ getPrice WRITE setPrice NOTIFY BDSDataChanged)
    Q_PROPERTY(int bdsPoint READ getPoint WRITE setPoint NOTIFY BDSDataChanged)
    Q_PROPERTY(bool bdsStatus READ getSubmitStatus WRITE setSubmitStatus NOTIFY BDSDataChanged)
    Q_PROPERTY(QString bdsCreatedDate READ getCreatedDate NOTIFY BDSDataChanged)

    Q_PROPERTY(int landId READ getLandid WRITE setLandid NOTIFY BDSDataChanged)
    Q_PROPERTY(int landType READ getLandtype WRITE setLandtype NOTIFY BDSDataChanged)
    Q_PROPERTY(double landWide READ getLandwide WRITE setLandwide NOTIFY BDSDataChanged)
    Q_PROPERTY(double landLong READ getLandlong WRITE setLandlong NOTIFY BDSDataChanged)
    Q_PROPERTY(double landDefaultSquare READ getDefaultsquare WRITE setDefaultsquare NOTIFY BDSDataChanged)
    Q_PROPERTY(double landRealitySquare READ getRealitysquare WRITE setRealitysquare NOTIFY BDSDataChanged)
    Q_PROPERTY(double landAgriculturalLandSquare READ getLandagriculturallandsquare WRITE setLandagriculturallandsquare NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landShape READ getLandshape WRITE setLandshape NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landJuridical READ getLandjuridical WRITE setLandjuridical NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landProjectName READ getLandProjectname WRITE setLandProjectname NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landDirection READ getLandDirection WRITE setLandDirection NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landPosition READ getLandPosition WRITE setLandPosition NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landPlanningType READ getLandPlanningType WRITE setLandPlanningType NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landLongitude READ getLandLongitude WRITE setLandLongitude  NOTIFY BDSDataChanged)
    Q_PROPERTY(QString landLatitude READ getLandLatitude WRITE setLandLatitude NOTIFY BDSDataChanged)

    Q_PROPERTY(int bedRooms READ bedRooms WRITE setBedRooms NOTIFY BDSDataChanged)
    Q_PROPERTY(int livingRooms READ livingRooms WRITE setLivingRooms NOTIFY BDSDataChanged)
    Q_PROPERTY(int toilets READ toilets WRITE setToilets NOTIFY BDSDataChanged)
    Q_PROPERTY(int kitchens READ kitchens WRITE setKitchens NOTIFY BDSDataChanged)
    Q_PROPERTY(bool terraceValid READ terraceValid WRITE setTerraceValid NOTIFY BDSDataChanged)
    Q_PROPERTY(bool yardValid READ yardValid WRITE setYardValid NOTIFY BDSDataChanged)
    Q_PROPERTY(bool garageValid READ garageValid WRITE setGarageValid NOTIFY BDSDataChanged)


    Q_PROPERTY(double streetWidth READ getStreetwidth WRITE setStreetwidth NOTIFY BDSDataChanged)

    Q_PROPERTY(int hostId READ getHostid WRITE setHostid NOTIFY BDSDataChanged)
    Q_PROPERTY(QString hostFullName READ getHostfullname WRITE setHostfullname NOTIFY BDSDataChanged)
    Q_PROPERTY(int hostAge READ getHostage WRITE setHostage NOTIFY BDSDataChanged)
    Q_PROPERTY(bool hostGender READ getHostgender WRITE setHostgender NOTIFY BDSDataChanged)
    Q_PROPERTY(QString hostPhone READ getHostphone WRITE setHostphone NOTIFY BDSDataChanged)
    Q_PROPERTY(QString hostAddress READ getHostaddress WRITE setHostaddress NOTIFY BDSDataChanged)
    Q_PROPERTY(QString hostCompany READ getHostcompany WRITE setHostcompany NOTIFY BDSDataChanged)
    Q_PROPERTY(int hostType READ getHosttype WRITE setHosttype NOTIFY BDSDataChanged)
    Q_PROPERTY(QString hostEmail READ getHostEmail WRITE setHostEmail NOTIFY BDSDataChanged)

    Q_PROPERTY(int contactId READ getContactid WRITE setContactid NOTIFY BDSDataChanged)
    Q_PROPERTY(QString contactFullName READ getContactfullname WRITE setContactfullname NOTIFY BDSDataChanged)
    Q_PROPERTY(int contactAge READ getContactage WRITE setContactage NOTIFY BDSDataChanged)
    Q_PROPERTY(bool contactGender READ getContactgender WRITE setContactgender NOTIFY BDSDataChanged)
    Q_PROPERTY(QString contactPhone READ getContactphone WRITE setContactphone NOTIFY BDSDataChanged)
    Q_PROPERTY(QString contactAddress READ getContactaddress WRITE setContactaddress NOTIFY BDSDataChanged)
    Q_PROPERTY(QString contactCompany READ getContactcompany WRITE setContactcompany NOTIFY BDSDataChanged)
    Q_PROPERTY(int contactType READ getContacttype WRITE setContacttype NOTIFY BDSDataChanged)
    Q_PROPERTY(QString contactEmail READ getContactEmail WRITE setContactEmail NOTIFY BDSDataChanged)

    Q_PROPERTY(double roadSquare READ getRoadSquare WRITE setRoadSquare NOTIFY BDSDataChanged)
    Q_PROPERTY(double constructionSquare READ getConstructionSquare WRITE setConstructionSquare NOTIFY BDSDataChanged)
    Q_PROPERTY(double floorSquare READ getFloorSquare WRITE setFloorSquare NOTIFY BDSDataChanged)
    Q_PROPERTY(int floors READ getFloors WRITE setFloors NOTIFY BDSDataChanged)
    Q_PROPERTY(double constructionHeight READ getConstructionHeight WRITE setConstructionHeight NOTIFY BDSDataChanged)
    Q_PROPERTY(QString usingStatus READ getUsingStatus WRITE setUsingStatus NOTIFY BDSDataChanged)
    Q_PROPERTY(QString houseQuality READ getHouseQuality WRITE setHouseQuality NOTIFY BDSDataChanged)
    Q_PROPERTY(double discussedPrice READ getDiscussedPrice WRITE setDiscussedPrice NOTIFY BDSDataChanged)
    Q_PROPERTY(QString tinhtrangthechap READ getTinhtrangthechap WRITE setTinhtrangthechap NOTIFY BDSDataChanged)
    Q_PROPERTY(QString completeTypes READ getCompleteTypes WRITE setCompleteTypes NOTIFY BDSDataChanged)

    Q_PROPERTY(QStringList houseImageList READ getHouseImageList NOTIFY houseImageListChanged)
    Q_PROPERTY(QStringList landPlanningImageList READ getLandPlanningImageList NOTIFY landPlanningImageListChanged)
    Q_PROPERTY(QStringList legacyImageList READ getLegacyImageList NOTIFY legacyImageListChanged)

    int m_id = DEFAULT_SELECTED_ID;
    SimpleData* m_landPosition = new SimpleData();
    QString m_homenumber = DEFAULT_TEXT;
    QString m_street = DEFAULT_TEXT;
    SimpleData* m_type = new SimpleData();
    SimpleData* m_province = new SimpleData();

    int m_landId = DEFAULT_INT_VALUE;
    int m_landType = DEFAULT_INT_VALUE;
    double m_landWide = DEFAULT_INT_VALUE;
    double m_landLong = DEFAULT_INT_VALUE;
    double m_landAgriculturalLandSquare = DEFAULT_INT_VALUE;
    SimpleData* m_landShape = new SimpleData();
    SimpleData* m_landPlanningType = new SimpleData();
    SimpleData* m_informationType = new SimpleData();
    SimpleData* m_landJuridical = new SimpleData();
    SimpleData* m_landJuridicalStatus = new SimpleData();
    QString m_landProjectName = DEFAULT_TEXT;
    double m_streetWidth = DEFAULT_INT_VALUE;
    SimpleData* m_landDirection = new SimpleData();
    double m_landDefaultSquare = DEFAULT_INT_VALUE;
    double m_landRealitySquare = DEFAULT_INT_VALUE;
    QString m_landLongitude = DEFAULT_TEXT;
    QString m_landLatide = DEFAULT_TEXT;
    SimpleData* m_completeTypes = new SimpleData();

    int m_bedRooms = DEFAULT_INT_VALUE;
    int m_livingRooms = DEFAULT_INT_VALUE;
    int m_toilets = DEFAULT_INT_VALUE;
    int m_kitchens = DEFAULT_INT_VALUE;
    bool m_terraceValid = false;
    bool m_yardValid = false;
    bool m_garageValid = false;

    int m_hostId = DEFAULT_SELECTED_ID;
    QString m_hostFullName = DEFAULT_TEXT;
    int m_hostAge = DEFAULT_INT_VALUE;
    bool m_hostGender = true;
    QString m_hostPhone = DEFAULT_TEXT;
    QString m_hostAddress = DEFAULT_TEXT;
    QString m_hostCompany = DEFAULT_TEXT;
    int m_hostType = DEFAULT_SELECTED_ID;
    QString m_hostEmail = DEFAULT_TEXT;

    int m_contactId = DEFAULT_SELECTED_ID;
    QString m_contactFullName = DEFAULT_TEXT;
    int m_contactAge = DEFAULT_INT_VALUE;
    bool m_contactGender = true;
    QString m_contactPhone = DEFAULT_TEXT;
    QString m_contactAddress = DEFAULT_TEXT;
    QString m_contactCompany = DEFAULT_TEXT;
    int m_contactType = DEFAULT_SELECTED_ID;
    QString m_contactEmail = DEFAULT_TEXT;

    double m_RoadSquare = DEFAULT_INT_VALUE;
    double m_ConstructionSquare = DEFAULT_INT_VALUE;
    double m_FloorSquare = DEFAULT_INT_VALUE;
    int m_Floors = DEFAULT_INT_VALUE;
    double m_ConstructionHeight = DEFAULT_INT_VALUE;
    QString m_Longitude = DEFAULT_TEXT;
    QString m_Latitude = DEFAULT_TEXT;
    SimpleData* m_UsingStatus = new SimpleData();
//    SimpleData* m_FurnituresStatus = new SimpleData();
    SimpleData* m_HouseQuality = new SimpleData();
    double m_priceUnit = DEFAULT_INT_VALUE;
    double m_price = DEFAULT_INT_VALUE;
    double m_DiscussedPrice = DEFAULT_INT_VALUE;
    QString m_tinhtrangthechap = DEFAULT_TEXT;

    bool m_SubmitStatus = false;
    int m_point = DEFAULT_INT_VALUE;
    QString m_CreatedDate = DEFAULT_TEXT;
    QString m_Source = DEFAULT_TEXT;
    QString m_SourceLink = DEFAULT_TEXT;

    QList<QObject*> m_lstHouseImageList;
    QList<QObject*> m_lstLandPlanningImageList;
    QList<QObject*> m_lstLegacyImageList;

    QMap<QString,int> m_mapPointList;

public:
    SimpleData* Ward = new SimpleData();
    SimpleData* District = new SimpleData();
    QString ownerID = "";
    explicit BDSData(QObject *parent = nullptr);
    ~BDSData();
    QJsonObject JSONData;
    QList<QObject*> HouseImageList();
    QList<QObject*> LandPlanningImageList();
    QList<QObject*> LegacyImageList();
    QList<QObject*> ImageList();

    int getId();
    int getTypeId();
    QString getType();
    QString getLandPosition();
    QString getHomenumber();
    QString getStreet();
    QString getWard();
    int getWardId();
    QString getDistrict();
    int getDistrictId();
    QString getProvince();
    int getProvinceId();
//    QString getCity();
    int getLandid();
    int getLandtype();
    double getLandwide();
    double getLandlong();
    double getLandagriculturallandsquare();
    QString getLandshape();
    QString getLandPlanningType();
    QString getLandjuridical();
    QString getLandJuridicalStatus();
    QString getLandProjectname();
    double getStreetwidth();
    QString getLandDirection();
    double getDefaultsquare();
    double getRealitysquare();
    QString getLandLongitude();
    QString getLandLatitude();

    int bedRooms();
    int livingRooms();
    int toilets();
    int kitchens();
    bool terraceValid();
    bool yardValid();
    bool garageValid();


    int getHostid();
    QString getHostfullname();
    int getHostage();
    bool getHostgender();
    QString getHostphone();
    QString getHostaddress();
    QString getHostcompany();
    int getHosttype();
    QString getHostEmail();

    int getContactid();
    QString getContactfullname();
    int getContactage();
    bool getContactgender();
    QString getContactphone();
    QString getContactaddress();
    QString getContactcompany();
    int getContacttype();
    QString getContactEmail();

    double getRoadSquare();
    double getConstructionSquare();
    double getFloorSquare();
    int getFloors();
    double getConstructionHeight();
    QString getUsingStatus();
    QString getHouseQuality();
    double getPriceUnit();
    double getPrice();
    double getDiscussedPrice();
    QString getTinhtrangthechap();
    QString getCompleteTypes();
    bool getSubmitStatus();
    QString getCreatedDate();
    int getPoint();

    QStringList getHouseImageList();
    QStringList getLandPlanningImageList();
    QStringList getLegacyImageList();

    void setId(int newValue);
    void setTypeId(int newValue);
    void setType(QString newValue);
    void setLandPosition(QString newValue);
    void setLandPositionId(int newValue);
    void setHomenumber(QString newValue);
    void setStreet(QString newValue);
    void setWard(QString newValue);
    void setWardId(int newValue);
    void setDistrict(QString newValue);
    void setDistrictId(int newValue);
    void setProvince(QString newValue);
    void setProvinceId(int newValue);
//    void setCity(QString newValue);
    void setLandid(int newValue);
    void setLandtype(int newValue);
    void setLandwide(double newValue);
    void setLandlong(double newValue);
    void setLandagriculturallandsquare(double newValue);
    void setLandshape(QString newValue);
    void setLandshapeId(int newValue);
    void setLandPlanningType(QString newValue);
    void setLandPlanningTypeId(int newValue);
    void setInformationType(QString newValue);
    void setInformationTypeId(int newValue);
    void setLandjuridical(QString newValue);
    void setLandjuridicalId(int newValue);
    void setLandjuridicalStatus(QString newValue);
    void setLandjuridicalStatusId(int newValue);
    void setLandProjectname(QString newValue);
    void setStreetwidth(double newValue);
    void setLandDirection(QString newValue);
    void setLandDirectionId(int newValue);
    void setLandLongitude(QString newLongitude);
    void setLandLatitude(QString newLatitude);
    void setDefaultsquare(double newValue);
    void setRealitysquare(double newValue);
    void setHostid(int newValue);
    void setHostfullname(QString newValue);
    void setHostage(int newValue);
    void setHostgender(bool newValue);
    void setHostphone(QString newValue);
    void setHostaddress(QString newValue);
    void setHostcompany(QString newValue);
    void setHosttype(int newValue);
    void setHostEmail(QString newValue);

    void setBedRooms(int newValue);
    void setLivingRooms(int newValue);
    void setToilets(int newValue);
    void setKitchens(int newValue);
    void setTerraceValid(bool newValue);
    void setYardValid(bool newValue);
    void setGarageValid(bool newValue);

    void setContactid(int newValue);
    void setContactfullname(QString newValue);
    void setContactage(int newValue);
    void setContactgender(bool newValue);
    void setContactphone(QString newValue);
    void setContactaddress(QString newValue);
    void setContactcompany(QString newValue);
    void setContacttype(int newValue);
    void setContactEmail(QString newValue);
    void setRoadSquare(double newValue);
    void setConstructionSquare(double newValue);
    void setFloorSquare(double newValue);
    void setFloors(int newValue);
    void setConstructionHeight(double newValue);
    void setUsingStatus(QString newValue);
    void setUsingStatusId(int newValue);
    void setHouseQuality(QString newValue);
    void setHouseQualityId(int newValue);
    void setCompleteTypes(QString newValue);
    void setCompleteTypesId(int newValue);
    void setPriceUnit(double newValue);
    void setPrice(double newValue);
    void setDiscussedPrice(double newValue);
    void setTinhtrangthechap(QString newValue);
    void setSubmitStatus(bool newValue);
    void setPoint(int newValue);
    void setCreatedDate(QString newValue);

    QJsonObject convertToJsonObj();
    void importFromJsonObj(QJsonObject jsObj);
    void importFromJsonCrawlObj(QJsonObject jsObj);
    int calculateDataPoint();
    void addImage(QString strImgType, QString strImgId, QString strImgPreview);
    void deleteImage(QString strImgType, int nImgIndex);
    void captureImage(QString strUID, QString strImgType, QString strImgId, QString strImgPath);
    void updateContactInfo(QString strName, QString strSoDienThoai,
                           QString strEmail, QString strDiachi,
                           QString strGioiTinh, QString strDoTuoi);
    void updateHostInfo(QString strName, QString strSoDienThoai,
                        QString strEmail, QString strDiachi,
                        QString strGioiTinh, QString strDoTuoi);
signals:
    void BDSDataChanged();
    void houseImageListChanged();
    void landPlanningImageListChanged();
    void legacyImageListChanged();

public slots:
};

#endif // BDSDATA_H
