#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QVariant>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QStandardPaths>
#include <QEventLoop>
#include <QTextStream>
#include <QThread>
#include <QDateTime>
#include <QProcess>
#include <QObject>
#include <QScreen>
#include <QPixmap>
#include <QFileInfo>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#ifdef Q_OS_ANDROID
#include <QAndroidJniObject>
#include <QtAndroidExtras/QAndroidJniEnvironment>
#include <QtAndroidExtras>
#include <QtAndroid>
#include <jni.h>
#endif

#include "RealEstateModel/bdsdata.h"
#include "RealEstateModel/provincedata.h"
#include "RealEstateModel/districtdata.h"
#include "RealEstateModel/retype.h"
#include "RealEstateModel/warddata.h"
#include "RealEstateModel/imagedata.h"

#include "globaldefine.h"
#include "ServerCommunication/servercommunicator.h"
#include "DBCommunication/dbcommunicator.h"

class AppManager : public QObject
{
    Q_OBJECT
    QNetworkAccessManager m_namSubmitData;
    Q_PROPERTY(QObject* currentBDSData READ getCurrentBDSData NOTIFY currentBDSDataChanged)
    Q_PROPERTY(QVariant notificationList READ getNotificationList NOTIFY notificationListChanged)
    Q_PROPERTY(QVariant submittedBDSList READ getSubmittedBDSList NOTIFY submittedBDSListChanged)
    Q_PROPERTY(QVariant provinceList READ getProvinceList NOTIFY provinceListChanged)
    Q_PROPERTY(QVariant districtList READ getDistrictList NOTIFY districtListChanged)
    Q_PROPERTY(QVariant wardList READ getWardList NOTIFY wardListChanged)
    Q_PROPERTY(QVariant realEstateTypesList READ realEstateTypesList NOTIFY realEstateTypesListChanged)
    Q_PROPERTY(QVariant landPositionList READ landPositionList  NOTIFY landPositionListChanged)
    Q_PROPERTY(QVariant landShapesList READ landShapesList NOTIFY landShapesListChanged)
    Q_PROPERTY(QVariant landDirectionsList READ landDirectionsList NOTIFY landDirectionsListChanged)
    Q_PROPERTY(QVariant houseQualitiesList READ houseQualitiesList NOTIFY houseQualitiesListChanged)
    Q_PROPERTY(QVariant landUsingStatuses READ landUsingStatuses NOTIFY landUsingStatusesChanged)
    Q_PROPERTY(QVariant landPlanningList READ landPlanningList NOTIFY landPlanningListChanged)
    Q_PROPERTY(QVariant furnituresInfoList READ furnituresInfoList NOTIFY furnituresInfoListChanged)
    Q_PROPERTY(QVariant sourcesInfoList READ sourcesInfoList NOTIFY sourcesInfoListChanged)
    Q_PROPERTY(QVariant juridicalsList READ juridicalsList   NOTIFY juridicalsListChanged)
    Q_PROPERTY(QVariant completeTypesList READ completeTypesList NOTIFY completeTypesListChanged)
    Q_PROPERTY(QVariant stairsInfoList READ stairsInfoList NOTIFY stairsInfoListChanged)
    Q_PROPERTY(QVariant imageTypesList READ imageTypesList NOTIFY imageTypesListChanged)
    Q_PROPERTY(QVariant priceTypeList READ priceTypeList NOTIFY priceTypeListChanged)
    Q_PROPERTY(QVariant ageList READ ageList NOTIFY ageListChanged)
    Q_PROPERTY(QVariant sexList READ sexList NOTIFY sexListChanged)

    Q_PROPERTY(int countSubmittedBDS READ countSubmittedBDS NOTIFY submittedBDSListChanged)
    Q_PROPERTY(int countUnsubmittedBDS READ countUnsubmittedBDS NOTIFY submittedBDSListChanged)
    Q_PROPERTY(QString userFullName READ userFullName NOTIFY userChanged)

