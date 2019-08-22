#include "bdsdata.h"
BDSData::BDSData(QObject *parent) : QObject(parent)
{
    QString tempData =
            "{\"BedRooms\":-1,\"Checker\":{\"Id\":-1,\"FullName\":\"\",\"Email\":\"\",\"Phone\":\"\","
            "\"Address\":\"\"},\"City\":\"\",\"CollectionPoints\":-1,\"Complete\":{\"Id\":-1,\"Name\":\"\","
            "\"DisplayName\":\"\",\"ParentId\":-1},\"ConstructionSquare\":-1,\"Contact\":{\"FullName\":\"\","
            "\"Age\":-1,\"Gender\":false,\"Phone\":\"\",\"Address\":\"\",\"Type\":-1,\"Id\":-1,\"Company\":\"\","
            "\"Email\":\"\"},\"CreatedBy\":{\"Id\":-1,\"FullName\":\"\",\"Email\":\"\",\"Phone\":\"\","
            "\"Address\":\"\"},\"CreatedDate\":\"\",\"DataSources\":[{\"Type\":-1,\"Link\":\"\",\"Id\":-1,"
            "\"RealEstateID\":-1,\"DataContent\":\"\",\"FileName\":\"\"}],\"DateOfPost\":\"\","
            "\"DefaultSquare\":-1,\"Direction\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},"
            "\"DiscussedPrice\":-1,\"District\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},"
            "\"FloorSquare\":-1,\"Floors\":-1,\"Furniture\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\","
            "\"ParentId\":-1},\"Garage\":false,\"Height\":-1,\"HomeNumber\":\"\","
//            "\"Host\":{\"FullName\":\"\",""\"Age\":-1,\"Gender\":false,\"Phone\":\"\",\"Address\":\"\",\"Type\":-1,\"Id\":-1,\"Company\":\"\","
//            "\"Email\":\"\"},\"Id\":-1,"
            "\"InfomationType\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\","
            "\"ParentId\":-1},\"Inputter\":{\"Id\":-1,\"FullName\":\"\",\"Email\":\"\",\"Phone\":\"\",\"Address\":\"\"},"
            "\"InvestmentPoints\":-1,\"Kitchen\":-1,\"Land\":{\"AgriculturalLandSquare\":-1,"
            "\"Juridical\":{\"DisplayName\":\"\",\"Id\":-1,\"Name\":\"\",\"ParentId\":-1},"
            "\"LandPlanningType\":{\"DisplayName\":\"\",\"Id\":-1,\"Name\":\"\",\"ParentId\":-1},"
            "\"Long\":-1,\"Shape\":{\"DisplayName\":\"\",\"Id\":-1,\"Name\":\"\",\"ParentId\":-1},"
            "\"Type\":-1,\"Wide\":-1,\"Id\":-1,\"RoadSquare\":-1,\"JuridicalStatus\":{\"Id\":-1,\"Name\":\"\","
            "\"DisplayName\":\"\",\"ParentId\":-1}},\"Latitude\":\"\",\"LivingRoom\":-1,\"LocationType\":-1,"
            "\"Longitude\":\"\",\"ModifiedDate\":\"\",\"ModifyBy\":{\"Id\":-1,\"FullName\":\"\",\"Email\":"
            "\"\",\"Phone\":\"\",\"Address\":\"\"},\"Note\":\"\",\"Position\":{\"Id\":-1,\"Name\":\"\","
            "\"DisplayName\":\"\",\"ParentId\":-1},\"Price\":-1,\"PriceUnit\":-1,\"ProjectName\":\"\","
            "\"Province\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},\"Quality\":{\"Id"
            "\":-1,\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},\"RealitySquare\":-1,\"Sales\":{\"Id"
            "\":-1,\"FullName\":\"\",\"Email\":\"\",\"Phone\":\"\",\"Address\":\"\"},\"Source\":{\"Id\":-1,"
            "\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},\"SourceLink\":\"\",\"Stairs\":-1,\"Status"
            "\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},\"Street\":\"\",\"StreetWidth"
            "\":-1,\"Terrace\":false,\"Toilets\":-1,\"Type\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\","
            "\"ParentId\":-1},\"UsingStatus\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},"
            "\"Ward\":{\"Id\":-1,\"Name\":\"\",\"DisplayName\":\"\",\"ParentId\":-1},\"Yard\":false}";

    JSONData = QJsonDocument::fromJson(tempData.toUtf8()).object();

    m_mapPointList.insert(c_NHADATVN_HomeNumber, POINT_HOMENUMBER);
    m_mapPointList.insert(c_NHADATVN_Street, POINT_STREETNAME);
    m_mapPointList.insert(c_NHADATVN_ProjectName, POINT_PROJECTNAME);
    m_mapPointList.insert(c_NHADATVN_StreetWidth, POINT_STREETWIDTH);
    m_mapPointList.insert(c_NHADATVN_DefaultSquare, POINT_DEFAULTSQUARE);
    m_mapPointList.insert(c_NHADATVN_RealitySquare, POINT_REALITYSQUARE);
    m_mapPointList.insert(c_NHADATVN_PriceUnit, POINT_PRICEUNIT);
    m_mapPointList.insert(c_NHADATVN_Price, POINT_PRICE);
    m_mapPointList.insert(c_NHADATVN_Floors, POINT_FLOORS);
    m_mapPointList.insert(c_NHADATVN_ConstructionHeight, POINT_CONSTRUCTIONHEIGHT);
    m_mapPointList.insert(c_NHADATVN_Longitude, POINT_POSITION);
    m_mapPointList.insert(c_NHADATVN_Terrace, POINT_TIENICHTRONGNHA);
    m_mapPointList.insert(c_NHADATVN_DiscussedPrice, POINT_DISCUSSEDPRICE);
    m_mapPointList.insert(c_NHADATVN_ConstructionSquare, POINT_CONSTRUCTIONSQUARE);
    m_mapPointList.insert(c_NHADATVN_FloorSquare, POINT_FLOORSQUARE);

    m_mapPointList.insert(c_NHADATVN_District, POINT_DISTRICT);
    m_mapPointList.insert(c_NHADATVN_Ward, POINT_WARD);
    m_mapPointList.insert(c_NHADATVN_Province, POINT_PROVINCE);
    m_mapPointList.insert(c_NHADATVN_Position, POINT_POSITION);
    m_mapPointList.insert(c_NHADATVN_Direction, POINT_DIRECTION);
    m_mapPointList.insert(c_NHADATVN_UsingStatus, POINT_USINGSTATUS);
    m_mapPointList.insert(c_NHADATVN_Complete, POINT_COMPLETETYPES);
    m_mapPointList.insert(c_NHADATVN_Quality, POINT_QUALITY);
    m_mapPointList.insert(c_NHADATVN_Shape, POINT_SHAPE);
    m_mapPointList.insert(c_NHADATVN_LandPlanningType, POINT_LANDPLANNINGTYPE);
    m_mapPointList.insert(c_NHADATVN_Juridical, POINT_JURIDICAL);
    m_mapPointList.insert(c_NHADATVN_Type, POINT_TYPE);


//    m_mapPointList.insert(c_NHADATVN_Latitude, POINT_;
    m_mapPointList.insert(c_NHADATVN_BedRooms, POINT_BEDROOM);
    m_mapPointList.insert(c_NHADATVN_Toilets, POINT_TOILET);
    m_mapPointList.insert(c_NHADATVN_LivingRoom, POINT_LIVINGROOM);
    m_mapPointList.insert(c_NHADATVN_Kitchen, POINT_KITCHEN);
//    m_mapPointList.insert(c_NHADATVN_InfomationType, POINT_IMAGE;


//    QJsonObject tempObjHost;
    m_mapPointList.insert(c_NHADATVN_FullName, POINT_CONTACTNAME);
    m_mapPointList.insert(c_NHADATVN_Age, POINT_CONTACTAGE);
    m_mapPointList.insert(c_NHADATVN_Phone, POINT_CONTACTPHONE);
    m_mapPointList.insert(c_NHADATVN_Gender, POINT_CONTACTGENDER);
    m_mapPointList.insert(c_NHADATVN_Address, POINT_CONTACTADDRESS);
    m_mapPointList.insert(c_NHADATVN_Company, POINT_CONTACTCOMPANY);
    m_mapPointList.insert(c_NHADATVN_Type, POINT_CONTACTTYPE);
//    m_mapPointList.insert(c_NHADATVN_Email] = m_hostEmail;
//    m_mapPointList.insert(c_NHADATVN_Id] = m_hostId;
//    JSONData[c_NHADATVN_Host] = tempObjHost;

//    QJsonArray imageArr;
//    QList<QObject*> tempListImage = ImageList();
//    for (int i = 0; i < tempListImage.count(); ++i) {
//        ImageData* tempImgData = dynamic_cast<ImageData*>(tempListImage[i]);
//        QJsonObject imageObj;
//        imageObj[c_NHADATVN_ID] = ownerID;
//        imageObj[c_NHADATVN_Link] = tempImgData->getImageUrl();
//        QString tempImgType = tempImgData->getImageType();
//        if(tempImgType == IMAGE_TYPE_GIAYTONHA){
//            imageObj[c_NHADATVN_Type] = 1;
//        }else if(tempImgType == IMAGE_TYPE_QUYHOACHLOGIOI){
//            imageObj[c_NHADATVN_Type] = 3;
//        }else{
//            imageObj[c_NHADATVN_Type] = 2;
//        }
//        imageArr.append(imageObj);
//    }
//    JSONData[c_NHADATVN_DataSources] = imageArr;
//    return JSONData;
}

