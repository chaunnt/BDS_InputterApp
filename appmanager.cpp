#include "appmanager.h"

static const bool SUBMITTED = true;

void AppManager::exportJson(QString strFileName, QJsonDocument jsDoc)
{
    QFile file(strFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << jsDoc.toJson();
    file.close();
}

AppManager::AppManager(QObject *parent) : QObject(parent)
{

}

AppManager::AppManager(){
    m_serverCommunicator = new ServerCommunicator(this);
    m_dbCommunicator = new DBCommunicator(this);
    m_RealEstateTypes.append(new SimpleData(1,"","Biệt Thự",-1));
    m_RealEstateTypes.append(new SimpleData(2,"","Nhà Riêng",-1));
    m_RealEstateTypes.append(new SimpleData(3,"","Nhà Mặt tiền",-1));
    m_RealEstateTypes.append(new SimpleData(4,"","Đất",-1));
    m_RealEstateTypes.append(new SimpleData(5,"","Đất Dự án",-1));
    m_RealEstateTypes.append(new SimpleData(6,"","Khác",-1));

    m_LandPositions.append(new SimpleData(1,"","Mặt tiền",-1));
    m_LandPositions.append(new SimpleData(1,"","Hẻm xe hơi",-1));
    m_LandPositions.append(new SimpleData(1,"","Hẻm nhỏ",-1));

    m_LandShapes.append(new SimpleData(1,"","Vuông vức",-1));
    m_LandShapes.append(new SimpleData(1,"","Nở hậu",-1));
    m_LandShapes.append(new SimpleData(1,"","Bóp hậu",-1));
    m_LandShapes.append(new SimpleData(1,"","Khác",-1));

    m_LandPlannings.append(new SimpleData(1,"","Đất ở",-1));
    m_LandPlannings.append(new SimpleData(1,"","Đất dịch vụ",-1));
    m_LandPlannings.append(new SimpleData(1,"","Đất cây xanh",-1));
    m_LandPlannings.append(new SimpleData(1,"","Đất hỗn hợp",-1));
    m_LandPlannings.append(new SimpleData(1,"","Đất nông nghiệp",-1));
    m_LandPlannings.append(new SimpleData(1,"","Khác",-1));

    m_LandDirections.append(new SimpleData(1,"","Đông",-1));
    m_LandDirections.append(new SimpleData(1,"","Đông Bắc",-1));
    m_LandDirections.append(new SimpleData(1,"","Đông Nam",-1));
    m_LandDirections.append(new SimpleData(1,"","Tây",-1));
    m_LandDirections.append(new SimpleData(1,"","Tây Bắc",-1));
    m_LandDirections.append(new SimpleData(1,"","Tây Nam",-1));
    m_LandDirections.append(new SimpleData(1,"","Nam",-1));
    m_LandDirections.append(new SimpleData(1,"","Bắc",-1));

    m_JuridicalsList.append(new SimpleData(1,"","Sổ đỏ",-1));
    m_JuridicalsList.append(new SimpleData(1,"","Sổ hồng riêng",-1));
    m_JuridicalsList.append(new SimpleData(1,"","Sổ hồng chung",-1));
    m_JuridicalsList.append(new SimpleData(1,"","Hợp đồng mua bán CĐT",-1));
    m_JuridicalsList.append(new SimpleData(1,"","Hợp đồng tay / vi bằng",-1));
    m_JuridicalsList.append(new SimpleData(1,"","Khác",-1));

    m_CompleteTypesList.append(new SimpleData(1,"","Cao cấp",-1));
    m_CompleteTypesList.append(new SimpleData(1,"","Trung bình",-1));
    m_CompleteTypesList.append(new SimpleData(1,"","Cơ bản",-1));

    m_HouseQualitiesList.append(new SimpleData(1,"","Mới xây",-1));
    m_HouseQualitiesList.append(new SimpleData(1,"","Mới sửa",-1));
    m_HouseQualitiesList.append(new SimpleData(1,"","Bình thường",-1));
    m_HouseQualitiesList.append(new SimpleData(1,"","Cũ nát",-1));
    m_HouseQualitiesList.append(new SimpleData(1,"","Không sử dụng được",-1));

    m_LandUsingStatuses.append(new SimpleData(1,"","Đang ở",-1));
    m_LandUsingStatuses.append(new SimpleData(1,"","Đang cho thuê",-1));
    m_LandUsingStatuses.append(new SimpleData(1,"","Buôn bán",-1));
    m_LandUsingStatuses.append(new SimpleData(1,"","Đầu tư",-1));

    m_PriceTypes.append(new SimpleData(1,"","Tỷ đồng",-1));
    m_PriceTypes.append(new SimpleData(1,"","Triệu đồng",-1));
    m_PriceTypes.append(new SimpleData(1,"","Triệu / m2",-1));

    m_AgeList.append(new SimpleData(1,"","25",-1));
    m_AgeList.append(new SimpleData(1,"","30",-1));
    m_AgeList.append(new SimpleData(1,"","35",-1));
    m_AgeList.append(new SimpleData(1,"","40",-1));
    m_AgeList.append(new SimpleData(1,"","45",-1));
    m_AgeList.append(new SimpleData(1,"","50",-1));
    m_AgeList.append(new SimpleData(1,"","55",-1));
    m_AgeList.append(new SimpleData(1,"","60",-1));

    m_SexList.append(new SimpleData(1,"","Nam",-1));
    m_SexList.append(new SimpleData(1,"","Nữ",-1));
    m_SexList.append(new SimpleData(1,"","Không xác định",-1));

    m_currentBDS = new BDSData;

#ifdef Q_OS_ANDROID
    qDebug() << "Create AndroidClient";
    m_androidClient = QAndroidJniObject("com/batdongsan/nhadatvn/AndroidClient");
    m_androidClient.setStaticField<jint>("com/batdongsan/nhadatvn/AndroidClient",
                                          "qtObject", reinterpret_cast<long>(this));
    qDebug() << "Qt setActivity";
    QAndroidJniObject::callStaticMethod<jint>("com/batdongsan/nhadatvn/AndroidClient",
                                              "setActivity",
                                              "(Landroid/app/Activity;)V",
                                              QtAndroid::androidActivity().object<jobject>());
#endif
}

//bool AppManager::changePassword(QString strOldPwd, QString strNewPwd, QString strConfirmPwd)
//{
//    return true;
//}

//bool AppManager::forgotPassword(QString strEmail)
//{
//    return true;
//}

bool AppManager::loginUser(QString strUserName, QString strPwd)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << strUserName;
    qDebug() << strPwd;
#endif
    QUrl url = QUrl(CLOUD_HOST + "/Users/UserLogin");
    QNetworkRequest request;
    QJsonObject jsObj;
    jsObj["UserName"] = strUserName;
    jsObj["Password"] = strPwd;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager tempNamLogin;
    QNetworkReply* response = tempNamLogin.post(request, QJsonDocument(jsObj).toJson());
    QEventLoop tempLoop;
    connect(&tempNamLogin, SIGNAL(finished(QNetworkReply*)), &tempLoop, SLOT(quit()));
    tempLoop.exec();
    QString tempNetworkResponse;
    if(response->error() == QNetworkReply::NoError)
    {
        QByteArray arrayResponse = response->readAll();
        qDebug() << "arrayResponse: " << arrayResponse;
        tempNetworkResponse = QString::fromUtf8(arrayResponse);
        QJsonDocument jsDoc = QJsonDocument::fromJson(arrayResponse);
        bool result = 0;
        result = jsDoc.object().value("IsSuccessed").toBool();
        if(result == true){
            m_UserName = strUserName;
            m_Email = jsDoc.object().value("Data").toObject().value("Email").toString();
            m_serverCommunicator->TokenKey = jsDoc.object().value("Data").toObject().value("TokenKey").toString();
            m_Roles = jsDoc.object().value("Data").toObject().value("Roles").toString();
            m_LastLogin = jsDoc.object().value("Data").toObject().value("LastLogin").toString();
            m_FullName = jsDoc.object().value("Data").toObject().value("FullName").toString();
            m_UserId = jsDoc.object().value("Data").toObject().value("Roles").toArray().at(0).toObject().value("ID").toInt();
            qDebug() << "m_userid: " << m_UserId;
            userChanged();
            saveLoginInfo(strUserName, strPwd);
        }else{
            qDebug() << jsDoc.object().value("Message").toString();
        }
        return result;
    }
    else
    {
        tempNetworkResponse = response->errorString() + " | " + response->readAll();
        qDebug() << "tempNetworkResponse: " << tempNetworkResponse;
        emit serverError("Login failed");
    }

    return false;
}