    BDSData* m_currentBDS;
    QList<QObject*> m_notificationList;
    QList<QObject*> m_submittedBDSList;
    QList<QObject*> m_provinceList;
    QList<QObject*> m_districtList;
    QList<QObject*> m_wardList;
    QList<QObject*> m_typeList;
    QList<QObject*> m_Locations;
    QList<QObject*> m_RealEstateTypes;
    QList<QObject*> m_LandPositions;
    QList<QObject*> m_LandShapes;
    QList<QObject*> m_LandDirections;
    QList<QObject*> m_HouseQualitiesList;
    QList<QObject*> m_LandUsingStatuses;
    QList<QObject*> m_LandPlannings;
    QList<QObject*> m_FurnituresInfo;
    QList<QObject*> m_SourcesInfo;
    QList<QObject*> m_JuridicalsList;
    QList<QObject*> m_CompleteTypesList;
    QList<QObject*> m_StairsInfo;
    QList<QObject*> m_ImageTypes;
    QList<QObject*> m_PriceTypes;
    QList<QObject*> m_AgeList;
    QList<QObject*> m_SexList;

    QString m_UserName = "";
    QString m_FullName = "";
    QString m_Email = "";
    QString m_Roles = "";
    QString m_LastLogin = "";
    int m_UserId = -1;

    ServerCommunicator* m_serverCommunicator;
    DBCommunicator *m_dbCommunicator;

    void exportJson(QString strFileName, QJsonDocument jsDoc);
#ifdef Q_OS_ANDROID
    QAndroidJniObject m_androidClient;
#endif
public:
    explicit AppManager(QObject *parent);
    AppManager();
    QScreen * screenPointer;
//    Q_INVOKABLE bool changePassword(QString strOldPwd, QString strNewPwd, QString strConfirmPwd);
//    Q_INVOKABLE bool forgotPassword(QString strEmail);
    Q_INVOKABLE bool loginUser(QString strEmail, QString strPwd);
//    Q_INVOKABLE bool registerUser(QString strNumber, QString strPwd);
    Q_INVOKABLE bool autoLogin();
    Q_INVOKABLE bool startupApplication();
    Q_INVOKABLE bool logout();
    Q_INVOKABLE bool submitData();
    Q_INVOKABLE void addPreviewImage(QString strImageType, QString strImgId, QString strImgPreview);
    Q_INVOKABLE void captureImage(QString strImageType, QString strImgId, QString strImgSrc);
    Q_INVOKABLE QString captureScreenShot(QString strFileName);
    Q_INVOKABLE void removeImage(QString strImageType, int nImgIndex);
    Q_INVOKABLE void selectProvince(QString strValue);
    Q_INVOKABLE void selectDistrict(QString strValue);
    Q_INVOKABLE void selectWard(QString strValue);
    Q_INVOKABLE void selectType(QString strValue);
    Q_INVOKABLE void selectLandShape(QString strValue);
    Q_INVOKABLE void selectLandPosition(QString strValue);
    Q_INVOKABLE void selectLandPlanning(QString strValue);
    Q_INVOKABLE void selectLandJuridical(QString strValue);
    Q_INVOKABLE void selectCompleteTypes(QString strValue);
    Q_INVOKABLE void selectLandDirection(QString strValue);
    Q_INVOKABLE void selectSubmittedBDS(int nBDSIndex);
    Q_INVOKABLE void selectBDSLocation(QString dLongitude, QString dLatitude);
    Q_INVOKABLE void selectConvenientStuff(QString stuffs, bool value);
    Q_INVOKABLE void selectHouseQuality(QString strValue);
    Q_INVOKABLE void selectUsingStatus(QString strValue);
//    Q_INVOKABLE void selectConvenientStuff(QString stuffs, bool value);
    Q_INVOKABLE bool checkMapUrl(QString strUrl);
    Q_INVOKABLE QString getImageStorageLocation();
    Q_INVOKABLE void startInputSequence();
    Q_INVOKABLE bool updateBDSData();
    Q_INVOKABLE void updateContactInfo(QString ctName, QString ctSoDienThoai,
                                       QString ctEmail, QString ctDiachi,
                                       QString ctGioiTinh, QString ctDoTuoi);
    Q_INVOKABLE void updateHostInfo(QString strName, QString strSoDienThoai,
                        QString strEmail, QString strDiachi,
                        QString strGioiTinh, QString strDoTuoi);

