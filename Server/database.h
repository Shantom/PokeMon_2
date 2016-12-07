#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <pokemon.h>
#include <pmagility.h>
#include <pmdefense.h>
#include <pmshield.h>
#include <pmstrength.h>

class Database
{
public:
    Database();

    QSqlDatabase db;

    bool login(QString username,QString password);

    bool signup(QString username,QString password);

    QStringList allUsers();

    double getWinRate(QString name);

    QList<PokeMon *> pmsOfUser(QString username);

    void addPokeMon(QString owner, PokeMon * pm);

    void updateWinRate(QString name, bool result);

    void deletePokeMon(int id);

    PokeMon *pmAt(int id);

    void updatePM(int id, PokeMon *pm);
};


#endif // DATABASE_H