//bool AppManager::registerUser(QString strNumber, QString strPwd)
//{
//    return true;
//}

bool AppManager::autoLogin()
{
    QString tempEmail = "";
    QString tempPwd = "";
    getLoginInfo(tempEmail, tempPwd);

    if(tempEmail != "" && tempPwd != ""){
        return loginUser(tempEmail, tempPwd);
    }
    return false;
}

bool AppManager::startupApplication()
{
    initProvinceList();
    initDistrictList();
    initWardList();
    initStreetList();

    //    loadAllBDSDataFromLocal();
    getAllBDSDataFromServer(20, 0, true);


    //    loadProvinceListFromServer();
    //    loadDistrictListFromServer(1);
    //    loadWardListFromServer(1);
    //    loadStreetListFromServer();
    getLookupData();

    //    initCurrentBDS();

    return true;
}

bool AppManager::logout()
{
    qDebug() << Q_FUNC_INFO;
    QFile file(LOGIN_INFO);
    qDebug() << "file: " << file.exists();
    if(file.exists()){
        file.remove();
    }
    qDebug() << "file: " << file.exists();
    return true;
}

bool AppManager::submitData()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(validateBDS(m_currentBDS) == false){
        return false;
    }
    calculateBDSRankingValue();
    QJsonObject submitData = m_currentBDS->convertToJsonObj();
#ifdef DEBUG_MODE
    exportJson("Submit1.json",QJsonDocument(submitData));
#endif
    submitData = removeUnusedValues(submitData);
#ifdef DEBUG_MODE
    exportJson("Submit2.json",QJsonDocument(submitData));
#endif
    QByteArray responseData = m_serverCommunicator->submitBDSData(submitData);
    if(responseData.length() == 0){
        return false;
    }

    QString tempNetworkResponse;
    QByteArray tempResponseData = responseData;
    tempNetworkResponse = QString::fromUtf8(tempResponseData);
    QJsonDocument jsDoc = QJsonDocument::fromJson(tempResponseData);
    qDebug() << tempResponseData;
#ifdef DEBUG_MODE
    exportJson("Submit3.json",QJsonDocument::fromJson(tempResponseData));
#endif

    bool result = 0;
    result = jsDoc.object().value("IsSuccessed").toBool();
    if(result == true){
        QList<QObject*> tempImageList = m_currentBDS->ImageList();
        for (int i = 0; i < tempImageList.count(); ++i) {
            ImageData* tempImg = dynamic_cast<ImageData*>(tempImageList[i]);
#ifdef DEBUG_MODE
            qDebug() << tempImg->getImagePath();
#endif
            if(tempImg->getImagePath() != ""){
                m_serverCommunicator->uploadImage(tempImg->getImagePath());
            }
        }
        BDSData* newBDS= new BDSData();
        m_currentBDS->ownerID = QString::number(m_UserId);
        m_currentBDS->importFromJsonObj(jsDoc.object().value("Data").toObject());
        m_currentBDS->setSubmitStatus(SUBMITTED);
        m_currentBDS->setCreatedDate(jsDoc.object().value("Data").toObject().value("CreatedDate").toString());
#ifdef DEBUG_MODE
        exportJson("Submit4.json",QJsonDocument(m_currentBDS->convertToJsonObj()));
#endif
        newBDS->importFromJsonObj(m_currentBDS->convertToJsonObj());
#ifdef DEBUG_MODE
        exportJson("Submit5.json",QJsonDocument(newBDS->convertToJsonObj()));
#endif
        m_submittedBDSList.append(newBDS);
        emit submittedBDSListChanged();
    }else{
        emit serverError(jsDoc.object().value("Message").toString());
        BDSData* newBDS= new BDSData();
        newBDS->importFromJsonObj(m_currentBDS->convertToJsonObj());
        addBDSDataToLocal(QJsonDocument(newBDS->convertToJsonObj()).toJson());
        m_submittedBDSList.append(newBDS);
        emit submittedBDSListChanged();
        return false;
    }
    return true;
}

void AppManager::addPreviewImage(QString strImageType, QString strImgId, QString strImgPreview)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strImageType << "  " << strImgId << "  " << strImgPreview;
    m_currentBDS->addImage(strImageType, strImgId, strImgPreview);
}

QObject* AppManager::getCurrentBDSData()
{
    return m_currentBDS;
}

QVariant AppManager::getNotificationList()
{
    return QVariant::fromValue(m_notificationList);
}

QVariant AppManager::getSubmittedBDSList()
{
    return QVariant::fromValue(m_submittedBDSList);
}

QVariant AppManager::getDistrictList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_districtList);
}

QVariant AppManager::getDistrictListWithProvinceID(int strProvinceID)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> temp;
    for (int i = 0; i < m_districtList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_districtList[i]);
        if(tempData->dataParentId() == strProvinceID){
            temp.append(tempData);
        }
    }
    return QVariant::fromValue(temp);
}

QVariant AppManager::getProvinceList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_provinceList);
}

QVariant AppManager::getWardList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_wardList);
}

QVariant AppManager::getWardListWithDistrictID(int strDistrictID)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> temp;
    for (int i = 0; i < m_wardList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_wardList[i]);
        if(tempData->dataParentId() == strDistrictID){
            temp.append(tempData);
        }
    }
    return QVariant::fromValue(temp);
}

int AppManager::countSubmittedBDS()
{
    qDebug() << Q_FUNC_INFO;
    int count = 0;
    for (int i = 0; i < m_submittedBDSList.count(); ++i) {
        BDSData* tempData = reinterpret_cast<BDSData*>(m_submittedBDSList[i]);
        if(tempData->getSubmitStatus() == true){
            count++;
        }
    }
    qDebug() << count;
    return count;
}

int AppManager::countUnsubmittedBDS()
{
    int count = 0;
    for (int i = 0; i < m_submittedBDSList.count(); ++i) {
        BDSData* tempData = reinterpret_cast<BDSData*>(m_submittedBDSList[i]);
        if(tempData->getSubmitStatus() == false){
            count++;
        }
    }
    return count;
}

QString AppManager::userFullName()
{
    return m_FullName;
}

bool AppManager::validateBDS(BDSData *newBDSData)
{
    if(newBDSData->getProvince() == DEFAULT_TEXT){
        emit serverError("Thiếu thông tin về tỉnh/thành");
        return false;
    }

    if(newBDSData->getDistrict() == DEFAULT_TEXT){
        emit serverError("Thiếu thông tin về quận/huyện");
        return false;
    }

    if(newBDSData->getType() == DEFAULT_TEXT){
        emit serverError("Thiếu thông tin về loại BĐS");
        return false;
    }

    if(newBDSData->getPrice() == DEFAULT_INT_VALUE){
        emit serverError("Thiếu thông tin về giá");
        return false;
    }

    if(newBDSData->getStreet() == DEFAULT_TEXT){
        emit serverError("Thiếu thông tin về tên đường");
        return false;
    }

    if(newBDSData->getHomenumber() == DEFAULT_TEXT){
        emit serverError("Thiếu thông tin về địa chỉ nhà");
        return false;
    }

    if(newBDSData->getHostphone() == DEFAULT_TEXT || newBDSData->getContactphone() == DEFAULT_TEXT){
        emit serverError("Thiếu thông tin về SĐT liên hệ");
        return false;
    }

    return true;
}