BDSData::~BDSData()
{
    if (!m_landPosition){
        delete m_landPosition;
        m_landPosition = nullptr;
    }
    if (!m_type){
        delete m_type;
        m_type = nullptr;
    }
    if (!m_province){
        delete m_province;
        m_province = nullptr;
    }
    if (!m_landShape){
        delete m_landShape;
        m_landShape = nullptr;
    }
    if (!m_landPlanningType){
        delete m_landPlanningType;
        m_landPlanningType = nullptr;
    }
    if (!m_informationType){
        delete m_informationType;
        m_informationType = nullptr;
    }
    if (!m_landJuridical){
        delete m_landJuridical;
        m_landJuridical = nullptr;
    }

    if (!m_landJuridicalStatus){
        delete m_landJuridicalStatus;
        m_landJuridicalStatus = nullptr;
    }

    if (!m_landDirection){
        delete m_landDirection;
        m_landDirection = nullptr;
    }
    if (!m_completeTypes){
        delete m_completeTypes;
        m_completeTypes = nullptr;
    }
    if (!m_UsingStatus){
        delete m_UsingStatus;
        m_UsingStatus = nullptr;
    }
    if (!m_HouseQuality){
        delete m_HouseQuality;
        m_HouseQuality = nullptr;
    }
    if (!Ward){
        delete Ward;
        Ward = nullptr;
    }
    if (!District){
        delete District;
        District = nullptr;
    }

    if (m_lstHouseImageList.count() > 0){
        for (int i = 0; i < m_lstHouseImageList.count(); i++){
            QObject* oldItem = m_lstHouseImageList.takeFirst();
            delete oldItem;
            oldItem = nullptr;
        }
    }

    if (m_lstLegacyImageList.count() > 0){
        for (int i = 0; i < m_lstLegacyImageList.count(); i++){
            QObject* oldItem = m_lstLegacyImageList.takeFirst();
            delete oldItem;
            oldItem = nullptr;
        }
    }

    if (m_lstLandPlanningImageList.count() > 0){
        for (int i = 0; i < m_lstLandPlanningImageList.count(); i++){
            QObject* oldItem = m_lstLandPlanningImageList.takeFirst();
            delete oldItem;
            oldItem = nullptr;
        }
    }
}

QList<QObject *> BDSData::HouseImageList()
{
    return m_lstHouseImageList;
}

