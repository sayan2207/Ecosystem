#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include <filesystem>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <unordered_map>
#include <vector>

#include <animal.hpp>

struct DatabaseManager
{
    /***************
     *  Attributes *
    ****************/

    sqlite3 *db;
    std::filesystem::path db_path;

    /******************************
     *  Constructor / Destructor  *
    *******************************/

    DatabaseManager(const std::filesystem::path &path = "../../data/ecosystem_master.db");
    ~DatabaseManager();

    /******************************
     *  Standard DBMS operations  *
    *******************************/

    void deleteRows(const std::vector<std::string> &);
    void insertRows(const std::vector<std::vector<stat_type>>&);
    std::vector<std::vector<stat_type>> readRows(const std::string&, const std::vector<std::string>&);
    void updateRows(const std::vector<std::vector<stat_type>>&);

    /******************************
     *  Miscellaneous operations  *
    *******************************/

    std::unordered_map<std::string, std::vector<std::vector<stat_type>>> groupByKind();
    void clearDatabase();
};

#endif // DATABASEMANAGER_HPP