    Q_INVOKABLE int getpoint_TinhThanh();
    Q_INVOKABLE int getpoint_QuanHuyen();
    Q_INVOKABLE int getpoint_PhuongXa();
    Q_INVOKABLE int getpoint_LoaiBDS();
    Q_INVOKABLE int getpoint_DiaChiNha();
    Q_INVOKABLE int getpoint_TenDuong();
    Q_INVOKABLE int getpoint_ViTri();
    Q_INVOKABLE int getpoint_ChieuRongDuong();
    Q_INVOKABLE int getpoint_DuAn();
    Q_INVOKABLE int getpoint_ChieuNgang();
    Q_INVOKABLE int getpoint_ChieuDai();
    Q_INVOKABLE int getpoint_DienTichCongNhan();
    Q_INVOKABLE int getpoint_DienTichThucTe();
    Q_INVOKABLE int getpoint_DienTichLoGioi();
    Q_INVOKABLE int getpoint_HinhDang();
    Q_INVOKABLE int getpoint_QuyHoachLoaiDat();
    Q_INVOKABLE int getpoint_DienTichDatNongNghiep();
    Q_INVOKABLE int getpoint_Huong();
    Q_INVOKABLE int getpoint_ConstructionSquare();
    Q_INVOKABLE int getpoint_FloorSquare();
    Q_INVOKABLE int getpoint_Floors();
    Q_INVOKABLE int getpoint_ConstructionHeight();
    Q_INVOKABLE int getpoint_VatLieuHoanThien();
    Q_INVOKABLE int getpoint_TienIchNha();
    Q_INVOKABLE int getpoint_UsingStatus();
    Q_INVOKABLE int getpoint_TinhTrangChatLuong();
    Q_INVOKABLE int getpoint_GiaBan();
    Q_INVOKABLE int getpoint_DonViGia();
    Q_INVOKABLE int getpoint_DiscussedPrice();
    Q_INVOKABLE int getpoint_LoaiGiayTo();
    Q_INVOKABLE int getpoint_TinhTrangPhapLy();
    Q_INVOKABLE int getpoint_CompleteTypes();
    Q_INVOKABLE int getpoint_OwnerName();
    Q_INVOKABLE int getpoint_OwnerAge();
    Q_INVOKABLE int getpoint_OwnerGender();
    Q_INVOKABLE int getpoint_OwnerPhone();
    Q_INVOKABLE int getpoint_OwnerAddress();

    Q_INVOKABLE int getpoint_ImageMatTien();
    Q_INVOKABLE int getpoint_ImageLeft();
    Q_INVOKABLE int getpoint_ImageRight();
    Q_INVOKABLE int getpoint_ImageOpposite();
    Q_INVOKABLE int getpoint_ImagePhongKhach();
    Q_INVOKABLE int getpoint_ImagePhongBep();
    Q_INVOKABLE int getpoint_ImagePhongNgu();
    Q_INVOKABLE int getpoint_ImagePhongTam();
    Q_INVOKABLE int getpoint_ImageSanThuong();
    Q_INVOKABLE int getpoint_ImageNhaXe();
    Q_INVOKABLE int getpoint_TienIchTrongNha();
    Q_INVOKABLE int getpoint_VideoNha();
    Q_INVOKABLE int getpoint_Image360Degree();
    Q_INVOKABLE int getpoint_Position();
    Q_INVOKABLE int getpoint_ImageGiayToNha();
    Q_INVOKABLE int getpoint_ImageQuyHoachLoGioi();
    Q_INVOKABLE int getpoint_ImageQuyHoachSuDungDat();
    Q_INVOKABLE int getpoint_ContactType();
    Q_INVOKABLE int getpoint_ContactName();
    Q_INVOKABLE int getpoint_ContactAge();
    Q_INVOKABLE int getpoint_ContactGender();
    Q_INVOKABLE int getpoint_ContactPhone();
    Q_INVOKABLE int getpoint_ContactAddress();
    Q_INVOKABLE int getpoint_ContactCompany();

    Q_INVOKABLE QString getImageType_nha();
    Q_INVOKABLE QString getImageType_mattien();
    Q_INVOKABLE QString getImageType_viewtraiphai();
    Q_INVOKABLE QString getImageType_phongkhach();
    Q_INVOKABLE QString getImageType_phongbep();
    Q_INVOKABLE QString getImageType_phongngu();
    Q_INVOKABLE QString getImageType_phongtam();
    Q_INVOKABLE QString getImageType_santhuong();
    Q_INVOKABLE QString getImageType_nhaxe();
    Q_INVOKABLE QString getImageType_giaytonha();
    Q_INVOKABLE QString getImageType_quyhoachlogioi();
    Q_INVOKABLE QString getImageType_quyhoachsudungdat();

