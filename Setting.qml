import QtQuick 2.0

Item {
    function initPoint(){
        pointRunning_TinhThanh = 0
        pointRunning_QuanHuyen = 0
        pointRunning_PhuongXa = 0
        pointRunning_LoaiBDS = 0
        pointRunning_DiaChiNha = 0
        pointRunning_TenDuong = 0
        pointRunning_ViTri = 0
        pointRunning_ChieuRongDuong = 0
        pointRunning_DuAn = 0

        pointRunning_ChieuNgang = 0
        pointRunning_ChieuDai = 0
        pointRunning_DienTichCongNhan = 0
        pointRunning_DienTichThucTe = 0
        pointRunning_DienTichLoGioi = 0
        pointRunning_HinhDang = 0
        pointRunning_QuyHoachLoaiDat = 0
        pointRunning_DienTichDatNongNghiep = 0
        pointRunning_Huong = 0
        pointRunning_ConstructionSquare = 0
        pointRunning_FloorSquare = 0
        pointRunning_Floors = 0
        pointRunning_ConstructionHeight = 0
        pointRunning_SoPhongNgu = 0
        pointRunning_SoWC = 0
        pointRunning_VatLieuHoanThien = 0
        pointRunning_TienIchNha = 0
        pointRunning_UsingStatus = 0
        pointRunning_TinhTrangChatLuong = 0
        pointRunning_GiaBan = 0
        pointRunning_DonViGia = 0
        pointRunning_DiscussedPrice = 0
        pointRunning_LoaiGiayTo = 0
        pointRunning_CompleteTypes = 0
        pointRunning_TinhTrangPhapLy = 0
        pointRunning_OwnerName = 0
        pointRunning_OwnerAge = 0
        pointRunning_OwnerGender = 0
        pointRunning_OwnerPhone = 0
        pointRunning_OwnerEmail = 0
        pointRunning_OwnerAddress = 0
        pointRunning_ImageMatTien = 0
        pointRunning_ImageLeft = 0
        pointRunning_ImageRight = 0
        pointRunning_ImageOpposite = 0
        pointRunning_ImagePhongKhach = 0
        pointRunning_ImagePhongBep = 0
        pointRunning_ImagePhongNgu = 0
        pointRunning_ImagePhongTam = 0
        pointRunning_ImageSanThuong = 0
        pointRunning_ImageNhaXe = 0
        pointRunning_TienIchTrongNha = 0
        pointRunning_VideoNha = 0
        pointRunning_Image360Degree = 0
        pointRunning_Position = 0
        pointRunning_ImageGiayToNha = 0
        pointRunning_ImageQuyHoachLoGioi = 0
        pointRunning_ImageQuyHoachSuDungDat = 0
        pointRunning_ContactType = 0
        pointRunning_ContactName = 0
        pointRunning_ContactAge = 0
        pointRunning_ContactGender = 0
        pointRunning_ContactPhone = 0
        pointRunning_ContactEmail = 0
        pointRunning_ContactAddress = 0
        pointRunning_ContactCompany = 0
    }
    function calculateRunningPoint(){
        totalRunningPoint =
        pointRunning_TinhThanh +
        pointRunning_QuanHuyen +
        pointRunning_PhuongXa +
        pointRunning_LoaiBDS +
        pointRunning_DiaChiNha +
        pointRunning_TenDuong +
        pointRunning_ViTri +
        pointRunning_ChieuRongDuong +
        pointRunning_DuAn +
        pointRunning_ChieuNgang +
        pointRunning_ChieuDai +
        pointRunning_DienTichCongNhan +
        pointRunning_DienTichThucTe +
        pointRunning_DienTichLoGioi +
        pointRunning_HinhDang +
        pointRunning_QuyHoachLoaiDat +
        pointRunning_DienTichDatNongNghiep +
        pointRunning_Huong +
        pointRunning_ConstructionSquare +
        pointRunning_FloorSquare +
        pointRunning_Floors +
        pointRunning_ConstructionHeight +
        pointRunning_SoPhongNgu +
        pointRunning_SoWC +
        pointRunning_VatLieuHoanThien +
        pointRunning_TienIchNha +
        pointRunning_UsingStatus +
        pointRunning_TinhTrangChatLuong +
        pointRunning_GiaBan +
        pointRunning_DonViGia +
        pointRunning_DiscussedPrice +
        pointRunning_LoaiGiayTo +
        pointRunning_CompleteTypes +
        pointRunning_TinhTrangPhapLy +
        pointRunning_OwnerName +
        pointRunning_OwnerAge +
        pointRunning_OwnerGender +
        pointRunning_OwnerPhone +
        pointRunning_OwnerEmail +
        pointRunning_OwnerAddress +
        pointRunning_ImageMatTien +
        pointRunning_ImageLeft +
        pointRunning_ImageRight +
        pointRunning_ImageOpposite +
        pointRunning_ImagePhongKhach +
        pointRunning_ImagePhongBep +
        pointRunning_ImagePhongNgu +
        pointRunning_ImagePhongTam +
        pointRunning_ImageSanThuong +
        pointRunning_ImageNhaXe +
        pointRunning_TienIchTrongNha +
        pointRunning_VideoNha +
        pointRunning_Image360Degree +
        pointRunning_Position +
        pointRunning_ImageGiayToNha +
        pointRunning_ImageQuyHoachLoGioi +
        pointRunning_ImageQuyHoachSuDungDat +
        pointRunning_ContactType +
        pointRunning_ContactName +
        pointRunning_ContactAge +
        pointRunning_ContactGender +
        pointRunning_ContactPhone +
        pointRunning_ContactEmail +
        pointRunning_ContactAddress +
        pointRunning_ContactCompany
    }

    property int point_TinhThanh : 0
    property int point_QuanHuyen : 0
    property int point_PhuongXa : 1
    property int point_LoaiBDS : 1
    property int point_DiaChiNha : 10
    property int point_TenDuong : 1
    property int point_ViTri : 1
    property int point_ChieuRongDuong : 5
    property int point_DuAn : 1

    property int point_ChieuNgang : 2
    property int point_ChieuDai : 2
    property int point_DienTichCongNhan : 2
    property int point_DienTichThucTe : 2
    property int point_DienTichLoGioi : 3
    property int point_HinhDang : 1
    property int point_QuyHoachLoaiDat : 3
    property int point_DienTichDatNongNghiep : 2
    property int point_Huong : 1
    property int point_ConstructionSquare : 3
    property int point_FloorSquare : 1
    property int point_Floors : 1
    property int point_ConstructionHeight : 2
    property int point_SoPhongNgu : 1
    property int point_SoWC : 1
    property int point_VatLieuHoanThien : 1
    property int point_TienIchNha : 2
    property int point_UsingStatus : 2
    property int point_TinhTrangChatLuong : 2
    property int point_GiaBan : 3
    property int point_DonViGia : 1
    property int point_DiscussedPrice : 5
    property int point_LoaiGiayTo : 2
    property int point_CompleteTypes : 2
    property int point_TinhTrangPhapLy : 2
    property int point_OwnerName : 2
    property int point_OwnerAge : 1
    property int point_OwnerGender : 1
    property int point_OwnerPhone : 5
    property int point_OwnerEmail : 5
    property int point_OwnerAddress : 2
    property int point_ImageMatTien : 3
    property int point_ImageLeft : 1
    property int point_ImageRight : 1
    property int point_ImageOpposite : 1
    property int point_ImagePhongKhach : 2
    property int point_ImagePhongBep : 2
    property int point_ImagePhongNgu : 2
    property int point_ImagePhongTam : 2
    property int point_ImageSanThuong : 2
    property int point_ImageNhaXe : 2
    property int point_TienIchTrongNha : 2
    property int point_VideoNha : 10
    property int point_Image360Degree : 10
    property int point_Position : 5
    property int point_ImageGiayToNha : 10
    property int point_ImageQuyHoachLoGioi : 10
    property int point_ImageQuyHoachSuDungDat : 10
    property int point_ContactType : 1
    property int point_ContactName : 2
    property int point_ContactAge : 1
    property int point_ContactGender : 1
    property int point_ContactPhone : 5
    property int point_ContactEmail : 5
    property int point_ContactAddress : 2
    property int point_ContactCompany : 1

    property string imageType_nha: "nha"
    property string imageType_mattien : "mattien";
    property string imageType_viewtraiphai : "viewtraiphai";
    property string imageType_phongkhach : "phongkhach";
    property string imageType_phongbep : "mattien";
    property string imageType_phongngu : "mattien";
    property string imageType_phongtam : "mattien";
    property string imageType_santhuong : "santhuong";
    property string imageType_nhaxe : "nhaxe";
    property string imageType_giaytonha : "Sovereignty";
    property string imageType_quyhoachlogioi : "LandPlaning";
    property string imageType_quyhoachsudungdat : "quyhoachsudungdat";
    property string imageType_vitribando : "Map";

    property int totalRunningPoint: 0
    property int pointRunning_TinhThanh : 0
    property int pointRunning_QuanHuyen : 0
    property int pointRunning_PhuongXa : 0
    property int pointRunning_LoaiBDS : 0
    property int pointRunning_DiaChiNha : 0
    property int pointRunning_TenDuong : 0
    property int pointRunning_ViTri : 0
    property int pointRunning_ChieuRongDuong : 0
    property int pointRunning_DuAn : 0

    property int pointRunning_ChieuNgang : 0
    property int pointRunning_ChieuDai : 0
    property int pointRunning_DienTichCongNhan : 0
    property int pointRunning_DienTichThucTe : 0
    property int pointRunning_DienTichLoGioi : 0
    property int pointRunning_HinhDang : 0
    property int pointRunning_QuyHoachLoaiDat : 0
    property int pointRunning_DienTichDatNongNghiep : 0
    property int pointRunning_Huong : 0
    property int pointRunning_ConstructionSquare : 0
    property int pointRunning_FloorSquare : 0
    property int pointRunning_Floors : 0
    property int pointRunning_ConstructionHeight : 0
    property int pointRunning_SoPhongNgu : 0
    property int pointRunning_SoWC : 0
    property int pointRunning_VatLieuHoanThien : 0
    property int pointRunning_TienIchNha : 0
    property int pointRunning_UsingStatus : 0
    property int pointRunning_TinhTrangChatLuong : 0
    property int pointRunning_GiaBan : 0
    property int pointRunning_DonViGia : 0
    property int pointRunning_DiscussedPrice : 0
    property int pointRunning_LoaiGiayTo : 0
    property int pointRunning_CompleteTypes: 0
    property int pointRunning_TinhTrangPhapLy : 0
    property int pointRunning_OwnerName : 0
    property int pointRunning_OwnerAge : 0
    property int pointRunning_OwnerGender : 0
    property int pointRunning_OwnerPhone : 0
    property int pointRunning_OwnerEmail : 0
    property int pointRunning_OwnerAddress : 0
    property int pointRunning_ImageMatTien : 0
    property int pointRunning_ImageLeft : 0
    property int pointRunning_ImageRight : 0
    property int pointRunning_ImageOpposite : 0
    property int pointRunning_ImagePhongKhach : 0
    property int pointRunning_ImagePhongBep : 0
    property int pointRunning_ImagePhongNgu : 0
    property int pointRunning_ImagePhongTam : 0
    property int pointRunning_ImageSanThuong : 0
    property int pointRunning_ImageNhaXe : 0
    property int pointRunning_TienIchTrongNha : 0
    property int pointRunning_VideoNha : 0
    property int pointRunning_Image360Degree : 0
    property int pointRunning_Position : 0
    property int pointRunning_ImageGiayToNha : 0
    property int pointRunning_ImageQuyHoachLoGioi : 0
    property int pointRunning_ImageQuyHoachSuDungDat : 0
    property int pointRunning_ContactType : 0
    property int pointRunning_ContactName : 0
    property int pointRunning_ContactAge : 0
    property int pointRunning_ContactGender : 0
    property int pointRunning_ContactPhone : 0
    property int pointRunning_ContactEmail : 0
    property int pointRunning_ContactAddress : 0
    property int pointRunning_ContactCompany : 0
}
