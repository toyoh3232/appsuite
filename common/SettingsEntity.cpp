
#include "SettingsEntity.h"

QDataStream& operator<< (QDataStream& stream, RequestType type)
{
    return stream << static_cast<qint16>(type);
}

QDataStream& operator>> (QDataStream& stream, RequestType& type)
{
    qint16 v;
    stream >> v;
    type = static_cast<RequestType>(v);
    return stream;
}