    Q_INVOKABLE QString get_const_DEFAULT_TEXT();
    Q_INVOKABLE int get_const_DEFAULT_SELECTED_ID();
    Q_INVOKABLE int get_const_DEFAULT_INT_VALUE();

    Q_INVOKABLE void calculateCurrentPriceList();

    QVariant landPositionList();
    QVariant landShapesList();
    QVariant landDirectionsList();
    QVariant houseQualitiesList();
    QVariant landUsingStatuses();
    QVariant landPlanningList();
    QVariant furnituresInfoList();
    QVariant sourcesInfoList();
    QVariant juridicalsList();
    QVariant completeTypesList();
    QVariant stairsInfoList();
    QVariant imageTypesList();
    QVariant priceTypeList();
    QVariant ageList();
    QVariant sexList();
    QVariant realEstateTypesList();

    void initProvinceList();
    void initDistrictList();
    void initWardList();
    void initStreetList();
    void initCurrentBDS();

    void saveLoginInfo(QString strEmail, QString strPassword);
    void getLoginInfo(QString &strEmail, QString &strPassword);
    bool addBDSDataToLocal(QString strData);
    bool updateBDSDataToLocal(QString strData, QString nIndex);//TODO

    void loadAllBDSDataFromLocal();
    void loadProvinceListFromLocal(); //TODO
    void loadDistrictListFromLocal();//TODO
    void loadWardListFromLocal();//TODO
    void loadStreetListFromLocal();//TODO

    void getAllBDSDataFromServer(int nItemsPerPage = 20, int nPageNumber = 0, bool bWaiting = false);
    QJsonObject loadBDSDataFromServerWithID(int strID);
    void loadProvinceListFromServer();
    void loadDistrictListFromServer(int nProvinceIndex);//TODO

    void getAllBDSData();
    void getLookupData();
    void importProvinceList(QString data);
    void importLocations(QString data);
    void importRealEstateTypes(QString data);
    void importLandPositions(QString data);
    void importLandShapes(QString data);
    void importLandDirections(QString data);
    void importLandStatuses(QString data);
    void importLandUsingStatuses(QString data);
    void importLandPlannings(QString data);
    void importFurnituresInfo(QString data);
    void importSourcesInfo(QString data);
    void importJuridicals(QString data);
    void importCompleteTypesList(QString data);
    void importStairsInfo(QString data);
    void importImageTypes(QString data);
    QList<QObject*> importLookupData(QString data);


    QObject* getCurrentBDSData();
    QVariant getNotificationList();
    QVariant getSubmittedBDSList();
    QVariant getDistrictList();
    QVariant getDistrictListWithProvinceID(int strProvinceID);
    QVariant getProvinceList();
    QVariant getWardList();
    QVariant getWardListWithDistrictID(int strDistrictID);
    int countSubmittedBDS();
    int countUnsubmittedBDS();
    QString userFullName();

    bool validateBDS(BDSData* newBDSData);
    double calculateHousePrice(double floorSquare, double unitPrice);
    double calculateHouseUnitPrice(double floorSquare, int completeTypeValue);
    double calculateLandUnitPrice(double landSquare, double landPrice);
    double calculateLandPrice(double floorSquare, double salePrice);

    bool checkValidJsonValue(QJsonValue newVal);
    QJsonObject removeUnusedValues(QJsonObject jsonInputObject);
    bool verifyBDSTypeA(QJsonObject JSONData);
    bool verifyBDSTypeB(QJsonObject JSONData);
    void calculateBDSRankingValue();
signals:
    void appStatusUpdated(QString newStatus);
    void serverError(QString errorMessage);
    void currentBDSDataChanged();
    void notificationListChanged();
    void submittedBDSListChanged();
    void districtListChanged();
    void provinceListChanged();
    void wardListChanged();
    void userChanged();
    void realEstateTypesListChanged();
    void landPositionListChanged();
    void landShapesListChanged();
    void landDirectionsListChanged();
    void houseQualitiesListChanged();
    void landUsingStatusesChanged();
    void landPlanningListChanged();
    void furnituresInfoListChanged();
    void sourcesInfoListChanged();
    void juridicalsListChanged();
    void completeTypesListChanged();
    void stairsInfoListChanged();
    void imageTypesListChanged();
    void priceTypeListChanged();
    void ageListChanged();
    void sexListChanged();
public slots:
    void updateLocationList();
};

#endif // APPMANAGER_H
