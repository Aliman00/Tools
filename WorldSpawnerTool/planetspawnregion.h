#ifndef PLANETSPAWNREGION_H
#define PLANETSPAWNREGION_H

#include <QVector>
#include <QString>
#include "region.h"
#include "spawn.h"

class PlanetSpawnRegion : public Region {
    QString regionName;
    int tier, constant;

    QVector<QString> spawns;
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant& value);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    //void wheelEvent(QGraphicsSceneWheelEvent* event);
public:
    PlanetSpawnRegion(qreal radius);
    PlanetSpawnRegion(qreal width, qreal height);

    QString toLua();

    void setWorldX(float v);
    void setWorldY(float v);

    void setRadius(float v);
    void setDimensions(float width, float height);

    void setTier(int v);
    void setConstant(int v);

    inline QVector<QString>* getSpawns() {
        return &spawns;
    }

    inline QString& getRegionName() {
        return regionName;
    }

    inline int getTier() {
        return tier;
    }

    inline int getConstant() {
        return constant;
    }

    inline void setRegionName(const QString& name) {
        regionName = name;
    }

    inline void addSpawn(const QString& sp) {
        spawns.append(sp);
    }

    inline void removeSpawn(const QString& name) {
        //spawns.remove();
        for (int i = 0; i < spawns.size(); ++i) {
            if (spawns.at(i) == name) {
                spawns.remove(i);

                return;
            }
        }
    }


};

#endif // PLANETSPAWNREGION_H