QList<QObject *> BDSData::LandPlanningImageList()
{
    return m_lstLandPlanningImageList;
}

QList<QObject *> BDSData::LegacyImageList()
{
    return m_lstLegacyImageList;
}

QList<QObject *> BDSData::ImageList()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QList<QObject*> newList;
    for (int i = 0; i < m_lstHouseImageList.count(); ++i) {
        newList.append(m_lstHouseImageList[i]);
    }

    for (int i = 0; i < m_lstLandPlanningImageList.count(); ++i) {
        newList.append(m_lstLandPlanningImageList[i]);
    }

    for (int i = 0; i < m_lstLegacyImageList.count(); ++i) {
        newList.append(m_lstLegacyImageList[i]);
    }
#ifdef DEBUG_MODE
    qDebug() << newList.count();
#endif
    return newList;
}
int BDSData::getId()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_id;
}
QString BDSData::getProvince()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << m_province->dataDisplayName();
#endif
    return m_province->dataDisplayName();
}

int BDSData::getProvinceId()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_province->dataId();
}
QString BDSData::getDistrict()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << District->dataDisplayName();
#endif
    return District->dataDisplayName();
}

int BDSData::getDistrictId()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return District->dataId();
}
int BDSData::getWardId()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return Ward->dataId();
}

int BDSData::getTypeId()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_type->dataId();
}

QString BDSData::getType()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_type->dataDisplayName();
}
QString BDSData::getContactfullname()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactFullName;
}
QString BDSData::getContactphone()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactPhone;
}
int BDSData::getContactage()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactAge;
}
bool BDSData::getContactgender()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactGender;
}
QString BDSData::getContactaddress()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactAddress;
}
QString BDSData::getContactcompany()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactCompany;
}
int BDSData::getContacttype()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactType;
}

QString BDSData::getContactEmail()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactEmail;
}

int BDSData::getContactid()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_contactId;
}
QString BDSData::getHomenumber()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_homenumber;
}
QString BDSData::getStreet()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_street;
}

QString BDSData::getWard()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << Ward->dataDisplayName();
#endif
    return Ward->dataDisplayName();
}
QString BDSData::getLandPosition()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landPosition->dataDisplayName();
}
double BDSData::getRoadSquare()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_RoadSquare;
}
QString BDSData::getLandProjectname()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landProjectName;
}
double BDSData::getLandwide()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landWide;
}
double BDSData::getLandlong()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landLong;
}
double BDSData::getDefaultsquare()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landDefaultSquare;
}
double BDSData::getRealitysquare()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landRealitySquare;
}

QString BDSData::getLandLongitude()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landLongitude;
}

QString BDSData::getLandLatitude()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landLatide;
}

int BDSData::bedRooms()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_bedRooms;
}

int BDSData::livingRooms()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_livingRooms;
}

int BDSData::toilets()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_toilets;
}

int BDSData::kitchens()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_kitchens;
}

bool BDSData::terraceValid()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_terraceValid;
}

bool BDSData::yardValid()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_yardValid;
}

bool BDSData::garageValid()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_garageValid;
}

double BDSData::getLandagriculturallandsquare()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landAgriculturalLandSquare;
}
QString BDSData::getLandshape()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landShape->dataDisplayName();
}

QString BDSData::getLandPlanningType()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landPlanningType->dataDisplayName();
}
int BDSData::getLandtype()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landType;
}
int BDSData::getLandid()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landId;
}
double BDSData::getStreetwidth()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_streetWidth;
}
QString BDSData::getLandDirection()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landDirection->dataDisplayName();
}
double BDSData::getConstructionSquare()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_ConstructionSquare;
}
double BDSData::getFloorSquare()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_FloorSquare;
}
int BDSData::getFloors()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_Floors;
}
double BDSData::getConstructionHeight()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_ConstructionHeight;
}
QString BDSData::getUsingStatus()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_UsingStatus->dataDisplayName();
}
QString BDSData::getHouseQuality()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_HouseQuality->dataDisplayName();
}
double BDSData::getPriceUnit()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_priceUnit;
}
double BDSData::getPrice()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_price;
}
double BDSData::getDiscussedPrice()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_DiscussedPrice;
}
QString BDSData::getLandjuridical()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landJuridical->dataDisplayName();
}

QString BDSData::getLandJuridicalStatus()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_landJuridical->dataDisplayName();
}

QString BDSData::getTinhtrangthechap()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_tinhtrangthechap;
}

QString BDSData::getCompleteTypes()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_completeTypes->dataDisplayName();
}

bool BDSData::getSubmitStatus()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_SubmitStatus;
}

QString BDSData::getCreatedDate()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_CreatedDate;
}

int BDSData::getPoint()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_point;
}

QStringList BDSData::getHouseImageList()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QStringList newList;
    for (int i = 0; i < m_lstHouseImageList.count(); ++i) {
        ImageData* tempData = dynamic_cast<ImageData*>(m_lstHouseImageList[i]);
        newList.append(tempData->getImageSrc());
    }
    return newList;
}

QStringList BDSData::getLandPlanningImageList()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QStringList newList;
    for (int i = 0; i < m_lstLandPlanningImageList.count(); ++i) {
        ImageData* tempData = dynamic_cast<ImageData*>(m_lstLandPlanningImageList[i]);
        newList.append(tempData->getImageSrc());
    }
    return newList;

}

QStringList BDSData::getLegacyImageList()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QStringList newList;
    for (int i = 0; i < m_lstLegacyImageList.count(); ++i) {
        ImageData* tempData = dynamic_cast<ImageData*>(m_lstLegacyImageList[i]);
        newList.append(tempData->getImageSrc());
    }
    return newList;
}

QString BDSData::getHostfullname()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostFullName;
}
QString BDSData::getHostphone()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostPhone;
}
int BDSData::getHostage()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostAge;
}
bool BDSData::getHostgender()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostGender;
}
QString BDSData::getHostaddress()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostAddress;
}
QString BDSData::getHostcompany()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostCompany;
}
int BDSData::getHosttype()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostType;
}

