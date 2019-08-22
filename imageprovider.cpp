#include "imageprovider.h"

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QImage image = QImage(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/" + id);
    size->setWidth(image.width());
    size->setHeight(image.height());
    return image;
}