void AppManager::calculateCurrentPriceList()
{
    qDebug() << Q_FUNC_INFO;
    double housePrice = 0;
    double landPrice = 0;
    double landUnitPrice = 0;
    double houseUnitPrice = 0;

    for (int i = 0; i < m_CompleteTypesList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_CompleteTypesList[i]);
        if(tempData->dataDisplayName() == "Cao cấp"){
            houseUnitPrice = calculateHouseUnitPrice(m_currentBDS->getFloorSquare(), 7);

        }else if(tempData->dataDisplayName() == "Trung bình"){
            houseUnitPrice = calculateHouseUnitPrice(m_currentBDS->getFloorSquare(), 5);

        }else if(tempData->dataDisplayName() == "Cơ bản"){
            houseUnitPrice = calculateHouseUnitPrice(m_currentBDS->getFloorSquare(), 4);

        }else{
            houseUnitPrice = calculateHouseUnitPrice(m_currentBDS->getFloorSquare(), 4);
        }
    }

    m_currentBDS->setPriceUnit(houseUnitPrice);

    housePrice = calculateHousePrice(m_currentBDS->getFloorSquare(), houseUnitPrice);
    landPrice = calculateLandPrice(housePrice, m_currentBDS->getPrice() * 1000);
    landUnitPrice = calculateLandUnitPrice(m_currentBDS->getFloorSquare(), landPrice);
    m_currentBDS->setPriceUnit(landUnitPrice);
}

double AppManager::calculateHousePrice(double floorSquare, double unitPrice)
{
    return floorSquare * unitPrice;
}

double AppManager::calculateHouseUnitPrice(double floorSquare, int completeTypeValue)
{
    return floorSquare * completeTypeValue;
}

double AppManager::calculateLandUnitPrice(double landSquare, double landPrice)
{
    if(landSquare > 1.0){
        return landPrice / landSquare;
    }
    return 0;
}

double AppManager::calculateLandPrice(double housePrice, double salePrice)
{
    return salePrice - housePrice;
}

bool AppManager::checkValidJsonValue(QJsonValue newVal)
{
    if (newVal.isBool()) {
        return true;
    }else if (newVal.isString()) {
        if(newVal.toString() == DEFAULT_TEXT){
            return false;
        }
    }else if (newVal.isArray()) {

    }else if (newVal.isDouble()) {
        if(newVal.toDouble() == DEFAULT_INT_VALUE){
            return false;
        }
    }else if (newVal.isNull()) {
        return false;
    }else if (newVal.isUndefined()){
        return false;
    }else {
        if(newVal.toInt() == DEFAULT_INT_VALUE){
            return false;
        }
    }
    return true;
}

QJsonObject AppManager::removeUnusedValues(QJsonObject jsonInputObject)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QJsonObject tempObj = jsonInputObject;
    for (int i = 0; i < jsonInputObject.keys().count(); ++i)
    {
        QString tempKey = jsonInputObject.keys()[i];
        QJsonValue tempVal = jsonInputObject.value(tempKey);
         if (tempVal.isObject())
         {
             for (int j = 0; j < tempVal.toObject().keys().count(); j++)
             {
                 QString tempChildKey = tempVal.toObject().keys()[j];
                 QJsonValue tempChildVal = tempVal.toObject().value(tempChildKey);
                 tempObj[tempKey] = removeUnusedValues(tempVal.toObject());
             }
         }else
         {
             if(checkValidJsonValue(tempVal) == false){
                 tempObj.remove(tempKey);
             }
         }

    }
    return tempObj;
}

bool AppManager::verifyBDSTypeB(QJsonObject JSONData)
{
    qDebug() << Q_FUNC_INFO;
    bool bResult = true;
    qDebug() << Q_FUNC_INFO;
    bResult = checkValidJsonValue(JSONData.value("HomeNumber"));
    bResult = checkValidJsonValue(JSONData.value("Street"));
    bResult = checkValidJsonValue(JSONData.value("Type").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Ward").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("District").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Province").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Position").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Direction").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("DefaultSquare"));
    bResult = checkValidJsonValue(JSONData.value("PriceUnit"));
    bResult = checkValidJsonValue(JSONData.value("Price"));
    bResult = checkValidJsonValue(JSONData.value("FloorSquare"));
    bResult = checkValidJsonValue(JSONData.value("Floors"));
    bResult = checkValidJsonValue(JSONData.value("UsingStatus").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("BedRooms"));
    bResult = checkValidJsonValue(JSONData.value("Toilets"));
    bResult = checkValidJsonValue(JSONData.value("LivingRoom"));
    bResult = checkValidJsonValue(JSONData.value("Kitchen"));

    QJsonObject tempObjLand = JSONData["Land"].toObject();
    bResult = checkValidJsonValue(tempObjLand.value("Type"));
    bResult = checkValidJsonValue(tempObjLand.value("Shape").toObject().value("Id"));
    bResult = checkValidJsonValue(tempObjLand.value("Wide"));
    bResult = checkValidJsonValue(tempObjLand.value("Long"));
    bResult = checkValidJsonValue(tempObjLand.value("LandPlanningType").toObject().value("Id"));
    bResult = checkValidJsonValue(tempObjLand.value("Shape").toObject().value("Id"));

    QJsonObject tempObjHost;
    bResult = checkValidJsonValue(tempObjHost.value("FullName"));
    bResult = checkValidJsonValue(tempObjHost.value("Phone"));

    QJsonObject tempObjContact;
    bResult = checkValidJsonValue(tempObjContact.value("FullName"));
    bResult = checkValidJsonValue(tempObjContact.value("Phone"));

    bResult = JSONData.value("DataSources").toArray().count() > 0;
    return bResult;
}

void AppManager::calculateBDSRankingValue()
{
    QJsonObject JSONData = m_currentBDS->convertToJsonObj();
    if(verifyBDSTypeB(JSONData) == true){
        m_currentBDS->setInformationType("B");
        m_currentBDS->setInformationTypeId(1);
        if(verifyBDSTypeA(JSONData) == true){
            m_currentBDS->setInformationType("A");
            m_currentBDS->setInformationTypeId(2);
        }
    }else{
        m_currentBDS->setInformationType("C");
        m_currentBDS->setInformationTypeId(0);
    }
}