QString BDSData::getHostEmail()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostEmail;
}
int BDSData::getHostid()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    return m_hostId;
}



void BDSData::setId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_id != newValue){
        m_id= newValue;
        emit BDSDataChanged();
    }
}
void BDSData::setProvince(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_province->dataDisplayName() != newValue){
        m_province->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setDistrict(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newValue;
#endif
    if(District->dataDisplayName() != newValue){
        District->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setDistrictId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newValue;
#endif
    if(District->dataId() != newValue){
        District->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setProvinceId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_province->dataId() != newValue){
        m_province->setDataId(newValue);
        emit BDSDataChanged();
    }
}
void BDSData::setWardId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(Ward->dataId() != newValue){
        Ward->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setTypeId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_type->dataId() != newValue){
        m_type->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setType(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_type->dataDisplayName() != newValue){
        m_type->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}
void BDSData::setContactfullname(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactFullName != newValue){
        m_contactFullName= newValue;
    }
}
void BDSData::setContactphone(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactPhone != newValue){
        m_contactPhone= newValue;
    }
}
void BDSData::setContactage(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactAge != newValue){
        m_contactAge= newValue;
    }
}
void BDSData::setContactgender(bool newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactGender != newValue){
        m_contactGender= newValue;
    }
}
void BDSData::setContactaddress(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactAddress != newValue){
        m_contactAddress= newValue;
    }
}
void BDSData::setContactcompany(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactCompany != newValue){
        m_contactCompany= newValue;
    }
}
void BDSData::setContacttype(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactType != newValue){
        m_contactType= newValue;
    }
}

void BDSData::setContactEmail(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactEmail != newValue){
        m_contactEmail= newValue;
    }
}
void BDSData::setContactid(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_contactId != newValue){
        m_contactId= newValue;
    }
}
void BDSData::setHomenumber(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_homenumber != newValue){
        m_homenumber= newValue;
    }
}
void BDSData::setStreet(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_street != newValue){
        m_street= newValue;
    }
}

void BDSData::setWard(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(Ward->dataDisplayName() != newValue){
        Ward->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}
void BDSData::setLandPosition(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << "newValue: " << newValue;
#endif
    if(m_landPosition->dataDisplayName() != newValue){
        m_landPosition->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setLandPositionId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << "newValue: " << newValue;
#endif
    if(m_landPosition->dataId() != newValue){
        m_landPosition->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setRoadSquare(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_RoadSquare != newValue){
        m_RoadSquare= newValue;
    }
}
void BDSData::setLandProjectname(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landProjectName != newValue){
        m_landProjectName= newValue;
    }
}
void BDSData::setLandwide(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landWide != newValue){
        m_landWide= newValue;
    }
}
void BDSData::setLandlong(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landLong != newValue){
        m_landLong= newValue;
    }
}
void BDSData::setDefaultsquare(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landDefaultSquare != newValue){
        m_landDefaultSquare= newValue;
    }
}
void BDSData::setRealitysquare(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landRealitySquare != newValue){
        m_landRealitySquare= newValue;
    }
}

void BDSData::setLandagriculturallandsquare(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landAgriculturalLandSquare != newValue){
        m_landAgriculturalLandSquare= newValue;
    }
}
void BDSData::setLandshape(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landShape->dataDisplayName() != newValue){
        m_landShape->setDataDisplayName(newValue);
    }
}

void BDSData::setLandshapeId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landShape->dataId() != newValue){
        m_landShape->setDataId(newValue);
    }
}

void BDSData::setLandPlanningType(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landPlanningType->dataDisplayName() != newValue){
        m_landPlanningType->setDataDisplayName(newValue);
    }
}

void BDSData::setLandPlanningTypeId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landPlanningType->dataId() != newValue){
        m_landPlanningType->setDataId(newValue);
    }
}

void BDSData::setInformationType(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_informationType->dataDisplayName() != newValue){
        m_informationType->setDataDisplayName(newValue);
    }
}

void BDSData::setInformationTypeId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_informationType->dataId() != newValue){
        m_informationType->setDataId(newValue);
    }
}

void BDSData::setLandtype(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landType != newValue){
        m_landType= newValue;
    }
}
void BDSData::setLandid(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landId != newValue){
        m_landId= newValue;
    }
}
void BDSData::setStreetwidth(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_streetWidth != newValue){
        m_streetWidth= newValue;
    }
}
void BDSData::setLandDirection(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landDirection->dataDisplayName() != newValue){
        m_landDirection->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setLandDirectionId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_landDirection->dataId() != newValue){
        m_landDirection->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setLandLongitude(QString newLongitude)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    m_landLongitude= newLongitude;
    emit BDSDataChanged();
}

void BDSData::setLandLatitude(QString newLatitude)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    m_landLatide = newLatitude;
    emit BDSDataChanged();
}

void BDSData::setConstructionSquare(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_ConstructionSquare != newValue){
        m_ConstructionSquare= newValue;
    }
}
void BDSData::setFloorSquare(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_FloorSquare != newValue){
        m_FloorSquare= newValue;
    }
}
void BDSData::setFloors(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_Floors != newValue){
        m_Floors= newValue;
    }
}
void BDSData::setConstructionHeight(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_ConstructionHeight != newValue){
        m_ConstructionHeight= newValue;
    }
}
void BDSData::setUsingStatus(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_UsingStatus->dataDisplayName() != newValue){
        m_UsingStatus->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setUsingStatusId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_UsingStatus->dataId() != newValue){
        m_UsingStatus->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setHouseQuality(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_HouseQuality->dataDisplayName() != newValue){
        m_HouseQuality->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setHouseQualityId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_HouseQuality->dataId() != newValue){
        m_HouseQuality->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setCompleteTypes(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_completeTypes->dataDisplayName() != newValue){
        m_completeTypes->setDataDisplayName(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setCompleteTypesId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_completeTypes->dataId() != newValue){
        m_completeTypes->setDataId(newValue);
        emit BDSDataChanged();
    }
}

void BDSData::setPriceUnit(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_priceUnit != newValue){
        m_priceUnit = newValue;
    }
}
void BDSData::setPrice(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_price != newValue){
        m_price= newValue;
    }
}
void BDSData::setDiscussedPrice(double newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_DiscussedPrice != newValue){
        m_DiscussedPrice= newValue;
    }
}
void BDSData::setLandjuridical(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newValue;
#endif
    if(m_landJuridical->dataDisplayName() != newValue){
        m_landJuridical->setDataDisplayName(newValue);
    }
}

