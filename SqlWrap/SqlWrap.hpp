#ifndef SQLWRAP_HPP_
	#define SQLWRAP_HPP_

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <vector>
#include <map>

#include <mysql.h>

#include "DatabaseInfos.hpp"

class SqlWrap {
	public:
		SqlWrap(std::shared_ptr<DatabaseInfos> &dbInfos);
		~SqlWrap();
		bool SqlConnexionToDatabase(const std::string &dbName);
		bool SqlQuery(const std::string &myQuery);
		bool fetchResult();
		void getColNameFromLastResult();
		std::vector<std::map<std::string,std::string> > getTabFetchResults() const { return this->_tabFetchResults; };
		void clearResults();
	private:
		std::shared_ptr<DatabaseInfos> _dbInfos;
		std::vector<std::string> _colNames;
		std::vector<std::map<std::string,std::string> > _tabFetchResults;

		MYSQL _mysql;
		MYSQL_RES *_result;
		MYSQL_ROW _row;

		int _nbFields;
		unsigned long *_colLen;
};

void displayMap(std::vector<std::map<std::string,std::string> > result);

#endif /* !SQLWRAP_HPP_ */