bool AppManager::verifyBDSTypeA(QJsonObject JSONData)
{
    qDebug() << Q_FUNC_INFO;
    bool bResult = true;
    bResult = checkValidJsonValue(JSONData.value("HomeNumber"));
    bResult = checkValidJsonValue(JSONData.value("Street"));
    bResult = checkValidJsonValue(JSONData.value("Type").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Ward").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("District").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Province").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("StreetWidth"));
    bResult = checkValidJsonValue(JSONData.value("Position").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Direction").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("DefaultSquare"));
    bResult = checkValidJsonValue(JSONData.value("RealitySquare"));

    bResult = checkValidJsonValue(JSONData.value("PriceUnit"));
    bResult = checkValidJsonValue(JSONData.value("Price"));
    bResult = checkValidJsonValue(JSONData.value("DiscussedPrice"));
    bResult = checkValidJsonValue(JSONData.value("ConstructionSquare"));
    bResult = checkValidJsonValue(JSONData.value("FloorSquare"));
    bResult = checkValidJsonValue(JSONData.value("Floors"));
    bResult = checkValidJsonValue(JSONData.value("Height"));
    bResult = checkValidJsonValue(JSONData.value("UsingStatus").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("Complete").toObject().value("Id"));
    bResult = checkValidJsonValue(JSONData.value("BedRooms"));
    bResult = checkValidJsonValue(JSONData.value("Toilets"));
    bResult = checkValidJsonValue(JSONData.value("LivingRoom"));
    bResult = checkValidJsonValue(JSONData.value("Kitchen"));
    bResult = checkValidJsonValue(JSONData.value("Quality").toObject().value("Id"));

    QJsonObject tempObjLand = JSONData["Land"].toObject();
    bResult = checkValidJsonValue(tempObjLand.value("Type"));
    bResult = checkValidJsonValue(tempObjLand.value("Shape").toObject().value("Id"));
    bResult = checkValidJsonValue(tempObjLand.value("Wide"));
    bResult = checkValidJsonValue(tempObjLand.value("Long"));
    bResult = checkValidJsonValue(tempObjLand.value("AgriculturalLandSquare"));
    bResult = checkValidJsonValue(tempObjLand.value("LandPlanningType").toObject().value("Id"));
    bResult = checkValidJsonValue(tempObjLand.value("RoadSquare"));
    bResult = checkValidJsonValue(tempObjLand.value("Shape").toObject().value("Id"));
    bResult = checkValidJsonValue(tempObjLand.value("Juridical").toObject().value("Id"));

    QJsonObject tempObjHost;
    bResult = checkValidJsonValue(tempObjHost.value("FullName"));
    bResult = checkValidJsonValue(tempObjHost.value("Age"));
    bResult = checkValidJsonValue(tempObjHost.value("Phone"));
    bResult = checkValidJsonValue(tempObjHost.value("Address"));

    QJsonObject tempObjContact;
    bResult = checkValidJsonValue(tempObjContact.value("FullName"));
    bResult = checkValidJsonValue(tempObjContact.value("Phone"));
    bResult = checkValidJsonValue(tempObjContact.value("Age"));
    bResult = checkValidJsonValue(tempObjContact.value("Address"));



    bResult = JSONData.value("DataSources").toArray().count() > 0;
    return bResult;
}

void AppManager::updateLocationList()
{
    qDebug() << Q_FUNC_INFO;
    m_districtList.clear();
    m_provinceList.clear();
    m_wardList.clear();

    QStringList provinceList;
    qDebug() << "m_provinceList";
    for (int i = 0; i < m_Locations.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_Locations[i]);
        if(tempData->dataParentId() == 0){
            m_provinceList.append(tempData);
            provinceList.append(QString::number(tempData->dataId()));
            qDebug() << tempData->dataDisplayName();
        }
    }

    qDebug() << "districtList";
    QStringList districtList;
    for (int i = 0; i < m_Locations.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_Locations[i]);
        if(provinceList.contains(QString::number(tempData->dataParentId()))){
            districtList.append(QString::number(tempData->dataId()));
            m_districtList.append(tempData);
            qDebug() << tempData->dataDisplayName();
        }
    }

    qDebug() << "m_wardList";
    for (int i = 0; i < m_Locations.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_Locations[i]);
        if(districtList.contains(QString::number(tempData->dataParentId()))){
            m_wardList.append(tempData);
            qDebug() << tempData->dataDisplayName();
        }
    }
    emit districtListChanged();
    emit wardListChanged();
    emit provinceListChanged();
}

int AppManager::getpoint_TinhThanh()
{
    return POINT_TINHTHANH;
}

int AppManager::getpoint_QuanHuyen()
{
    return POINT_QUANHUYEN;
}

int AppManager::getpoint_PhuongXa()
{
    return POINT_PHUONGXA;
}

int AppManager::getpoint_LoaiBDS()
{
    return POINT_LOAIBDS;
}
int AppManager::getpoint_DiaChiNha()
{
    return POINT_DIACHINHA;
}
int AppManager::getpoint_TenDuong()
{
    return POINT_TENDUONG;
}
int AppManager::getpoint_ViTri()
{
    return POINT_VITRI;
}
int AppManager::getpoint_ChieuRongDuong()
{
    return POINT_CHIEURONGDUONG;
}
int AppManager::getpoint_DuAn()
{
    return POINT_DUAN;
}
int AppManager::getpoint_ChieuNgang()
{
    return POINT_CHIEUNGANG;
}
int AppManager::getpoint_ChieuDai()
{
    return POINT_CHIEUDAI;
}
int AppManager::getpoint_DienTichCongNhan()
{
    return POINT_DIENTICHCONGNHAN;
}
int AppManager::getpoint_DienTichThucTe()
{
    return POINT_DIENTICHTHUCTE;
}
int AppManager::getpoint_DienTichLoGioi()
{
    return POINT_DIENTICHLOGIOI;
}
int AppManager::getpoint_HinhDang()
{
    return POINT_HINHDANG;
}
int AppManager::getpoint_QuyHoachLoaiDat()
{
    return POINT_QUYHOACHLOAIDAT;
}
int AppManager::getpoint_DienTichDatNongNghiep()
{
    return POINT_DIENTICHDATNONGNGHIEP;
}
int AppManager::getpoint_Huong()
{
    return POINT_DIRECTION;
}
int AppManager::getpoint_ConstructionSquare()
{
    return POINT_CONSTRUCTIONSQUARE;
}
int AppManager::getpoint_FloorSquare()
{
    return POINT_FLOORSQUARE;
}
int AppManager::getpoint_Floors()
{
    return POINT_FLOORS;
}
int AppManager::getpoint_ConstructionHeight()
{
    return POINT_CONSTRUCTIONHEIGHT;
}
int AppManager::getpoint_VatLieuHoanThien()
{
    return POINT_VATLIEUHOANTHIEN;
}
int AppManager::getpoint_TienIchNha()
{
    return POINT_TIENICHNHA;
}
int AppManager::getpoint_UsingStatus()
{
    return POINT_USINGSTATUS;
}
int AppManager::getpoint_TinhTrangChatLuong()
{
    return POINT_TINHTRANGCHATLUONG;
}
int AppManager::getpoint_GiaBan()
{
    return POINT_GIABAN;
}
int AppManager::getpoint_DonViGia()
{
    return POINT_DONVIGIA;
}
int AppManager::getpoint_DiscussedPrice()
{
    return POINT_DISCUSSEDPRICE;
}
int AppManager::getpoint_LoaiGiayTo()
{
    return POINT_LOAIGIAYTO;
}
int AppManager::getpoint_TinhTrangPhapLy()
{
    return POINT_TINHTRANGPHAPLY;
}

int AppManager::getpoint_CompleteTypes()
{
    return POINT_COMPLETETYPES;
}

int AppManager::getpoint_OwnerName()
{
    return POINT_OWNERNAME;
}
int AppManager::getpoint_OwnerAge()
{
    return POINT_OWNERAGE;
}
int AppManager::getpoint_OwnerGender()
{
    return POINT_OWNERGENDER;
}
int AppManager::getpoint_OwnerPhone()
{
    return POINT_OWNERPHONE;
}
int AppManager::getpoint_OwnerAddress()
{
    return POINT_OWNERADDRESS;
}