void BDSData::setLandjuridicalId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newValue;
#endif
    if(m_landJuridical->dataId() != newValue){
        m_landJuridical->setDataId(newValue);
    }
}

void BDSData::setLandjuridicalStatus(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newValue;
#endif
    if(m_landJuridicalStatus->dataDisplayName() != newValue){
        m_landJuridicalStatus->setDataDisplayName(newValue);
    }
}

void BDSData::setLandjuridicalStatusId(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newValue;
#endif
    if(m_landJuridicalStatus->dataId() != newValue){
        m_landJuridicalStatus->setDataId(newValue);
    }
}
void BDSData::setTinhtrangthechap(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_tinhtrangthechap != newValue){
        m_tinhtrangthechap= newValue;
    }
}

void BDSData::setSubmitStatus(bool newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_SubmitStatus != newValue){
        m_SubmitStatus= newValue;
        emit BDSDataChanged();
    }
}

void BDSData::setPoint(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newValue;
#endif
    if(m_point != newValue){
        m_point = newValue;
    }
}

void BDSData::setCreatedDate(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_CreatedDate != newValue){
        m_CreatedDate = newValue;
    }
}
void BDSData::setHostfullname(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostFullName != newValue){
        m_hostFullName= newValue;
    }
}
void BDSData::setHostphone(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostPhone != newValue){
        m_hostPhone= newValue;
    }
}
void BDSData::setHostage(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostAge != newValue){
        m_hostAge= newValue;
    }
}
void BDSData::setHostgender(bool newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostGender != newValue){
        m_hostGender= newValue;
    }
}
void BDSData::setHostaddress(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostAddress != newValue){
        m_hostAddress= newValue;
    }
}
void BDSData::setHostcompany(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostCompany != newValue){
        m_hostCompany= newValue;
    }
}
void BDSData::setHosttype(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostType != newValue){
        m_hostType= newValue;
    }
}

void BDSData::setHostEmail(QString newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostEmail != newValue){
        m_hostEmail= newValue;
    }
}

void BDSData::setBedRooms(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_bedRooms != newValue){
        m_bedRooms = newValue;
    }
}

void BDSData::setLivingRooms(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_livingRooms != newValue){
        m_livingRooms = newValue;
    }
}

void BDSData::setToilets(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_toilets != newValue){
        m_toilets = newValue;
    }
}

void BDSData::setKitchens(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_kitchens != newValue){
        m_kitchens= newValue;
    }
}

void BDSData::setTerraceValid(bool newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_terraceValid != newValue){
        m_terraceValid= newValue;
    }
}

void BDSData::setYardValid(bool newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_yardValid != newValue){
        m_yardValid= newValue;
    }
}

void BDSData::setGarageValid(bool newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_garageValid != newValue){
        m_garageValid= newValue;
    }
}

void BDSData::setHostid(int newValue)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(m_hostId != newValue){
        m_hostId= newValue;
    }
}

QJsonObject BDSData::convertToJsonObj()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    JSONData[c_NHADATVN_Id] =  m_id;
    JSONData[c_NHADATVN_Type] =  m_type->convertToJSONObject();
    JSONData[c_NHADATVN_HomeNumber] =  m_homenumber;
    JSONData[c_NHADATVN_Street] =  m_street;
    JSONData[c_NHADATVN_Ward] =  Ward->convertToJSONObject();
    JSONData[c_NHADATVN_District] =  District->convertToJSONObject();
    JSONData[c_NHADATVN_Province] =  m_province->convertToJSONObject();
    JSONData[c_NHADATVN_ProjectName] =  m_landProjectName;
    JSONData[c_NHADATVN_StreetWidth] =  m_streetWidth;
    JSONData[c_NHADATVN_Position] = m_landPosition->convertToJSONObject();
    JSONData[c_NHADATVN_Direction] =  m_landDirection->convertToJSONObject();
    JSONData[c_NHADATVN_DefaultSquare] =  m_landDefaultSquare;
    JSONData[c_NHADATVN_RealitySquare] =  m_landRealitySquare;

    JSONData[c_NHADATVN_PriceUnit] =  m_priceUnit;
    JSONData[c_NHADATVN_Price] =  m_price;
    JSONData[c_NHADATVN_DiscussedPrice] =  m_DiscussedPrice;
    JSONData[c_NHADATVN_ConstructionSquare] =  m_ConstructionSquare;
    JSONData[c_NHADATVN_FloorSquare] =  m_FloorSquare;//;
    JSONData[c_NHADATVN_Floors] =  m_Floors;//;
    JSONData[c_NHADATVN_ConstructionHeight] =  m_ConstructionHeight;
    JSONData[c_NHADATVN_UsingStatus] =  m_UsingStatus->convertToJSONObject();
    JSONData[c_NHADATVN_Complete] =  m_completeTypes->convertToJSONObject();
    JSONData[c_NHADATVN_Longitude] = m_landLongitude;
    JSONData[c_NHADATVN_Latitude] = m_landLatide;
    JSONData[c_NHADATVN_BedRooms] =  m_bedRooms;
    JSONData[c_NHADATVN_Toilets] =  m_toilets;
    JSONData[c_NHADATVN_LivingRoom] =  m_livingRooms;
    JSONData[c_NHADATVN_Kitchen] =  m_kitchens;
    JSONData[c_NHADATVN_Quality] =  m_HouseQuality->convertToJSONObject();
    JSONData[c_NHADATVN_InfomationType] =  m_informationType->convertToJSONObject();
    JSONData[c_NHADATVN_SubmitStatus] =  m_SubmitStatus;
    JSONData[c_NHADATVN_CollectionPoints] =  m_point;
    JSONData[c_NHADATVN_CreatedDate] = m_CreatedDate;
    JSONData[c_NHADATVN_Terrace] =  m_terraceValid;
    JSONData[c_NHADATVN_Yard] =  m_yardValid;
    JSONData[c_NHADATVN_Garage] =  m_garageValid;

    QJsonObject tempObjLand;
    tempObjLand[c_NHADATVN_Type] =  m_landType;
    tempObjLand[c_NHADATVN_Shape] =  m_landShape->convertToJSONObject();
    tempObjLand[c_NHADATVN_Wide] =  m_landWide;
    tempObjLand[c_NHADATVN_Long] =  m_landLong;
    tempObjLand[c_NHADATVN_AgriculturalLandSquare] =  m_landAgriculturalLandSquare;
    tempObjLand[c_NHADATVN_LandPlanningType] =  m_landPlanningType->convertToJSONObject();
    tempObjLand[c_NHADATVN_RoadSquare] = m_RoadSquare;
    tempObjLand[c_NHADATVN_Shape] = m_landShape->convertToJSONObject();
    tempObjLand[c_NHADATVN_Juridical] =  m_landJuridical->convertToJSONObject();
    tempObjLand[c_NHADATVN_JuridicalStatus] = m_landJuridicalStatus->convertToJSONObject();
    tempObjLand[c_NHADATVN_Id] = m_landId;
    JSONData[c_NHADATVN_Land] = tempObjLand;

