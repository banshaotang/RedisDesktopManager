#pragma once
#include "exception.h"
#include "modules/value-editor/abstractkeyfactory.h"

class KeyFactory : public QObject, public ValueEditor::AbstractKeyFactory
{
    Q_OBJECT
    ADD_EXCEPTION
public:
    KeyFactory();

    void loadKey(QSharedPointer<RedisClient::Connection> connection,
                 QString keyFullPath, int dbIndex,
                 std::function<void(QSharedPointer<ValueEditor::Model>)> callback) override;

    void addKey(QSharedPointer<RedisClient::Connection> connection,
                QString keyFullPath, int dbIndex, QString type,
                const QVariantMap &row) override;

private:
    QSharedPointer<ValueEditor::Model> createModel(QString type, QSharedPointer<RedisClient::Connection> connection,
                                                   QString keyFullPath, int dbIndex, int ttl);
};