int AppManager::getpoint_ImageMatTien()
{
    return POINT_IMAGEMATTIEN;
}
int AppManager::getpoint_ImageLeft()
{
    return POINT_IMAGELEFT;
}
int AppManager::getpoint_ImageRight()
{
    return POINT_IMAGERIGHT;
}
int AppManager::getpoint_ImageOpposite()
{
    return POINT_IMAGEOPPOSITE;
}
int AppManager::getpoint_ImagePhongKhach()
{
    return POINT_IMAGEPHONGKHACH;
}
int AppManager::getpoint_ImagePhongBep()
{
    return POINT_IMAGEPHONGBEP;
}
int AppManager::getpoint_ImagePhongNgu()
{
    return POINT_IMAGEPHONGNGU;
}
int AppManager::getpoint_ImagePhongTam()
{
    return POINT_IMAGEPHONGTAM;
}
int AppManager::getpoint_ImageSanThuong()
{
    return POINT_IMAGESANTHUONG;
}
int AppManager::getpoint_ImageNhaXe()
{
    return POINT_IMAGENHAXE;
}
int AppManager::getpoint_TienIchTrongNha()
{
    return POINT_TIENICHTRONGNHA;
}
int AppManager::getpoint_VideoNha()
{
    return POINT_VIDEONHA;
}
int AppManager::getpoint_Image360Degree()
{
    return POINT_IMAGE360DEGREE;
}
int AppManager::getpoint_Position()
{
    return POINT_POSITION;
}
int AppManager::getpoint_ImageGiayToNha()
{
    return POINT_IMAGEGIAYTONHA;
}
int AppManager::getpoint_ImageQuyHoachLoGioi()
{
    return POINT_IMAGEQUYHOACHLOGIOI;
}
int AppManager::getpoint_ImageQuyHoachSuDungDat()
{
    return POINT_IMAGEQUYHOACHSUDUNGDAT;
}
int AppManager::getpoint_ContactType()
{
    return POINT_CONTACTTYPE;
}
int AppManager::getpoint_ContactName()
{
    return POINT_CONTACTNAME;
}
int AppManager::getpoint_ContactAge()
{
    return POINT_CONTACTAGE;
}
int AppManager::getpoint_ContactGender()
{
    return POINT_CONTACTGENDER;
}
int AppManager::getpoint_ContactPhone()
{
    return POINT_CONTACTPHONE;
}
int AppManager::getpoint_ContactAddress()
{
    return POINT_CONTACTADDRESS;
}
int AppManager::getpoint_ContactCompany()
{
    return POINT_CONTACTCOMPANY;
}

QString AppManager::getImageType_nha()
{
    return IMAGE_TYPE_NHA;
}

QString AppManager::getImageType_mattien()
{
    return IMAGE_TYPE_MATTIEN;
}

QString AppManager::getImageType_viewtraiphai()
{
    return IMAGE_TYPE_VIEWTRAIPHAI;
}

QString AppManager::getImageType_phongkhach()
{
    return IMAGE_TYPE_PHONGKHACH;
}

QString AppManager::getImageType_phongbep()
{
    return IMAGE_TYPE_PHONGBEP;
}

QString AppManager::getImageType_phongngu()
{
    return IMAGE_TYPE_PHONGNGU;
}

QString AppManager::getImageType_phongtam()
{
    return IMAGE_TYPE_PHONGTAM;
}

QString AppManager::getImageType_santhuong()
{
    return IMAGE_TYPE_SANTHUONG;
}

QString AppManager::getImageType_nhaxe()
{
    return IMAGE_TYPE_NHAXE;
}

QString AppManager::getImageType_giaytonha()
{
    return IMAGE_TYPE_GIAYTONHA;
}

QString AppManager::getImageType_quyhoachlogioi()
{
    return IMAGE_TYPE_QUYHOACHLOGIOI;
}

QString AppManager::getImageType_quyhoachsudungdat()
{
    return IMAGE_TYPE_QUYHOACHSUDUNGDAT;
}

QString AppManager::get_const_DEFAULT_TEXT()
{
    return DEFAULT_TEXT;
}

int AppManager::get_const_DEFAULT_SELECTED_ID()
{
    return DEFAULT_SELECTED_ID;
}

int AppManager::get_const_DEFAULT_INT_VALUE()
{
    return DEFAULT_INT_VALUE;
}

QVariant AppManager::realEstateTypesList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_RealEstateTypes);
}
QVariant AppManager::landPositionList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_LandPositions);
}
QVariant AppManager::landShapesList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_LandShapes);
}
QVariant AppManager::landDirectionsList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_LandDirections);
}
QVariant AppManager::houseQualitiesList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_HouseQualitiesList);
}
QVariant AppManager::landUsingStatuses()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_LandUsingStatuses);
}

QVariant AppManager::landPlanningList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_LandPlannings);
}
QVariant AppManager::furnituresInfoList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_FurnituresInfo);
}
QVariant AppManager::sourcesInfoList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_SourcesInfo);
}
QVariant AppManager::juridicalsList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_JuridicalsList);
}

QVariant AppManager::completeTypesList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_CompleteTypesList);
}
QVariant AppManager::stairsInfoList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_StairsInfo);
}
QVariant AppManager::imageTypesList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_ImageTypes);
}

QVariant AppManager::priceTypeList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_PriceTypes);
}

QVariant AppManager::ageList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_AgeList);
}

QVariant AppManager::sexList()
{
    qDebug() << Q_FUNC_INFO;
    return QVariant::fromValue(m_SexList);
}
void AppManager::saveLoginInfo(QString strEmail, QString strPassword)
{
    QFile file(LOGIN_INFO);

    if(!file.open(QIODevice::WriteOnly)){
        qDebug() << "saveLoginInfo fail";
        return;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("LoginInfo");
    xmlWriter.writeTextElement("Email", strEmail);
    xmlWriter.writeTextElement("Password", strPassword);
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();
}

void AppManager::getLoginInfo(QString &strEmail, QString &strPassword)
{
    QFile file(LOGIN_INFO);

#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if( !file.open( QFile::ReadOnly | QFile::Text ) ) {
        qDebug() << file.fileName();
        return;
    }
    QXmlStreamReader xmlStream(&file);
    while(!xmlStream.atEnd())
    {
        xmlStream.readNext();
        if(xmlStream.isStartElement() && xmlStream.name() == "LoginInfo") {

            while(!xmlStream.atEnd())
            {
                xmlStream.readNext();
                QString keyValue = xmlStream.name().toString();
                if(xmlStream.isStartElement() == true){
                    if(keyValue == "Email"){
                        strEmail = xmlStream.readElementText();
                    }
                    else if(keyValue == "Password"){
                        strPassword = xmlStream.readElementText();
                    }
                }
            }
        }
    }

    file.close();
}

bool AppManager::addBDSDataToLocal(QString strData)
{
    qDebug() << Q_FUNC_INFO;
    return m_dbCommunicator->addBDSData(strData);
}

bool AppManager::updateBDSDataToLocal(QString strData, QString nIndex)
{
    qDebug() << Q_FUNC_INFO;
    return m_dbCommunicator->updateBDSData(strData, nIndex);
}

void AppManager::loadAllBDSDataFromLocal()
{
    qDebug() << Q_FUNC_INFO;
    m_submittedBDSList = m_dbCommunicator->loadAllBDSData();
}

void AppManager::loadProvinceListFromLocal()
{

}

void AppManager::loadDistrictListFromLocal()
{

}

void AppManager::loadWardListFromLocal()
{

}

void AppManager::loadStreetListFromLocal()
{

}