//    QJsonObject tempObjHost;
//    tempObjHost[c_NHADATVN_FullName] =  m_hostFullName;
//    tempObjHost[c_NHADATVN_Age] =  m_hostAge;
//    tempObjHost[c_NHADATVN_Phone] =  m_hostPhone;
//    tempObjHost[c_NHADATVN_Gender] =  m_hostGender;
//    tempObjHost[c_NHADATVN_Address] =  m_hostAddress;
//    tempObjHost[c_NHADATVN_Company] =  m_hostCompany;
//    tempObjHost[c_NHADATVN_Type] =  m_hostType;
//    tempObjHost[c_NHADATVN_Email] = m_hostEmail;
//    tempObjHost[c_NHADATVN_Id] = m_hostId;
//    JSONData[c_NHADATVN_Host] = tempObjHost;

    QJsonObject tempObjContact;
    tempObjContact[c_NHADATVN_FullName] =  m_contactFullName;
    tempObjContact[c_NHADATVN_Phone] =  m_contactPhone;
    tempObjContact[c_NHADATVN_Age] =  m_contactAge;
    tempObjContact[c_NHADATVN_Gender] =  m_contactGender;
    tempObjContact[c_NHADATVN_Address] =  m_contactAddress;
    tempObjContact[c_NHADATVN_Company] =  m_contactCompany;
    tempObjContact[c_NHADATVN_Type] =  m_contactType;
    tempObjContact[c_NHADATVN_Email] = m_contactEmail;
    tempObjContact[c_NHADATVN_Id] = m_contactId;
    JSONData[c_NHADATVN_Contact] = tempObjContact;


    QJsonArray imageArr;
    QList<QObject*> tempListImage = ImageList();
    for (int i = 0; i < tempListImage.count(); ++i) {
        ImageData* tempImgData = dynamic_cast<ImageData*>(tempListImage[i]);
        QJsonObject imageObj;
        imageObj[c_NHADATVN_ID] = ownerID;
        imageObj[c_NHADATVN_Link] = tempImgData->getImageUrl();
        QString tempImgType = tempImgData->getImageType();
        if(tempImgType == c_NHADATVN_IMAGE_TYPE_JURIDICAL){
            imageObj[c_NHADATVN_Type] = 1;
        }else if(tempImgType == c_NHADATVN_IMAGE_TYPE_LANDPLANNING){
            imageObj[c_NHADATVN_Type] = 3;
        }else{
            imageObj[c_NHADATVN_Type] = 2;
        }
        imageArr.append(imageObj);
    }
    JSONData[c_NHADATVN_DataSources] = imageArr;
    return JSONData;
}

void BDSData::importFromJsonObj(QJsonObject jsObj)
{
    JSONData =  QJsonDocument(jsObj).object();
     m_id = JSONData.value(c_NHADATVN_Id).toInt(DEFAULT_INT_VALUE);
     m_type->importFromJSON(JSONData.value(c_NHADATVN_Type).toObject());
     m_landProjectName = JSONData.value(c_NHADATVN_ProjectName).toString(DEFAULT_TEXT);
     Ward->importFromJSON(JSONData.value(c_NHADATVN_Ward).toObject());
     District->importFromJSON(JSONData.value(c_NHADATVN_District).toObject());
     m_province->importFromJSON(JSONData.value(c_NHADATVN_Province).toObject());
     m_homenumber = JSONData.value(c_NHADATVN_HomeNumber).toString(DEFAULT_TEXT);
     m_street = JSONData.value(c_NHADATVN_Street).toString(DEFAULT_TEXT);
     m_landDirection->importFromJSON(JSONData.value(c_NHADATVN_Direction).toObject());
     m_priceUnit = JSONData.value(c_NHADATVN_PriceUnit).toDouble(DEFAULT_INT_VALUE);
     m_price = JSONData.value(c_NHADATVN_Price).toDouble(DEFAULT_INT_VALUE);
     m_DiscussedPrice = JSONData.value(c_NHADATVN_DiscussedPrice).toDouble(DEFAULT_INT_VALUE);
     m_FloorSquare = JSONData.value(c_NHADATVN_FloorSquare).toDouble(DEFAULT_INT_VALUE);
     m_Floors = JSONData.value(c_NHADATVN_Floors).toInt(DEFAULT_INT_VALUE);
     m_ConstructionHeight = JSONData.value(c_NHADATVN_ConstructionHeight).toDouble(DEFAULT_INT_VALUE);
     m_landLongitude = JSONData.value(c_NHADATVN_Longitude).toString(DEFAULT_TEXT);
     m_landLatide = JSONData.value(c_NHADATVN_Latitude).toString(DEFAULT_TEXT);
     m_terraceValid = JSONData.value(c_NHADATVN_Terrace).toBool();
     m_yardValid = JSONData.value(c_NHADATVN_Yard).toBool();
     m_garageValid = JSONData.value(c_NHADATVN_Garage).toBool();
     m_toilets = JSONData.value(c_NHADATVN_Toilets).toInt(DEFAULT_INT_VALUE);
     m_kitchens = JSONData.value(c_NHADATVN_Kitchen).toInt(DEFAULT_INT_VALUE);
     m_livingRooms = JSONData.value(c_NHADATVN_LivingRoom).toInt(DEFAULT_INT_VALUE);
     m_streetWidth = JSONData.value(c_NHADATVN_StreetWidth).toDouble(DEFAULT_INT_VALUE);
     m_landDefaultSquare = JSONData.value(c_NHADATVN_DefaultSquare).toDouble(DEFAULT_INT_VALUE);
     m_landRealitySquare = JSONData.value(c_NHADATVN_RealitySquare).toDouble(DEFAULT_INT_VALUE);
     m_landPosition->importFromJSON(JSONData.value(c_NHADATVN_Position).toObject());
     m_ConstructionSquare = JSONData.value(c_NHADATVN_ConstructionSquare).toDouble(DEFAULT_INT_VALUE);
     m_UsingStatus->importFromJSON(JSONData.value(c_NHADATVN_UsingStatus).toObject());
     m_bedRooms = JSONData.value(c_NHADATVN_BedRooms).toInt(DEFAULT_INT_VALUE);
     m_completeTypes->importFromJSON(JSONData.value(c_NHADATVN_Complete).toObject());
     m_informationType->importFromJSON(JSONData.value(c_NHADATVN_InfomationType).toObject());
     m_HouseQuality->importFromJSON(JSONData.value(c_NHADATVN_Quality).toObject());

     QJsonObject jsObjLand = JSONData.value(c_NHADATVN_Land).toObject();
     m_landWide = jsObjLand.value(c_NHADATVN_Wide).toDouble(DEFAULT_INT_VALUE);
     m_landLong = jsObjLand.value(c_NHADATVN_Long).toDouble(DEFAULT_INT_VALUE);
     m_landAgriculturalLandSquare = jsObjLand.value(c_NHADATVN_AgriculturalLandSquare).toDouble(DEFAULT_INT_VALUE);
     m_landType = jsObjLand.value(c_NHADATVN_Type).toInt(DEFAULT_INT_VALUE);
     m_landId = jsObjLand.value(c_NHADATVN_Id).toInt(DEFAULT_INT_VALUE);
     m_landShape->importFromJSON(jsObjLand.value(c_NHADATVN_Shape).toObject());
     m_landPlanningType->importFromJSON(jsObjLand.value(c_NHADATVN_LandPlanningType).toObject());
     m_landJuridical->importFromJSON(jsObjLand.value(c_NHADATVN_Juridical).toObject());
     m_landJuridicalStatus->importFromJSON(jsObjLand.value(c_NHADATVN_JuridicalStatus).toObject());
     m_RoadSquare = jsObjLand.value(c_NHADATVN_RoadSquare).toDouble(DEFAULT_INT_VALUE);

//     QJsonObject jsObjHost = JSONData.value(c_NHADATVN_Host).toObject();
//     m_hostFullName = jsObjHost.value(c_NHADATVN_FullName).toString(DEFAULT_TEXT);
//     m_hostPhone = jsObjHost.value(c_NHADATVN_Phone).toString(DEFAULT_TEXT);
//     m_hostAge = jsObjHost.value(c_NHADATVN_Age).toInt(DEFAULT_INT_VALUE);
//     m_hostGender = jsObjHost.value(c_NHADATVN_Gender).toBool();
//     m_hostAddress = jsObjHost.value(c_NHADATVN_Address).toString(DEFAULT_TEXT);
//     m_hostCompany = jsObjHost.value(c_NHADATVN_Company).toString(DEFAULT_TEXT);
//     m_hostType = jsObjHost.value(c_NHADATVN_Type).toInt(DEFAULT_INT_VALUE);
//     m_hostId = jsObjHost.value(c_NHADATVN_Id).toInt(DEFAULT_INT_VALUE);
//     m_hostEmail = jsObjHost.value(c_NHADATVN_Email).toString(DEFAULT_TEXT);

     QJsonObject jsObjContact = JSONData.value(c_NHADATVN_Contact).toObject();
     m_contactFullName = jsObjContact.value(c_NHADATVN_FullName).toString(DEFAULT_TEXT);
     m_contactPhone = jsObjContact.value(c_NHADATVN_Phone).toString(DEFAULT_TEXT);
     m_contactAge = jsObjContact.value(c_NHADATVN_Age).toInt(DEFAULT_INT_VALUE);
     m_contactGender = jsObjContact.value(c_NHADATVN_Gender).toBool();
     m_contactAddress = jsObjContact.value(c_NHADATVN_Address).toString(DEFAULT_TEXT);
     m_contactCompany = jsObjContact.value(c_NHADATVN_Company).toString(DEFAULT_TEXT);
     m_contactType = jsObjContact.value(c_NHADATVN_Type).toInt(DEFAULT_INT_VALUE);
     m_contactId = jsObjContact.value(c_NHADATVN_Id).toInt(DEFAULT_INT_VALUE);
     m_contactEmail = jsObjContact.value(c_NHADATVN_Email).toString(DEFAULT_TEXT);
     m_SubmitStatus = (m_id == DEFAULT_INT_VALUE) ? false : true ;
     m_point = JSONData.value(c_NHADATVN_CollectionPoints).toInt(DEFAULT_INT_VALUE);
     m_CreatedDate = JSONData.value(c_NHADATVN_CreatedDate).toString(DEFAULT_TEXT);

     QJsonArray imageArr = JSONData.value(c_NHADATVN_DataSources).toArray();
     m_lstLegacyImageList.clear();
     m_lstLandPlanningImageList.clear();
     m_lstHouseImageList.clear();
     for (int i = 0; i < imageArr.count(); ++i) {
         QJsonObject tempImgObj = imageArr[i].toObject();
         ImageData* tempImgData = new ImageData();
         tempImgData->importFromJSONObject(tempImgObj);
         QString tempImgType = tempImgData->getImageType();
         if(tempImgType == c_NHADATVN_IMAGE_TYPE_JURIDICAL){
             m_lstLegacyImageList.append(tempImgData);
         }else if(tempImgType == c_NHADATVN_IMAGE_TYPE_LANDPLANNING){
             m_lstLandPlanningImageList.append(tempImgData);
         }else{
             m_lstHouseImageList.append(tempImgData);
         }
     }
}