void AppManager::getAllBDSDataFromServer(int nItemsPerPage, int nPageNumber, bool bWaiting)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << m_UserId;
    if(bWaiting){
        QByteArray arrayResponse = m_serverCommunicator->getAllBDSDataFromServer(nItemsPerPage, nPageNumber, bWaiting);
        qDebug() << arrayResponse;
        QJsonDocument jsDoc = QJsonDocument::fromJson(arrayResponse);
        if(arrayResponse.length() <= 0){
            return;
        }

        QJsonArray jsArr = jsDoc.object().value("Data").toObject().value("BrowseItems").toArray();
        if(jsArr.count() > 0){
            m_submittedBDSList.clear();
            for (int i = 0; i < jsArr.count(); ++i) {
                QJsonObject tempObj = jsArr[i].toObject();
                BDSData* newBds = new BDSData();
                newBds->importFromJsonObj(tempObj);
                newBds->setSubmitStatus(SUBMITTED);
                m_submittedBDSList.append(newBds);
            }
            emit submittedBDSListChanged();
            emit districtListChanged();
        }
    }else{
        m_serverCommunicator->getAllBDSDataFromServer(nItemsPerPage, nPageNumber, bWaiting);
        QObject::connect(m_serverCommunicator, &ServerCommunicator::getAllBDSDataFromServerResponsed, [=] (QNetworkReply *newResponse) {
            QObject::disconnect(m_serverCommunicator, &ServerCommunicator::getAllAssignedDistrictResponsed, nullptr, nullptr);
            qDebug() << "getAllBDSDataFromServer";

            QString tempNetworkResponse;
            if(newResponse->error() == QNetworkReply::NoError)
            {
                QByteArray arrayResponse = newResponse->readAll();
                qDebug() << arrayResponse;
                QJsonDocument jsDoc = QJsonDocument::fromJson(arrayResponse);
                QJsonArray jsArr = jsDoc.object().value("Data").toObject().value("BrowseItems").toArray();
                if(jsArr.count() > 0){
                    m_submittedBDSList.clear();
                    for (int i = 0; i < jsArr.count(); ++i) {
                        QJsonObject tempObj = jsArr[i].toObject();
                        BDSData* newBds = new BDSData();
                        newBds->importFromJsonObj(tempObj);
                        newBds->setSubmitStatus(SUBMITTED);
                        m_submittedBDSList.append(newBds);
                    }
                    emit submittedBDSListChanged();
                    emit districtListChanged();
                }
            }
            else
            {
                tempNetworkResponse = newResponse->errorString() + " | " + newResponse->readAll();
                qDebug() << tempNetworkResponse;
            }
        });
    }
}

QJsonObject AppManager::loadBDSDataFromServerWithID(int strID)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << m_UserId;
    QByteArray arrayResponse = m_serverCommunicator->getBDSDataFromServerWithID(strID);
    qDebug() << arrayResponse;
    QJsonDocument jsDoc = QJsonDocument::fromJson(arrayResponse);
    QJsonObject jsObj = jsDoc.object().value("Data").toObject();
    return jsObj;
}

void AppManager::captureImage(QString strImageType, QString strImgId, QString strImgSrc)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strImageType << "  " << strImgId << "  " << strImgSrc;
    m_currentBDS->captureImage(QString::number(m_UserId), strImageType, strImgId, strImgSrc);
}

QString AppManager::captureScreenShot(QString strFileName)
{
    qDebug() << Q_FUNC_INFO;
    QString fileName = "";
#ifdef Q_OS_ANDROID
    QAndroidJniObject tempfileName = QAndroidJniObject::fromString(strFileName);
    QAndroidJniObject captureResult = m_androidClient.callObjectMethod("captureScreenShot",
                                                                       "(Ljava/lang/String;)Ljava/lang/String;",
                                                                       tempfileName.object<jstring> ());
    if(captureResult.isValid()){
        fileName = captureResult.toString();
    }
#endif
    qDebug() << "fileName: " << fileName;
    return fileName;
}

void AppManager::removeImage(QString strImageType, int nImgIndex)
{
    m_currentBDS->deleteImage(strImageType, nImgIndex);
}

void AppManager::selectProvince(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_provinceList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_provinceList[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setProvinceId(tempData->dataId());
            m_currentBDS->setProvince(strValue);
            m_districtList.clear();
            qDebug() << "ID: " << m_currentBDS->getProvinceId();
            qDebug() << "name: " << m_currentBDS->getProvince();
            for (int j = 0; j < m_Locations.count(); ++j) {
                SimpleData* tempLocation = reinterpret_cast<SimpleData*>(m_Locations[j]);
                if(tempLocation->dataParentId() == tempData->dataId()){
                    m_districtList.append(tempLocation);
                }
            }
            break;
        }
    }
    emit districtListChanged();
}

void AppManager::selectDistrict(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_districtList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_districtList[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setDistrictId(tempData->dataId());
            m_currentBDS->setDistrict(strValue);
            m_currentBDS->District->setDataParentId(tempData->dataParentId());
            m_wardList.clear();
            for (int j = 0; j < m_Locations.count(); ++j) {
                SimpleData* tempLocation = reinterpret_cast<SimpleData*>(m_Locations[j]);
                if(tempLocation->dataParentId() == tempData->dataId()){
                    m_wardList.append(tempLocation);
                }
            }
            break;
        }
    }
    emit wardListChanged();
}

void AppManager::selectWard(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_wardList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_wardList[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setWardId(tempData->dataId());
            m_currentBDS->setWard(strValue);
            m_currentBDS->Ward->setDataParentId(tempData->dataParentId());
            break;
        }
    }
    emit wardListChanged();
}

void AppManager::selectType(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_RealEstateTypes.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_RealEstateTypes[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setTypeId(tempData->dataId());
            m_currentBDS->setType(strValue);
            return;
        }
    }
}

void AppManager::selectLandShape(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_LandShapes.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_LandShapes[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setLandshape(tempData->dataDisplayName());
            m_currentBDS->setLandshapeId(tempData->dataId());
            return;
        }
    }
}

void AppManager::selectLandPosition(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_LandPositions.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_LandPositions[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setLandPosition(tempData->dataDisplayName());
            m_currentBDS->setLandPositionId(tempData->dataId());
            return;
        }
    }
}

void AppManager::selectLandPlanning(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_LandPlannings.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_LandPlannings[i]);
        qDebug() << "setLandjuridical: " << tempData->dataDisplayName();
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setLandPlanningType(tempData->dataDisplayName());
            m_currentBDS->setLandPlanningTypeId(tempData->dataId());
            qDebug() << "setLandjuridical: " << tempData->dataDisplayName();
            qDebug() << "setLandjuridicalId: " << tempData->dataId();
            return;
        }
    }
}

void AppManager::selectLandJuridical(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_JuridicalsList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_JuridicalsList[i]);
        qDebug() << "setLandjuridical: " << tempData->dataDisplayName();
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setLandjuridical(tempData->dataDisplayName());
            m_currentBDS->setLandjuridicalId(tempData->dataId());
            qDebug() << "setLandjuridical: " << tempData->dataDisplayName();
            qDebug() << "setLandjuridicalId: " << tempData->dataId();
            return;
        }
    }
}

void AppManager::selectCompleteTypes(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_CompleteTypesList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_CompleteTypesList[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setCompleteTypes(tempData->dataDisplayName());
            m_currentBDS->setCompleteTypesId(tempData->dataId());
            qDebug() << "setCompleteTypes: " << tempData->dataDisplayName();
            qDebug() << "setCompleteTypesId: " << tempData->dataId();
            return;
        }
    }
}

void AppManager::selectLandDirection(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_LandDirections.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_LandDirections[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setLandDirection(tempData->dataDisplayName());
            m_currentBDS->setLandDirectionId(tempData->dataId());
            return;
        }
    }
}

void AppManager::selectSubmittedBDS(int nBDSIndex)
{
    m_currentBDS = reinterpret_cast<BDSData*>(m_submittedBDSList[nBDSIndex]);
    if(m_currentBDS->getSubmitStatus() == true){
        QByteArray response = m_serverCommunicator->getBDSDataFromServerWithID(m_currentBDS->getId());
#ifdef DEBUG_MODE
        exportJson("selectSubmittedBDS1.json",QJsonDocument::fromJson(response));
#endif
        if(response.length() > 0){
            QJsonObject resObj = QJsonDocument::fromJson(response).object().value("Data").toObject();
#ifdef DEBUG_MODE
            exportJson("selectSubmittedBDS2.json",QJsonDocument(resObj));
#endif
            m_currentBDS->importFromJsonObj(resObj);
            m_currentBDS->setSubmitStatus(SUBMITTED);
#ifdef DEBUG_MODE
            exportJson("selectSubmittedBDS3.json",QJsonDocument(m_currentBDS->convertToJsonObj()));
#endif
        }
    }
    emit currentBDSDataChanged();
}