int BDSData::calculateDataPoint()
{
    return m_point;
}

void BDSData::addImage(QString strImgType, QString strImgId, QString strImgPreview)
{
    ImageData* newImageData = new ImageData(strImgId, "", strImgPreview);
    if(strImgType == c_NHADATVN_IMAGE_TYPE_JURIDICAL){
        newImageData->setImageType(c_NHADATVN_IMAGE_TYPE_JURIDICAL);
        m_lstLegacyImageList.append(newImageData);
        emit legacyImageListChanged();
    }else if(strImgType == c_NHADATVN_IMAGE_TYPE_LANDPLANNING){
        newImageData->setImageType(c_NHADATVN_IMAGE_TYPE_LANDPLANNING);
        m_lstLandPlanningImageList.append(newImageData);
        emit landPlanningImageListChanged();
    }else{
        newImageData->setImageType(c_NHADATVN_IMAGE_TYPE_HOUSE);
        m_lstHouseImageList.append(newImageData);
        emit houseImageListChanged();
    }

}

void BDSData::deleteImage(QString strImgType, int nImgIndex)
{
    if(strImgType == c_NHADATVN_IMAGE_TYPE_JURIDICAL){
        m_lstLegacyImageList.removeAt(nImgIndex);
        emit legacyImageListChanged();
    }else if(strImgType == c_NHADATVN_IMAGE_TYPE_LANDPLANNING){
        m_lstLandPlanningImageList.removeAt(nImgIndex);
        emit landPlanningImageListChanged();
    }else{
        m_lstHouseImageList.removeAt(nImgIndex);
        emit houseImageListChanged();
    }
}

void BDSData::captureImage(QString strUID, QString strImgType, QString strImgId, QString strImgPath)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QList<QObject*> tempList;
    QString newName = strUID + "_";
    if(strImgType == c_NHADATVN_IMAGE_TYPE_JURIDICAL){
        tempList = m_lstLegacyImageList;
        newName.append(c_NHADATVN_IMAGE_TYPE_JURIDICAL);
    }else if(strImgType == c_NHADATVN_IMAGE_TYPE_LANDPLANNING){
        tempList = m_lstLandPlanningImageList;
        newName.append(c_NHADATVN_IMAGE_TYPE_LANDPLANNING);
    }else{
        tempList = m_lstHouseImageList;
        newName.append(c_NHADATVN_IMAGE_TYPE_HOUSE);
    }
    for (int i = 0; i < m_lstHouseImageList.count(); ++i) {
        ImageData* tempImgData = dynamic_cast<ImageData*>(tempList[i]);
        //        qDebug() << tempImgData->getImagePath();
    }

    newName.append("_");
    for (int i = 0; i < tempList.count(); ++i) {
        ImageData* tempImgData = dynamic_cast<ImageData*>(tempList[i]);
        if(tempImgData->getImageId() == strImgId){
            QFile* newFile = new QFile(strImgPath);
            QString oldFileName = QFileInfo(*newFile).fileName();
            QString newFileName = newName + QString::number(QDateTime::currentDateTime().toTime_t()) + oldFileName;
            QString newFilePath = QFileInfo(*newFile).filePath().replace(oldFileName, newFileName);
            newFile->rename(newFilePath);
            tempImgData->setImagePath(QFileInfo(*newFile).filePath());
            tempImgData->setImageUrl(IMAGE_HOST + newFileName);
            //            qDebug() << newFilePath;
            //            qDebug() << newFile->exists();
            //            qDebug() << tempImgData->getImagePath();
        }
    }

    for (int i = 0; i < m_lstHouseImageList.count(); ++i) {
        ImageData* tempImgData = dynamic_cast<ImageData*>(tempList[i]);
        //        qDebug() << tempImgData->getImagePath();
    }

    if(strImgType == c_NHADATVN_IMAGE_TYPE_JURIDICAL){
        emit legacyImageListChanged();
    }else if(strImgType == c_NHADATVN_IMAGE_TYPE_LANDPLANNING){
        emit landPlanningImageListChanged();
    }else{
        emit houseImageListChanged();
    }
}

void BDSData::updateContactInfo(QString strName,
                                QString strSoDienThoai,
                                QString strEmail,
                                QString strDiachi,
                                QString strGioiTinh,
                                QString strDoTuoi)
{
    m_contactFullName = strName;
    m_contactPhone = strSoDienThoai;
    m_contactEmail = strEmail;
    m_contactAddress = strDiachi;
    m_contactGender = strGioiTinh.toInt();
    m_contactAge = strDoTuoi.toInt();
}

void BDSData::updateHostInfo(QString strName,
                             QString strSoDienThoai,
                             QString strEmail,
                             QString strDiachi,
                             QString strGioiTinh,
                             QString strDoTuoi)
{
    m_hostFullName = strName;
    m_hostPhone = strSoDienThoai;
    m_hostEmail = strEmail;
    m_hostAddress = strDiachi;
    m_hostGender = strGioiTinh.toInt();
    m_hostAge = strDoTuoi.toInt();
}