void AppManager::selectBDSLocation(QString dLongitude, QString dLatitude)
{
    m_currentBDS->setLandLongitude(dLongitude);
    m_currentBDS->setLandLatitude(dLatitude);
}

void AppManager::selectConvenientStuff(QString stuffs, bool value)
{
    if (stuffs == "Sân thượng"){
        m_currentBDS->setTerraceValid(value);
    }
    else if (stuffs == "Sân Vườn"){
        m_currentBDS->setYardValid(value);
    }
    else if (stuffs == "Nhà xe"){
        m_currentBDS->setGarageValid(value);
    }
}

void AppManager::selectHouseQuality(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_HouseQualitiesList.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_HouseQualitiesList[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setHouseQuality(tempData->dataDisplayName());
            m_currentBDS->setHouseQualityId(tempData->dataId());
            return;
        }
    }
}

void AppManager::selectUsingStatus(QString strValue)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << strValue;
    for (int i = 0; i < m_LandUsingStatuses.count(); ++i) {
        SimpleData* tempData = reinterpret_cast<SimpleData*>(m_LandUsingStatuses[i]);
        if(tempData->dataDisplayName() == strValue){
            m_currentBDS->setUsingStatus(tempData->dataDisplayName());
            m_currentBDS->setUsingStatusId(tempData->dataId());
            return;
        }
    }
}

bool AppManager::checkMapUrl(QString strUrl)
{
    if(strUrl.contains("https://www.google.com/maps")){
        return true;
    }
    return false;
}

QString AppManager::getImageStorageLocation()
{
    QString strLocaltion = "";
    strLocaltion = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/";
    return strLocaltion;
}

void AppManager::startInputSequence()
{
    initCurrentBDS();
}

bool AppManager::updateBDSData()
{
    if(validateBDS(m_currentBDS) == false){
        return false;
    }
    calculateBDSRankingValue();
    QJsonObject submitData = m_currentBDS->convertToJsonObj();
#ifdef DEBUG_MODE
    exportJson("Submit1.json",QJsonDocument(submitData));
#endif
    submitData = removeUnusedValues(submitData);
#ifdef DEBUG_MODE
    exportJson("Submit2.json",QJsonDocument(submitData));
#endif
    QByteArray responseData = m_serverCommunicator->updateBDSData(submitData);
    if(responseData.length() == 0){
        return false;
    }

    QString tempNetworkResponse;
    QByteArray tempResponseData = responseData;
    tempNetworkResponse = QString::fromUtf8(tempResponseData);
    QJsonDocument jsDoc = QJsonDocument::fromJson(tempResponseData);
    qDebug() << tempResponseData;
    bool result = 0;
    result = jsDoc.object().value("IsSuccessed").toBool();
    if(result == true){
        m_currentBDS->setSubmitStatus(true);
        m_currentBDS->setCreatedDate(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm"));
        updateBDSDataToLocal(QJsonDocument(m_currentBDS->convertToJsonObj()).toJson(), "0");
        emit submittedBDSListChanged();
    }else{
        emit serverError(jsDoc.object().value("Message").toString());
        return false;
    }
    return true;
}

void AppManager::updateContactInfo(QString ctName, QString ctSoDienThoai, QString ctEmail, QString ctDiachi, QString ctGioiTinh, QString ctDoTuoi)
{
    m_currentBDS->updateContactInfo(ctName, ctSoDienThoai, ctEmail, ctDiachi, ctGioiTinh, ctDoTuoi);
}

void AppManager::updateHostInfo(QString strName, QString strSoDienThoai, QString strEmail, QString strDiachi, QString strGioiTinh, QString strDoTuoi)
{
    m_currentBDS->updateHostInfo(strName, strSoDienThoai, strEmail, strDiachi, strGioiTinh, strDoTuoi);
}

void AppManager::initProvinceList()
{
    SimpleData* newProvince = new SimpleData();
    newProvince->setDataId(DEFAULT_INT_VALUE);
    newProvince->setDataName(DEFAULT_TINHTHANH);
    newProvince->setDataParentId(DEFAULT_INT_VALUE);
    newProvince->setDataDisplayName(DEFAULT_TINHTHANH);
    m_provinceList.append(newProvince);
}

void AppManager::initDistrictList()
{
    SimpleData* newDistrict = new SimpleData();
    newDistrict->setDataId(DEFAULT_INT_VALUE);
    newDistrict->setDataName(DEFAULT_QUANHUYEN);
    newDistrict->setDataParentId(DEFAULT_INT_VALUE);
    newDistrict->setDataDisplayName(DEFAULT_QUANHUYEN);
    m_districtList.append(newDistrict);
}

void AppManager::initWardList()
{
    SimpleData* newWard = new SimpleData();
    newWard->setDataId(DEFAULT_INT_VALUE);
    newWard->setDataName(DEFAULT_PHUONGXA);
    newWard->setDataParentId(DEFAULT_INT_VALUE);
    newWard->setDataDisplayName(DEFAULT_PHUONGXA);
    m_wardList.append(newWard);
}

void AppManager::initStreetList()
{

}

void AppManager::initCurrentBDS()
{
    m_currentBDS = new BDSData();
    //    selectProvince((reinterpret_cast<SimpleData*>(m_provinceList[0]))->dataDisplayName());
    //    selectDistrict((reinterpret_cast<SimpleData*>(m_districtList[0]))->dataDisplayName());
    //    selectWard((reinterpret_cast<SimpleData*>(m_wardList[0]))->dataDisplayName());
    //    m_currentBDS->setProvinceId((reinterpret_cast<SimpleData*>(m_provinceList[0]))->dataId());
    //    m_currentBDS->setProvince((reinterpret_cast<SimpleData*>(m_provinceList[0]))->dataDisplayName());
    //    m_currentBDS->setDistrictId((reinterpret_cast<SimpleData*>(m_districtList[0]))->dataId());
    //    m_currentBDS->setDistrict((reinterpret_cast<SimpleData*>(m_districtList[0]))->dataDisplayName());
    //    m_currentBDS->setWardId((reinterpret_cast<SimpleData*>(m_wardList[0]))->dataId());
    //    m_currentBDS->setWard((reinterpret_cast<SimpleData*>(m_wardList[0]))->dataDisplayName());
}

void AppManager::loadDistrictListFromServer(int nProvinceIndex)
{
    qDebug() << Q_FUNC_INFO;
    m_serverCommunicator->getAllAssignedDistrict(nProvinceIndex);
    QObject::connect(m_serverCommunicator, &ServerCommunicator::getAllAssignedDistrictResponsed, [=] (QNetworkReply *newResponse) {
        QObject::disconnect(m_serverCommunicator, &ServerCommunicator::getAllAssignedDistrictResponsed, nullptr, nullptr);
        qDebug() << "getAllAssignedDistrictResponsed";

        QString tempNetworkResponse;
        if(newResponse->error() == QNetworkReply::NoError)
        {
            QByteArray arrayResponse = newResponse->readAll();
            QJsonDocument jsDoc = QJsonDocument::fromJson(arrayResponse);
            QJsonArray jsArr = jsDoc.object().value("Data").toArray();
            if(jsArr.count() > 0){
                m_districtList.clear();
                for (int i = 0; i < jsArr.count(); ++i) {
                    QJsonObject tempObj = jsArr[i].toObject();
                    SimpleData* newDistrict = new SimpleData();
                    newDistrict->setDataId(tempObj.value("Id").toInt());
                    newDistrict->setDataName(tempObj.value("Name").toString());
                    newDistrict->setDataParentId(tempObj.value("ParentId").toInt());
                    newDistrict->setDataDisplayName(tempObj.value("DisplayName").toString());
                    m_districtList.append(newDistrict);
                }
                emit districtListChanged();
            }
        }
        else
        {
            tempNetworkResponse = newResponse->errorString() + " | " + newResponse->readAll();
            qDebug() << tempNetworkResponse;
        }
    });
}

void AppManager::getAllBDSData()
{
    getAllBDSDataFromServer(20, 0, true);
    loadAllBDSDataFromLocal();
}

void AppManager::getLookupData()
{
    qDebug() << Q_FUNC_INFO;
    m_serverCommunicator->getLookupDatas();
    QObject::connect(m_serverCommunicator, &ServerCommunicator::getLookupDatasResponsed, [=] (QNetworkReply *newResponse) {
        QObject::disconnect(m_serverCommunicator, &ServerCommunicator::getLookupDatasResponsed, nullptr, nullptr);
        qDebug() << "getLookupData";

        QString tempNetworkResponse;
        if(newResponse->error() == QNetworkReply::NoError)
        {
            QByteArray arrayResponse = newResponse->readAll();
            QJsonDocument jsDoc = QJsonDocument::fromJson(arrayResponse);
            qDebug() << arrayResponse;
            QJsonObject jsObj = jsDoc.object().value("Data").toObject();
            bool result = 0;
            result = jsDoc.object().value("IsSuccessed").toBool();
            if(result == true){
                importLocations(QJsonDocument(jsObj.value("Locations").toArray()).toJson());
                importRealEstateTypes(QJsonDocument(jsObj.value("Types").toArray()).toJson());
                importLandPositions(QJsonDocument(jsObj.value("Positions").toArray()).toJson());
                importLandShapes(QJsonDocument(jsObj.value("Shapes").toArray()).toJson());
                importLandDirections(QJsonDocument(jsObj.value("Directions").toArray()).toJson());
                importLandStatuses(QJsonDocument(jsObj.value("Statuses").toArray()).toJson());
                importLandUsingStatuses(QJsonDocument(jsObj.value("UsingStatuses").toArray()).toJson());
                importLandPlannings(QJsonDocument(jsObj.value("LandPlannings").toArray()).toJson());
                importFurnituresInfo(QJsonDocument(jsObj.value("Furnitures").toArray()).toJson());
                importSourcesInfo(QJsonDocument(jsObj.value("Sources").toArray()).toJson());
                importJuridicals(QJsonDocument(jsObj.value("Juridicals").toArray()).toJson());
                importCompleteTypesList(QJsonDocument(jsObj.value("CompleteTypes").toArray()).toJson());
                importStairsInfo(QJsonDocument(jsObj.value("Stairs").toArray()).toJson());
                importImageTypes(QJsonDocument(jsObj.value("ImageTypes").toArray()).toJson());
            }
        }
        else
        {
            tempNetworkResponse = newResponse->errorString() + " | " + newResponse->readAll();
            qDebug() << tempNetworkResponse;
        }
    });

}

void AppManager::importLocations(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_Locations.clear();
        m_Locations = tempList;
        updateLocationList();
    }
}

void AppManager::importRealEstateTypes(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_RealEstateTypes.clear();
        m_RealEstateTypes = tempList;
        emit realEstateTypesListChanged();
    }
}

void AppManager::importLandPositions(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_LandPositions.clear();
        m_LandPositions = tempList;
        emit landPositionListChanged();
    }
}

void AppManager::importLandShapes(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_LandShapes.clear();
        m_LandShapes = tempList;
        emit landShapesListChanged();
    }
}

void AppManager::importLandDirections(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_LandDirections.clear();
        m_LandDirections = tempList;
        emit landDirectionsListChanged();
    }
}

void AppManager::importLandStatuses(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_HouseQualitiesList.clear();
        m_HouseQualitiesList = tempList;
        emit houseQualitiesListChanged();
    }
}

void AppManager::importLandUsingStatuses(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_LandUsingStatuses.clear();
        m_LandUsingStatuses = tempList;
        emit landUsingStatusesChanged();
    }
}

void AppManager::importLandPlannings(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_LandPlannings.clear();
        m_LandPlannings = tempList;
        emit landPlanningListChanged();
    }
}

void AppManager::importFurnituresInfo(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_FurnituresInfo.clear();
        m_FurnituresInfo = tempList;
        emit furnituresInfoListChanged();
    }
}

void AppManager::importSourcesInfo(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_SourcesInfo.clear();
        m_SourcesInfo = tempList;
        emit sourcesInfoListChanged();
    }
}

void AppManager::importJuridicals(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_JuridicalsList.clear();
        m_JuridicalsList = tempList;
        emit juridicalsListChanged();
    }
}

void AppManager::importCompleteTypesList(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_CompleteTypesList.clear();
        m_CompleteTypesList = tempList;
        emit completeTypesListChanged();
    }
}

void AppManager::importStairsInfo(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_StairsInfo.clear();
        m_StairsInfo = tempList;
        emit stairsInfoListChanged();
    }
}

void AppManager::importImageTypes(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> tempList = importLookupData(data);
    if(tempList.count() > 0){
        m_ImageTypes.clear();
        m_ImageTypes = tempList;
        emit imageTypesListChanged();
    }
}

QList<QObject *> AppManager::importLookupData(QString data)
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject*> newList;
    QJsonDocument jsDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonArray jsArr = jsDoc.array();
    if(jsArr.count() > 0){
        for (int i = 0; i < jsArr.count(); ++i) {
            QJsonObject tempObj = jsArr[i].toObject();
            SimpleData* newData = new SimpleData();
            newData->setDataId(tempObj.value("Id").toInt());
            newData->setDataName(tempObj.value("Name").toString());
            newData->setDataParentId(tempObj.value("ParentId").toInt());
            newData->setDataDisplayName(tempObj.value("DisplayName").toString());
            newList.append(newData);
        }
    }
    return newList;
}

void AppManager::loadProvinceListFromServer()
{
    qDebug() << Q_FUNC_INFO;
    m_serverCommunicator->getAllAssignedProvince();
    QObject::connect(m_serverCommunicator, &ServerCommunicator::getAllAssignedProvinceResponsed, [=] (QNetworkReply *newResponse) {
        QObject::disconnect(m_serverCommunicator, &ServerCommunicator::getAllAssignedProvinceResponsed, nullptr, nullptr);
        qDebug() << "getAllAssignedProvinceResponsed";
        QString tempNetworkResponse;
        if(newResponse->error() == QNetworkReply::NoError)
        {
            QByteArray arrayResponse = newResponse->readAll();
            qDebug() << "arrayResponse: " << arrayResponse;
            QJsonDocument jsDoc = QJsonDocument::fromJson(arrayResponse);
            QJsonArray jsArr = jsDoc.object().value("Data").toArray();
            if(jsArr.count() > 0){
                m_provinceList.clear();
                for (int i = 0; i < jsArr.count(); ++i) {
                    QJsonObject tempObj = jsArr[i].toObject();
                    SimpleData* newProvince = new SimpleData();
                    newProvince->setDataId(tempObj.value("Id").toInt());
                    newProvince->setDataName(tempObj.value("Name").toString());
                    newProvince->setDataParentId(tempObj.value("ParentId").toInt());
                    newProvince->setDataDisplayName(tempObj.value("DisplayName").toString());
                    qDebug() << "Id: " << newProvince->dataId();
                    qDebug() << "Name: " << newProvince->dataDisplayName();
                    m_provinceList.append(newProvince);
                    //                    loadDistrictListFromServer(newProvince->dataId());
                }
                emit provinceListChanged();
                qDebug() << "provinceListChanged: " << m_provinceList.count();
            }
        }
        else
        {
            tempNetworkResponse = newResponse->errorString() + " | " + newResponse->readAll();
            qDebug() << tempNetworkResponse;
            emit serverError(newResponse->errorString());
        }
        qDebug() << "tempNetworkResponse: " << tempNetworkResponse;
    });
}
